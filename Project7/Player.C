#include "Player.h"
#include "Game.h"
#include <iostream>
using namespace std;

void Player::update(int key) {
    int shoot = 0;
    switch (key) {
        case KEY_LEFT:
            direction -= 1;
            break;
        case KEY_RIGHT:
            direction += 1;
            break;
        case ' ':
            shoot = 1;
            break;
        default:
            break;
    }
    if (shoot) game->addBullet(row, col);
    col += direction;
    if (col > 65) {direction = 0; col = 65;}
    if (col < 5) {direction = 0; col = 5;}
    game->paintat(row, col, 'M');
}
