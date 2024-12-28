#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include "Item.h"
#include "Gui.h"
using namespace std;
class Item;
class Player;
class Bullet;
class Tank;
class Bomb;

class Game {
    Gui gui;
    Player* pl;
    Tank* tk;
    Bullet* bl;
    Bomb* bb;
    list <Item*> items;
    bool isBomb;
    int numBullet;
    int maxBullet;
    int score;
    int bullet_refresh;
    int display_time;
    char state;
public:
    Game() ;
    ~Game();
    void addBullet(size_t r, size_t c);
    void update();
    void hitTank(Item* bullet, size_t tank_c);
    void hitPlayer(Item* bomb, size_t player_c);
    void paintat(size_t ro, size_t cl, char c) {gui.paintat(ro, cl, c);}
    void reboot();
    bool end();
};
#endif
