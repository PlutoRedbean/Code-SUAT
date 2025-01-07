#ifndef _ITEM_H_
#define _ITEM_H_

#define MAXROW 30
#define MAXCOL 80
#include <iostream>
using namespace std;
class Game;
class Item {
public:
    size_t row;
    size_t col;
    Game* game;
    int dx;
    int dy;
    Item();
    Item(Game* g, int r, int w, int dx1, int dx2);
    virtual void update(int);
    virtual bool out();
};
#endif
