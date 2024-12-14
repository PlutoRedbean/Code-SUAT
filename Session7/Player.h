#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Game.h"

class Player {
    size_t row;
    size_t col;
    Game* game;
    int direction;
    public:
    Player (Game * g) : row(18), col(25), game(g), direction(0){}
    void update (int key);
};



#endif