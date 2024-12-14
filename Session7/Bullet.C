#include "Bullet.h"
#include "Game.h"

void Bullet::update(){
    if (row <= 1) {
        return;
    }
    row--;
    game->paintat(row, col, '^');

    
}
bool Bullet::out() {
    if (row <= 0) {
        return true;
    }else {
        return false;
    }
}