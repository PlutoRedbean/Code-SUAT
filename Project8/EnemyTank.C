#include "Tank.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "EnemyTank.h"
#include "Bullet.h"
#include "Mine.h"
using namespace std;

// int randomValue = (rand() % (max - min)) + min;//范围[min,max)
//     randomValue = (rand() % (max - min + 1)) + min;//范围[min,max]
//     randomValue = (rand() % (max - min)) + min + 1;//范围(min,max]

EnemyTank::EnemyTank(Game* g) {
    game = g;
    dx = 0;
    dy = 0;
    updateCount = 0;
    direction = UP;
    col = (rand() % (78 - 3 + 1)) + 3;
    row = (rand() % (30 - 1 + 1)) + 1;
    if (rand() % 100 < 30) {
        type = SUPER;
        health = 100;
    }
    else {
        type = NORMAL;
        health = 25;
    }
    updateCount = 0;
}

void EnemyTank::update(int key) {
    if (col > MAXCOL) {col = MAXCOL;}
    if (col < 1) {col = 1;}
    if (row > MAXROW) {row = MAXROW;}
    if (row < 1) {row = 1;}
    if (type == NORMAL) {
        game->addColor(NORMALCOLOR);
        game->paintat(row, col - 1, '[');
        game->paintat(row, col, 'N');
        game->paintat(row, col + 1, ']');
        game->stopColor(NORMALCOLOR);
    } else {
        game->addColor(SUPERCOLOR);
        game->paintat(row, col - 2, '{');
        game->paintat(row, col - 1, '=');
        game->paintat(row, col, 'S');
        game->paintat(row, col + 1, '=');
        game->paintat(row, col + 2, '}');
        game->stopColor(SUPERCOLOR);
    }
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

void EnemyTank::reduceHealth() {
    health -= 25;
}

bool EnemyTank::isHit(int r, int c, int range) {
    // if (row <= r + range && row >= r - range) {
    //     if (col <= c + range && col >= c - range) return true;
    // }
    if (row == r) {
        if (col <= c + range && col >= c - range) return true;
    }
    return false;
}

bool EnemyTank::out() {return false;}

void EnemyTank::move(int r, int c) {
    if (movable()) {
        if (rand() % 100 < 80 && type == SUPER) {
            if (rand() % 2 == 1) {
                if (row < r) {dy = 1;direction = DOWN;}
                else if (row > r) {dy = -1;direction = UP;}
            } else {
                if (col < c) {dx = 1;direction = RIGHT;}
                else if (col > c) {dx = -1;direction = LEFT;}
            }
            // if (dx != 0 && dy != 0 && (rand() % 2 == 1)) {
            //     dx = 0;
            //     direction = (dy == 1) ? direction = DOWN : direction = UP;
            // } else if (dx != 0 && dy != 0 && (rand() % 2 == 0)) {
            //     dy = 0;
            //     direction = (dx == 1) ? direction = RIGHT : direction = LEFT;
            // }
        } else if (rand() % 100 < 40 && type == NORMAL) {
            direction = rand() % 4;
            switch (direction) {
                case LEFT:
                    dx = -1;
                    break;
                case RIGHT:
                    dx = 1;
                    break;
                case DOWN:
                    dy = 1;
                    break;
                case UP:
                    dy = -1;
                    break;
            }
        }
    } else {
        dx = 0;
        dy = 0;
    }
    if (shootable(r, c)) {
        if (direction == UP || direction == DOWN) {
            game->addRemovableItem(new Bullet(game, row, col, dx, dy, direction, type));
        } else {
            if (type == NORMAL) {
                game->addRemovableItem(new Bullet(game, row, direction == LEFT ? col - 1 : col + 1, dx, dy, direction, type));
            } else {
                game->addRemovableItem(new Bullet(game, row, direction == LEFT ? col - 2 : col + 2, dx, dy, direction, type));
            }
        }
    }
    if (mine_place(r, c) && type == SUPER) {
        game->addRemovableItem(new Mine(game, row, col, 0, 0, direction, type));
    }
    hitObstacle();
    col += dx;
    row += dy;
}

bool EnemyTank::movable() {
    updateCount++;
    if (updateCount > 10) {
        updateCount = 0;
        return true;
    }
    return false;
}

bool EnemyTank::shootable(int r, int c) {
    shoot_count++;
    if (shoot_count > 5) {
        shoot_count = 0;
        if (((row == r && direction == LEFT && col > c) ||
             (row == r && direction == RIGHT && col < c) ||
             (col == c && direction == UP && row > r) ||
             (col == c && direction == DOWN && row < r))
             && rand() % 100 < 40) {
                return true;
             }
    }
    return false;
}

bool EnemyTank::mine_place(int r, int c) {
    place_count++;
    if (place_count > 100) {
        place_count = 0;
        if (rand() % 100 > 40 && mine_placed < MAXMINE) {
            return true;
        }
    }
    return false;
}

void EnemyTank::hitObstacle() {
    switch (type) {
        case NORMAL :
        if (dx == 1 && direction == RIGHT && game->playground[col + 1][row - 1] == 1) {
            dx = 0;
        }
        if (dx == -1 && direction == LEFT && game->playground[col - 3][row - 1] == 1) {
            dx = 0;
        }
        if (dy == 1 && direction == DOWN &&
            (game->playground[col - 1][row] == 1 || game->playground[col - 2][row] == 1 || game->playground[col][row] == 1)) {
            dy = 0;
        }
        if (dy == -1 && direction == UP &&
            (game->playground[col - 1][row - 2] == 1 || game->playground[col - 2][row - 2] == 1 || game->playground[col][row - 2] == 1)) {
            dy = 0;
        }
        case SUPER :
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
}

