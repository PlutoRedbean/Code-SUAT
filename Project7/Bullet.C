#include "Bullet.h"
#include "Game.h"
#include <iostream>

void Bullet::update(int tank_c) {
    row--;
    if ((col == tank_c + 1 || col == tank_c || col == tank_c - 1) && row == 2) {
        game->hitTank(this, tank_c);
    }
    if (row > 0) game->paintat(row, col, '^');
}

bool Bullet::out() {
    if (row <= 0) return true;
    else return false;
}
