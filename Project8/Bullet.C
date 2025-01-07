#include "Bullet.h"
#include "Game.h"

void Bullet::update(int c) {
    if (row <= 0 || col <= 0 || row > 30 || col > 80) return;
    // if (row < 0) return;
    if (direction == UP) {
        row--;
        game->paintat(row, col, '\'');
    } else if (direction == DOWN) {
        row++;
        game->paintat(row, col, '\'');
    } else if (direction == LEFT) {
        col--;
        game->paintat(row, col, '-');
    } else if (direction == RIGHT) {
        col++;
        game->paintat(row, col, '-');
    }
    if (game->playground[col - 1][row - 1] == 1) hit = true;
    if (game->checkHit(row, col, 0, shooter)) hit = true;
    if (game->hitPlayer(row, col, 0, shooter)) hit = true;
}

bool Bullet::out() {
    if (row < 1 || col < 1 || row > 30 || col > 80 || hit == true) return true;
    else return false;
}
