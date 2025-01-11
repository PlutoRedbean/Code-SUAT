#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include "Gui.h"
#include "Item.h"
using namespace std;

#define END 100
#define RUNNING 101
#define PAUSE 102
#define RESET 103
#define DEAD 104

#define MAXTANK 20
#define MAXMEDPACK 4
#define MEDPACKTIME 300
#define MAXCURRENTTANK 4

#define PLAYERCOLOR 10
#define NORMALCOLOR 11
#define SUPERCOLOR 12
#define MINECOLOR 13
#define MEDPACKCOLOR 14
#define OBSTACLECOLOR 1
#define LASERCOLOR 16

class RemovableItem;
class Player;
class Bullet;
class Tank;
class Mine;
class Medpack;

class Game {
    Gui gui;
    Player* pl;
    Tank* tank;
    list <RemovableItem*> items;
    list <Tank*> tanks;
    size_t score;
    int med_refresh_time;
    size_t tank_number;
    size_t tank_max_number;
public:
    int playground[80][30] = {};
    int state = RUNNING;
    Game(char** argv) ;
    ~Game() {gui.end();}
    void addRemovableItem(RemovableItem*);
    void update();
    void paintat(size_t ro, size_t cl, char c) {gui.paintat(ro, cl, c);}
    bool hitPlayer(int r, int w, int range, int shooter);
    bool mineBlast(int r, int w, int range);
    bool medPick(int r, int w, int range);
    void updateRemovableItems(int c) ;
    void bang();
    void updateTanks(int c);
    void medRefresh();
    void pg_spawn();
    void pg_read(ifstream& Map);
    void map_paint();
    void addColor(int num);
    void stopColor(int num);
    void obj_init(Game* init);
    void obstacleExpand(int& i, int& j, int& extension);
    bool checkHit(int r, int c, int range, int shooter); //range, hit range, can be 0 or 1
    bool spawnable(int r, int c, int range);
    // void medSpawn();
    // void tank_spawn(int player_range, int tank_range);
};
#endif
