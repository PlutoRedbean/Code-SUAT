#include "Tank.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "EnemyTank.h"
#include "LaserTank.h"
#include "Laser.h"
using namespace std;

LaserTank::LaserTank(Game* g) {
    game = g;
    dx = 0;
    dy = 0;
    updateCount = 0;
    direction = UP;
    col = (rand() % (78 - 3 + 1)) + 3;
    row = (rand() % (30 - 1 + 1)) + 1;
    type = LASER;
    health = 200;
    updateCount = 0;
}

void LaserTank::update(int key) {
    if (health <= 0) {return;}
    if (col > MAXCOL) {col = MAXCOL;}
    if (col < 1) {col = 1;}
    if (row > MAXROW) {row = MAXROW;}
    if (row < 1) {row = 1;}
    game->addColor(LASERCOLOR);
    game->paintat(row, col - 2, '{');
    game->paintat(row, col - 1, '=');
    game->paintat(row, col, 'L');
    game->paintat(row, col + 1, '=');
    game->paintat(row, col + 2, '}');
    game->stopColor(LASERCOLOR);
    switch (direction) {
        case LEFT:
            if (type == NORMAL) {game->paintat(row, col - 2, '-');}
            else {game->paintat(row, col - 3, '-');}
            break;
        case RIGHT:
            if (type == NORMAL) {game->paintat(row, col + 2, '-');}
            else {game->paintat(row, col + 3, '-');}
            break;
        case DOWN:
            game->paintat(row + 1, col, '\'');
            break;
        case UP:
            game->paintat(row - 1, col, '\'');
            break;
    }
}

void LaserTank::reduceHealth() {
    health -= 25;
}

bool LaserTank::isHit(int r, int c, int range) {
    if (row == r) {
        if (col <= c + range && col >= c - range) return true;
    }
    return false;
}

void LaserTank::move(int r, int c) {
    if (movable()) {
        if (rand() % 2 == 1) {
            if (row < r) {dy = 1;direction = DOWN;}
            else if (row > r) {dy = -1;direction = UP;}
        } else {
            if (col < c) {dx = 1;direction = RIGHT;}
            else if (col > c) {dx = -1;direction = LEFT;}
        }
    } else {
        dx = 0;
        dy = 0;
    }
    if (shootable(r, c)) {
        status = SHOOT;
        if (direction == LEFT || direction == RIGHT) {
            for (int i = 3; true; i++) {
                if (col + i > MAXCOL || game->playground[col + i - 1][row - 1]) break;
                game->addRemovableItem(new Laser(game, row, col + i, 0, 0, PARAL));
                // game->addColor(LASERCOLOR);
                // game->paintat(row, col + i, '-');
                // game->stopColor(LASERCOLOR);
            }
            for (int i = 3; true; i++) {
                if (col - i <= 0 || game->playground[col - i - 1][row - 1]) break;
                game->addRemovableItem(new Laser(game, row, col - i, 0, 0, PARAL));
                // game->addColor(LASERCOLOR);
                // game->paintat(row, col - i, '-');
                // game->stopColor(LASERCOLOR);
            }
        } else if (direction == UP || direction == DOWN) {
            for (int i = 1; true; i++) {
                if (row + i > MAXROW || game->playground[col - 1][row + i - 1]) break;
                game->addRemovableItem(new Laser(game, row + i, col, 0, 0, VERTI));
                // game->addColor(LASERCOLOR);
                // game->paintat(row + i, col, '|');
                // game->stopColor(LASERCOLOR);
            }
            for (int i = 1; true; i++) {
                if (row - i <= 0 || game->playground[col - 1][row - i - 1]) break;
                game->addRemovableItem(new Laser(game, row - i, col, 0, 0, VERTI));
                // game->addColor(LASERCOLOR);
                // game->paintat(row - i, col, '|');
                // game->stopColor(LASERCOLOR);
            }
        }
    } else status = NOSHOOT;
    hitObstacle();
    col += dx;
    row += dy;
}

bool LaserTank::movable() {
    updateCount++;
    if (updateCount > 10) {
        updateCount = 0;
        return true;
    }
    return false;
}

bool LaserTank::shootable(int r, int c) {
    shoot_count++;
    if (shoot_count > 10) {
        shoot_count = 0;
        if (((row == r && direction == LEFT && col > c) ||
             (row == r && direction == RIGHT && col < c) ||
             (col == c && direction == UP && row > r) ||
             (col == c && direction == DOWN && row < r))
             && rand() % 100 < 10) {
                return true;
             }
    }
    return false;
}

void LaserTank::hitObstacle() {
    if (dx == 1 && direction == RIGHT && game->playground[col + 2][row - 1] == 1) {
        dx = 0;
    }
    if (dx == -1 && direction == LEFT && game->playground[col - 4][row - 1] == 1) {
        dx = 0;
    }
    if (dy == 1 && direction == DOWN &&
        (game->playground[col + 2][row] == 1 ||
            game->playground[col + 1][row] == 1 ||
            game->playground[col - 1][row] == 1 ||
            game->playground[col - 2][row] == 1 ||
            game->playground[col - 3][row] == 1 ||
            game->playground[col - 4][row] == 1 ||
            game->playground[col][row] == 1)) {
        dy = 0;
    }
    if (dy == -1 && direction == UP &&
        (game->playground[col + 2][row - 2] == 1 ||
            game->playground[col + 1][row - 2] == 1 ||
            game->playground[col - 1][row - 2] == 1 ||
            game->playground[col - 2][row - 2] == 1 ||
            game->playground[col - 3][row - 2] == 1 ||
            game->playground[col - 4][row - 2] == 1 ||
            game->playground[col][row - 2] == 1)) {
        dy = 0;
    }
}
