#ifndef _GUI_H_
#define _GUI_H_
#include <ncurses.h>

class Gui {
    size_t row;
    size_t col;
    WINDOW* win;
public:
    Gui() : row(20),col(50) {
        init();
        init_color(COLOR_MAGENTA, 1000, 550, 0);
        init_color(COLOR_YELLOW, 1000, 1000, 200);
        init_color(COLOR_BLUE, 1000, 700, 800);
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_BLACK);
        init_pair(10, COLOR_CYAN, COLOR_BLACK);
        init_pair(11, COLOR_YELLOW, COLOR_BLACK);
        init_pair(12, COLOR_BLUE, COLOR_BLACK);
        init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(14, COLOR_GREEN, COLOR_BLACK);
        init_pair(15, COLOR_WHITE, COLOR_WHITE);
    }
    ~Gui() {endwin();}
    void init();
    int get();
    void paintat(size_t, size_t, char);
    void printMsg(int row, int col, const char* prompt, int v);
    void clear();
    void redraw();
    void end() {endwin();}
    void color_on(int);
    void print(int row, int col, const char* prompt);
    void color_off(int);
};
#endif
