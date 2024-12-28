#ifndef _ITEM_H_
#define _ITEM_H_
#include "Game.h"

class Item
{
public:
    size_t row;
    size_t col;
    Item(size_t r, size_t c);
    virtual void update(int);
    virtual bool out();
    virtual ~Item();
};

#endif
