#ifndef _PLAYER_H_
#define _PLAYER_H
#include "Item.h"
#include "Game.h"

class Player : public Item {
    Game* game;
    int direction;
public:
    Player (Game* g) : Item(12, 25), game(g), direction(0) {}
    // ~Player();
    void update(int key);
};
#endif
