#ifndef _ENEMYTANK_H_
#define _ENEMYTANK_H_
#include "Game.h"
#include "Item.h"

#define MAXMINE 10

class EnemyTank : public Tank {
public:
    int shoot_count = 0;
    int place_count = 0;
    int mine_placed = 0;
    EnemyTank (Game* g) ;
    void update (int key);
    bool isHit (int r, int w, int range);
    void reduceHealth ();
    bool out ();
    void move (int r, int c);
    bool movable ();
    bool shootable (int r, int c);
    bool mine_place (int r, int c);
    void hitObstacle();
};
#endif
