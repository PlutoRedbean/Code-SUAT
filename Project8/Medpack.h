#ifndef _MEDPACK_H_
#define _MEDPACK_H_
#include "RemovableItem.h"
#include "Game.h"
#include "Item.h"

class Medpack : public RemovableItem {
    int direction;
    int placer;
    int exist_time = 0;
public:
    Medpack (Game* g, size_t r, size_t c, int dx1, int dy1) : RemovableItem(g, r, c, dx1, dy1) {
        dx = 0;
        dy = 0;
    }
    void update(int);
    bool out();
    void spwan();
};
#endif
