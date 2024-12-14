#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include "Gui.h"

using namespace std;
class Player;
class Bullet;

class Game {
    Gui gui;
    Player* pl;
    list <Bullet*> bullets;
public:
    Game();
    ~Game(){gui.end();}
    void addBullet(size_t r, size_t c);
    void update();
    void paintat(size_t ro, size_t cl, char c) {
        gui.paintat (ro, cl, c);
    }
};
#endif
