#include "Player.h"
#include "Game.h"
#include "Item.h"
#include "Bullet.h"
#include <iostream>
using namespace std;

Player::Player(Game* g) {   //row 行, col 列
    game = g;
    row = (rand() % (30 - 1 + 1)) + 1;
    col = (rand() % (79 - 2 + 1)) + 2;
    dx = 0;
    dy = 0;
    type = PLAYER;
    // updateCount = 0;
    numBullet = MAXNUMBULLET;
    health = 100;
    direction = DOWN;
}
void Player::update(int key) {
    int shoot = 0;
    if (numBullet < MAXNUMBULLET) updateCount++;
    if (updateCount > MAXCOUNT) {
        numBullet++;
        if (numBullet > MAXNUMBULLET) numBullet = MAXNUMBULLET;
        updateCount = 0;
    }
    switch (key) {
        case KEY_LEFT:
            direction = LEFT;
            dx = -1;
            break;
        case KEY_RIGHT:
            direction = RIGHT;
            dx = 1;
            break;
        case KEY_UP:
            direction = UP;
            dy = -1;
            break;
        case KEY_DOWN:
            direction = DOWN;
            dy = 1;
            break;
        case ' ':
            shoot = 1;
            break;
        default:
            dx = 0;
            dy = 0;
            break;
    }
    if (shoot == 1) {
        if (numBullet > 0) {
            if (direction == UP || direction == DOWN) {
                game->addRemovableItem(new Bullet(game, row, col, dx, dy, direction, type));
            } else {
                game->addRemovableItem(new Bullet(game, row, direction == LEFT ? col - 1 : col + 1, dx, dy, direction, type));
            }
            numBullet--;
        }
    }
    
    game->addColor(PLAYERCOLOR);
    game->paintat(row, col - 1, '(');
    game->paintat(row, col, 'P');
    game->paintat(row, col + 1, ')');
    game->stopColor(PLAYERCOLOR);
    switch (direction) {
        case LEFT:
            game->paintat(row, col - 2, '-');
            break;
        case RIGHT:
            game->paintat(row, col + 2, '-');
            break;
        case DOWN:
            game->paintat(row + 1, col, '\'');
            break;
        case UP:
            game->paintat(row - 1, col, '\'');
            break;
    }
}

bool Player::out() {return false;}

bool Player::isHit(int r, int c, int xr) {
    if (row == r) {
        if (col <= c + xr && col >= c - xr) return true;
    }
    return false;
}

bool Player::mineHit(int r, int c, int xr) {
    if (row <= r + xr && row >= r - xr) {
        if (col <= c + xr + 1 && col >= c - xr - 1) return true;
    }
    return false;
}

bool Player::medHit(int r, int c, int xr) {
    if (row <= r + xr && row >= r - xr) {
        if (col <= c + xr + 1 && col >= c - xr - 1) return true;
    }
    return false;
}

void Player::reduceHealth() {
   health -= 10;
}

void Player::heal() {
   health = 100;
}

void Player::move(int r, int c) {
    hitObstacle();
    col += dx;
    row += dy;
    if (row >= MAXROW) { row = MAXROW;}
    if (row < 1) {row = 1; }
    if (col >= MAXCOL - 1) { col = MAXCOL - 1;}
    if (col < 2) {col = 2; }
}

void Player::hitObstacle() {
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
}

bool Player::dead() {
    return health <= 0;
}
