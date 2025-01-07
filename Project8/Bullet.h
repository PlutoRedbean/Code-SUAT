#ifndef _BULLET_H_
#define _BULLET_H_
#include "RemovableItem.h"
#include "Game.h"
#include "Item.h"

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3

class Bullet : public RemovableItem {
    int direction;
    int shooter;
public:
    Bullet (Game* g, size_t r, size_t c, int dx1, int dy1, int dir, int type) : RemovableItem(g, r, c, dx1, dy1) {
        direction = dir;
        shooter = type;
    }
    void update(int);
    bool out();
};
#endif
