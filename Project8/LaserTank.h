#ifndef _LASERTANK_H_
#define _LASERTANK_H_
#include "Game.h"
#include "Tank.h"
#define NOSHOOT 0
#define SHOOT 1

class LaserTank: public Tank {
protected:
    int health;
    int updateCount;
    int direction;
public:
    int shoot_count = 0;
    LaserTank (Game* g);
    int type;
    int status = NOSHOOT;
    void update(int key);
    void move(int r, int c);
    int reportHealth() {return health;}
    int reportNumBullet() {return 0;};
    bool isHit(int r, int w, int range);
    void reduceHealth();
    bool movable ();
    bool shootable (int r, int c);
    bool died() { return false;}
    bool out() {return false;}
    void hitObstacle();
};

#endif
