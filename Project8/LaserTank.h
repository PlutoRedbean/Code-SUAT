#ifndef _LASERTANK_H_
#define _LASERTANK_H_
#include "Game.h"
#include "Tank.h"

class LaserTank: public Tank {
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
