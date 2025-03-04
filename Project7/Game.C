#include "Game.h"
#include "Tank.h"
#include "Player.h"
#include "Bullet.h"
#include "Bomb.h"
#include <cstdlib>
#include <ctime>
//row, col = 行, 列
Game::Game()
{
    srand(time(0));
    gui.init();
    pl = new Player(this);
    items.push_front(pl);
    tk = nullptr;
    bl = nullptr;
    bb = nullptr;
    isBomb = false;
    score = 0;
    numBullet = 10;
    maxBullet = 10;
    bullet_refresh = 0;
    display_time = 0;
    state = 'R';
}

void Game::addBullet(size_t r, size_t c)
{
    if (numBullet > 0) {
        bl = new Bullet(this, r, c);
        items.push_back(bl);
        maxBullet--;
        numBullet--;
    }
}

void Game::update()
{
    gui.clear();
    // gui.printMsg(1, 67, "MBullet: ", maxBullet);
    gui.printMsg(2, 68, "Bullet: ", numBullet);
    gui.printMsg(3, 69, "SCORE: ", score);
    int c = gui.get();
    list<Item*>::iterator bi = items.begin();
    while (bi != items.end() ) {
        if (*bi == pl) (*bi)->update(c);
        else if (dynamic_cast<Bullet*>(*bi) && tk != nullptr) (*bi)->update(tk->col);
        else if (*bi == bb && pl != nullptr) (*bi)->update(pl->col);
        else if (pl == nullptr) break; 
        else (*bi)->update(c);
        if ((*bi)->out()) {
            if (*bi == tk) tk = nullptr;
            if (dynamic_cast<Bomb*>(*bi)) {
                bb = nullptr;
                isBomb = false;
            }
            if (dynamic_cast<Bullet*>(*bi) && maxBullet < 10) {
                maxBullet++;
            }
            delete *bi;
            bi = items.erase(bi);
        } else bi++;
        int display_percentage = rand() % 50;    //2% 1/50
        int direction_percentage = rand() % 2;    //50% 1/2
        int bomb_percentage = rand() % 30;
        if (tk == nullptr && display_percentage == 1) {
            if (direction_percentage) {
                tk = new Tank(this, 2, 4, 1);  //1, 4 | 1, 66
            } else {
                tk = new Tank(this, 2, 66, -1);
            }
            items.push_front(tk);
        } else if (tk != nullptr) {
            if (bb == nullptr && bomb_percentage == 1 && !isBomb) {
                isBomb = true;
                bb = new Bomb(this, tk->row + 1, tk->col);
                items.push_front(bb);
            }
        }
        if (numBullet < maxBullet && bullet_refresh >= 40) numBullet++;
        if (bullet_refresh < 40) bullet_refresh++;
        else bullet_refresh = 0;
    }
    if (pl != nullptr && bb != nullptr && bb->col < pl->col) bb->col++;
    else if (pl != nullptr && bb != nullptr && bb->col > pl->col) bb->col--;
    if (pl == nullptr && display_time < 90) {
        gui.printMsg(8, 25, "GAME OVER, SCORE: ", score);
        display_time++;
        gui.paintat(9, 30, 'q');
        gui.paintat(9, 32, 'f');
        gui.paintat(9, 33, 'o');
        gui.paintat(9, 34, 'r');
        gui.paintat(9, 36, 'q');
        gui.paintat(9, 37, 'u');
        gui.paintat(9, 38, 'i');
        gui.paintat(9, 39, 't');
        gui.paintat(10, 28, 'r');
        gui.paintat(10, 29, 'e');
        gui.paintat(10, 30, 's');
        gui.paintat(10, 31, 'e');
        gui.paintat(10, 32, 't');
        gui.paintat(10, 34, 'a');
        gui.paintat(10, 35, 'f');
        gui.paintat(10, 36, 't');
        gui.paintat(10, 37, 'e');
        gui.paintat(10, 38, 'r');
        gui.paintat(10, 40, '3');
        gui.paintat(10, 41, 's');
    } else if (pl == nullptr && display_time >= 90) {
        reboot();
    }
    if (pl == nullptr && c == 'q') {
        state = 'E';
    }
}

void Game::hitTank(Item* bullet, size_t tank_c)
{
    score += 100;
    list<Item*>::iterator bi = items.begin();
    while (bi != items.end()) {
        if (dynamic_cast<Tank*>(*bi)) {
            delete *bi;
            bi = items.erase(bi);
            tk = nullptr;
            bullet->row = 0;
            break;
        }
        bi++;
    }
}

void Game::hitPlayer(Item* bomb, size_t player_c)
{
    list<Item*>::iterator bi = items.begin();
    while (bi != items.end()) {
        if (*bi == pl) {
            delete *bi;
            bi = items.erase(bi);
            pl = nullptr;
            bomb->row = 20;
            break;
        }
        bi++;
    }
}

bool Game::end()
{
    return state == 'E';
}

void Game::reboot()
{
    pl = new Player(this);
    items.push_front(pl);
    if (tk != nullptr) tk->col = 70;
    if (bl != nullptr) bl->row = 0;
    if (bb != nullptr) bb->row = 20;
    tk = nullptr;
    bl = nullptr;
    bb = nullptr;
    isBomb = false;
    score = 0;
    numBullet = 10;
    maxBullet = 10;
    bullet_refresh = 0;
    display_time = 0;
}

Game::~Game()
{
    delete pl;
    delete tk;
    delete bl;
    delete bb;
    items.clear(); 
    gui.end();
}
