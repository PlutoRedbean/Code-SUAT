#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Game.h"
#include "Item.h"
#include "Tank.h"

#define MAXCOUNT 40
#define MAXNUMBULLET 20

class Player:public Tank {
    int numBullet;
public:
    Player (Game* g);
    int reportNumBullet() {return numBullet;}
    void move(int r, int c);
    void update(int key);
    bool out();
    bool isHit(int r, int w, int range);
    void reduceHealth();
    void heal();
    bool mineHit(int r, int c, int xr);
    bool medHit(int r, int c, int xr);
    void hitObstacle();
    bool dead();
};
#endif
