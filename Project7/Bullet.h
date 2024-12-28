#ifndef _BULLET_H_
#define _BULLET_H_
#include "Item.h"
#include "Game.h"

class Bullet : public Item {
    Game* game;
public:
    Bullet(Game* g, size_t r, size_t c) : Item(r, c), game(g) {}
    // ~Bullet();
    void update(int);
    bool out();
};
#endif
