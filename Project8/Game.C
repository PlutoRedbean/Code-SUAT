#include "Game.h"
#include "Player.h"
#include "EnemyTank.h"
#include "LaserTank.h"
#include "Laser.h"
#include "Bullet.h"
#include "Mine.h"
#include "Medpack.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

Game::Game(char** argv) {
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 30; j++) {
            playground[i][j] == 0;
        }
    }
    gui.init();

    ifstream Map(argv[1]);
    if (Map.is_open()) {
        pg_read(Map);
    } else {
        pg_spawn();
    }
    map_paint();

    obj_init(this);

    score = 0;
}

void Game::addRemovableItem(RemovableItem* rbi) {
    items.push_back(rbi);
}

void Game::update() {
    gui.clear(); //clear everything on the screen

    /*调试:输出链表的节点数*/
    /*list<Tank*>::iterator bi = tanks.begin();
    int length = 0;
    while (bi != tanks.end() ) {
        length++;
        bi++;
    }
    gui.color_on(1);
    gui.printMsg(6, MAXCOL + 3, "  List: ", length);
    gui.color_off(1);*/

    gui.printMsg(2, MAXCOL + 3, "Bullet: ", pl->reportNumBullet());
    gui.printMsg(3, MAXCOL + 3, "  Tank: ", tank_max_number);
    gui.printMsg(4, MAXCOL + 3, "Health: ", pl->reportHealth());
    gui.printMsg(5, MAXCOL + 3, " Score: ", score);
    gui.print(7, MAXCOL + 3, "R for reset");
    gui.print(8, MAXCOL + 3, "Q for quit");
    gui.print(9, MAXCOL + 3, "ESC for pause");
    
    int c = gui.get();
    switch (state) {
        case RUNNING :
            pl->update(c);
            pl->move(0, 0);
            medRefresh();
            updateRemovableItems(c);
            updateTanks(c);
            map_paint();
            if (pl->dead()) state = DEAD;
            if (c == 27) state = PAUSE;
            if (c == 114 || c == 82) state = RESET;
            if (c == 113 || c == 81) state = END;
        break;
        case DEAD :
            gui.printMsg((MAXROW / 2) - 1, (MAXCOL / 2) - 11, "GAME OVER Score: ", score);
            gui.print((MAXROW / 2) + 1, (MAXCOL / 2) - 15, "Press R for reset, Q for quit");
            if (c == 114 || c == 82) state = RESET;
            if (c == 113 || c == 81) state = END;
            break;
        case PAUSE :
            gui.printMsg((MAXROW / 2) - 1, (MAXCOL / 2) - 11, "GAME PAUSED Score: ", score);
            gui.print((MAXROW / 2) + 1, (MAXCOL / 2) - 15, "Press R for reset, Q for quit");
            if (c == 27) state = RUNNING;
            if (c == 114 || c == 82) state = RESET;
            if (c == 113 ||c == 81) state = END;
            break;
        case RESET :
            delete pl;
            list<Tank*>::iterator tks = tanks.begin();
            while (tks != tanks.end() ) {
                delete *tks;
                tks = tanks.erase(tks);
                // tks++;
            }
            list<RemovableItem*>::iterator itms = items.begin();
            while (itms != items.end() ) {
                delete *itms;
                itms = items.erase(itms);
                // itms++;
            }
            obj_init(this);
            state = RUNNING;
            break;
    }
    gui.redraw(); //draw things
}

void Game::updateTanks(int c) {
    bang();
    list<Tank*>::iterator bi = tanks.begin();
    while (bi != tanks.end() ) {
        (*bi)->update(c);
        (*bi)->move(pl->row, pl->col);
        if ((*bi)->reportHealth() <= 0) {
            score += (*bi)->type == NORMAL ? 10 : 100;
            tank_max_number--;
            tank_number--;
            delete *bi;
            bi = tanks.erase(bi);
        }
        bi++;
    }
    if (tank_number < 4 && tank_max_number >= 4) {
        tank_number++;
        tank = new EnemyTank(this);
        while (playground[tank->col - 1][tank->row - 1] == 1 || playground[tank->col - 2][tank->row - 1] == 1 || playground[tank->col][tank->row - 1] == 1) {
            tank->row = (rand() % (30 - 1 + 1)) + 1;
            tank->col = (rand() % (79 - 2 + 1)) + 2;
        }
        tanks.push_back(tank);
    }
    if (laser != nullptr) {laser->update(c);laser->move(pl->row, pl->col);}
    if (laser != nullptr && laser->reportHealth() <= 0) {
        score += 1000;
        delete laser;
        laser = nullptr;
    }
}

void Game::updateRemovableItems(int c) {
    list<RemovableItem*>::iterator bi = items.begin();
    while (bi != items.end() ) {
        (*bi)->update(c);
        if ((*bi)->out() == true) {
            delete *bi;
            bi = items.erase(bi);
        }
        bi++;
    }
}

void Game::bang() {
    list<Tank*>::iterator bi = tanks.begin();
    while (bi != tanks.end() ) {
        if (pl->col >= (*bi)->col - 1 && pl->col <= (*bi)->col + 1 && pl->row == (*bi)->row && (*bi)->type == NORMAL) {
            pl->setHealth(0);
        } else if (pl->col >= (*bi)->col - 2 && pl->col <= (*bi)->col + 2 && pl->row == (*bi)->row && (*bi)->type == SUPER) {
            pl->setHealth(0);
        }
        bi++;
    }
    if (laser != nullptr && pl->col >= laser->col - 1 && pl->col <= laser->col + 1
        && pl->row == laser->row && laser->type == LASER) {
        pl->setHealth(0);
    }
}

bool Game::hitPlayer(int r, int w, int range, int shooter) {
    if (pl->isHit(r, w, range + 1) && shooter != PLAYER) {
        pl->reduceHealth();
        return true;
    }
    else {return false;}
}

bool Game::mineBlast(int r, int w, int range) {
    if (pl->mineHit(r, w, range)) {
        for (int i = 0; i < 5; i++) pl->reduceHealth();
        return true;
    }
    else {return false;}
}

bool Game::medPick(int r, int w, int range) {
    if (pl->medHit(r, w, range)) {
        pl->heal();
        return true;
    }
    else {return false;}
}

bool Game::checkHit(int r, int w, int range, int shooter) {
    list<Tank*>::iterator bi = tanks.begin();
    while (bi != tanks.end() ) {
        if ( (*bi)->isHit(r, w, (*bi)->type == NORMAL ? range + 1 : range + 2) && shooter == PLAYER ) {
            (*bi)->reduceHealth();
            return true;
        }
        bi++;
    }
    if ( laser != nullptr && laser->isHit(r, w, range + 2) && shooter == PLAYER ) {
        laser->reduceHealth();
        return true;
    }
    return false;
}

void Game::medRefresh() {
    med_refresh_time++;
    if (med_refresh_time > MEDPACKTIME) {
        med_refresh_time = 0;
        for (int i = 0; i < MAXMEDPACK; i++) {
            int row = (rand() % (30 - 1 + 1)) + 1;
            int col = (rand() % (79 - 2 + 1)) + 2;
            while (playground[col - 1][row - 1] == 1 || playground[col - 2][row - 1] == 1 || playground[col][row - 1] == 1) {
                row = (rand() % (30 - 1 + 1)) + 1;
                col = (rand() % (79 - 2 + 1)) + 2;
            }
            addRemovableItem(new Medpack(this, row, col, 0, 0));
        }
    }
}

void Game::addColor(int num) {
    gui.color_on(num);
}

void Game::stopColor(int num) {
    gui.color_off(num);
}

void Game::pg_spawn() {
    int max = 5;
    int min = 2;
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 30; j++) {
            if (rand() % 100 != 3) continue;
            playground[i][j] = 1;
            int extension = (rand() % (max - min + 1)) + min;
            obstacleExpand(i, j, extension);
        }
    }
}

void Game::obstacleExpand(int& i, int& j, int& extension) {
    if (rand() % 2 == 1) {
        for (int k = 1; k <= extension; k++) {
            if (j - k >= 0) playground[i][j - k] = 1;
            if (j + k < 30) playground[i][j + k] = 1;
        }
    } else {
        for (int k = 1; k <= extension; k++) {
            if (i - k >= 0) playground[i - k][j] = 1;
            if (i + k < 80) playground[i + k][j] = 1;
        }
    }
}

void Game::pg_read(ifstream& Map) {
    char** read = new char*[33];
    for (int i = 0; i < 33; i++) {
        if (i != 32) read[i] = new char[82];
        else read[32] = new char[1];
    }
    read[32][0] = '\0';

    string map;
    int row = 0;
    while (!Map.eof()) {
        getline(Map, map);
        if (row >= 32) {
            continue;
        }
        for (int i = 0; i < 82; i++) {
            read[row][i] = map[i];
        }
        row++;
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 80; j++) {
            playground[j][i] = read[i + 1][j + 1] == '%' ? 1 : 0;
        }
    }
}

void Game::map_paint() {
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 30; j++) {
            if (playground[i][j] == 1) gui.paintat(j + 1, i + 1, '%');
        }
    }
}

void Game::obj_init(Game* init) {
    med_refresh_time = 0;
    tank_number = 0;
    tank_max_number = MAXTANK;
    pl = new Player(this);
    while (spawnable(pl->row, pl->col, 1)) {
        pl->row = (rand() % (30 - 1 + 1)) + 1;
        pl->col = (rand() % (79 - 2 + 1)) + 2;
    }
    for (int i = 0; i < MAXCURRENTTANK; i++) {
        tank = new EnemyTank(init);
        while (spawnable(tank->row, tank->col, 1)) {
            tank->row = (rand() % (30 - 1 + 1)) + 1;
            tank->col = (rand() % (78 - 3 + 1)) + 3;
        }
        tanks.push_back(tank);
        tank_number++;
    }
    laser = new LaserTank(init);
    while (spawnable(laser->row, laser->col, 1)) {
        laser->row = (rand() % (30 - 1 + 1)) + 1;
        laser->col = (rand() % (78 - 3 + 1)) + 3;
    }

    for (int i = 0; i < MAXMEDPACK; i++) {
        int row = (rand() % (30 - 1 + 1)) + 1;
        int col = (rand() % (79 - 2 + 1)) + 2;
        while (spawnable(row, col, 1)) {
            row = (rand() % (30 - 1 + 1)) + 1;
            col = (rand() % (79 - 2 + 1)) + 2;
        }
        addRemovableItem(new Medpack(init, (rand() % (30 - 1 + 1)) + 1, (rand() % (79 - 2 + 1)) + 2, 0, 0));
    }
    score = 0;
}

bool Game::spawnable(int r, int c, int range) {
    return playground[c - 1][r - 1] == 1 ||
           playground[c - 2][r - 1] == 1 ||
           playground[c - 3][r - 1] == 1 ||
           playground[c    ][r - 1] == 1 ||
           playground[c + 1][r - 1] == 1;
}
