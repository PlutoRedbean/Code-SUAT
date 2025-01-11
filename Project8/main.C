#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
    srand(time(0));
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    time_t currentTime = oldTime;
    Game game(argv);
    while (true) {
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        if (currentTime - oldTime < 60) {usleep(22);continue;}
        game.update();
        if (game.state == END) break;
        oldTime = currentTime;
    }
    return 0;
}
