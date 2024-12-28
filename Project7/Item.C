#include "Item.h"
#include "Game.h"
#include <iostream>

Item::Item (size_t r, size_t c)
{
    row = r;
    col = c;
}

void Item::update(int key)
{

}

bool Item::out()
{
    if (row <= 0) return true;
    else return false;
}

Item::~Item()
{
    
}
