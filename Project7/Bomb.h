#ifndef _BOMB_H_
#define _BOMB_H_
#include "Item.h"
#include "Game.h"

class Bomb : public Item {
    Game* game;
public:
    Bomb(Game* g, size_t r, size_t c) : Item(r, c), game(g) {}
    // ~Bomb();
    void update(int);
    bool out();
};
#endif
