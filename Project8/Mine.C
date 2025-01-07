#include "Mine.h"
#include "Game.h"

void Mine::update(int c) {
    if (row <= 0 || col <= 0 || row > 30 || col > 80) return;
    // if (row < 0) return;
    game->addColor(MINECOLOR);
    game->paintat(row, col, '@');
    game->stopColor(MINECOLOR);
    if (game->mineBlast(row, col, 1)) hit = true;
}

bool Mine::out() {
    if (row < 1 || col < 1 || row > 30 || col > 80 || hit == true) return true;
    else return false;
}
