#ifndef _LASER_H_
#define _LASER_H_
#include "RemovableItem.h"
#include "Game.h"
#include "Item.h"

#define PARAL 0
#define VERTI 1

class Laser : public RemovableItem {
    int exist = 0;
public:
    int direction;
    Laser (Game* g, size_t r, size_t c, int dx1, int dy1, int type) : RemovableItem(g, r, c, dx1, dy1) {
        direction = type;
    }
    void update(int);
    bool out();
};
#endif
