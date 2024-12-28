#include "Bomb.h"
#include "Game.h"

void Bomb::update(int player_c) {
    row++;
    if (col == player_c && row == 12) {
        game->hitPlayer(this, player_c);
    }
    if (row <= 19) game->paintat(row, col, 'O');
}

bool Bomb::out() {
    if (row > 19) return true;
    else return false;
}
