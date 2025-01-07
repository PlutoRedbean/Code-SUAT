#include "Item.h"

Item::Item() : row (10), col (0) {}
Item::Item(Game* g, int r, int c, int dx1, int dy1) 
    : game(g), row (r), col (c), dx (dx1), dy (dy1) {}
void Item::update(int) {}
bool Item::out(){return false;}

