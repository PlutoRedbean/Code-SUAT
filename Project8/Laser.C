#include "Laser.h"
#include "Game.h"

void Laser::update(int c) {
    exist++;
    if (direction == PARAL) {
        game->addColor(LASERCOLOR);
        game->paintat(row, col, '-');
        game->stopColor(LASERCOLOR);
    } else if (direction == VERTI) {
        game->addColor(LASERCOLOR);
        game->paintat(row, col, '|');
        game->stopColor(LASERCOLOR);
    }
    if (exist >= 3) hit = true;
    if (game->checkHit(row, col, 0, 2)) hit = true;
    if (game->hitPlayer(row, col, 0, 3)) hit = true;
}

bool Laser::out() {
    if (hit == true) return true;
    else return false;
}
