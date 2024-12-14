#ifndef _BULLET_H_
#define _BULLET_H_
#include "Game.h"

class Bullet
{
private:
    size_t row;
    size_t col;
    Game* game;
public:
    Bullet(Game* g, size_t r, size_t c) : row(r), col(c), game(g) {};
    void update();
    bool out();
};

#endif
