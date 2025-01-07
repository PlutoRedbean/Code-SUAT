#include "Medpack.h"
#include "Game.h"

void Medpack::update(int c) {
    exist_time++;
    if (row <= 0 || col <= 0 || row > 30 || col > 80) return;
    // if (row < 0) return;
    game->addColor(MEDPACKCOLOR);
    game->paintat(row, col - 1, '<');
    game->paintat(row, col, '+');
    game->paintat(row, col + 1, '>');
    game->stopColor(MEDPACKCOLOR);
    if (game->medPick(row, col, 1)) hit = true;
}

bool Medpack::out() {
    if (row < 1 || col < 1 || row > 30 || col > 80 || hit == true || exist_time > MEDPACKTIME) return true;
    else return false;
}

void Medpack::spwan() {
    
}
