#ifndef _MINE_H_
#define _MINE_H_
#include "RemovableItem.h"
#include "Game.h"
#include "Item.h"

class Mine : public RemovableItem {
    int direction;
    int placer;
public:
    Mine (Game* g, size_t r, size_t c, int dx1, int dy1, int dir, int type) : RemovableItem(g, r, c, dx1, dy1) {
        dx = 0;
        dy = 0;
        direction = dir;
        placer = type;
    }
    void update(int);
    bool out();
};
#endif
