#include "Player.h"
#include "Game.h"
#include <iostream>
using namespace std;
void Player::update (int key){
    int shoot = 0;
    switch (key)
    {
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
    if (shoot == 1) {
        game->addBullet(row, col);
    }
    col += direction;
    if (col > 66) {
        direction = 0;
        col = 66;
    }
    if (col < 4) {
        direction = 0;
        col = 4;
    }
    game->paintat(row, col, 'M');
} 