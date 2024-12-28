#include "Tank.h"
#include "Game.h"
#include <iostream>
using namespace std;

void Tank::update(int hit)
{
    col += direction;
    if (col + 1 >= 5 && col + 1 <= 65) game->paintat(row, col + 1, 'D');
    if (col >= 5 && col <= 65) game->paintat(row, col, 'M');
    if (col - 1 >= 5 && col - 1 <= 65) game->paintat(row, col - 1, 'C');
}

Tank::~Tank()
{
    
}

bool Tank::out()
{
    if (col + 1 >= 5 && col - 1 <= 65) return false;
    else return true;
}
