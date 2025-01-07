#ifndef _REMOVEABLEITEM_H_
#define _REMOVEABLEITEM_H_
#include "Game.h"
#include "Item.h"

class RemovableItem : public Item {
public:
    bool hit;
    RemovableItem (Game* g, size_t r, size_t c, int dx1, int dy1) : Item(g, r, c, dx1, dy1), hit(false) {}
    void update(int);
    bool out();
};
#endif
