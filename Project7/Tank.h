#ifndef _TANK_H_
#define _TANK_H_
#include "Item.h"
#include "Game.h"

// class Game;

class Tank : public Item {
    Game* game;
    int direction;
public:
    Tank(Game* g, size_t r, size_t c, int dir) : Item(r, c), game(g), direction(dir) {}
    ~Tank();
    void update(int);
    bool out();
};
#endif
