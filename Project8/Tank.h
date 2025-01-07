#ifndef _TANK_H_
#define _TANK_H_
#include "Game.h"
#include "Item.h"

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3

#define LASER 3
#define PLAYER 2
#define SUPER 1
#define NORMAL 0

class Tank: public Item {
protected:
    int health;
    int updateCount;
    int direction;
public:
    int type;
    void update(int key) = 0;
    virtual void move(int r, int c) = 0;
    int reportHealth() {return health;}
    virtual int reportNumBullet() {return 0;};
    virtual bool isHit(int r, int w, int range) = 0;
    virtual void reduceHealth() = 0;
    bool died() { return false;}
    bool out() {return false;}
    virtual void hitObstacle() = 0;
    void setHealth(int hp);
};
#endif
