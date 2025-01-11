#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;

void Gui::init() {
    initscr();                  /* Start curses mode              */
    refresh();                  /* Print it on to the real screen */
    win = stdscr;
    refresh();
    curs_set(0);
    wrefresh(win);
    noecho();
    cbreak();
    keypad(win, true);
    nodelay(win, true);
    flushinp();
    start_color();
    attron(COLOR_PAIR(1));
    mvaddch(0, 0, '+');
    mvaddch(0, 81, '+');
    mvaddch(31, 0, '+');
    mvaddch(31, 81, '+');
    for (int i = 1; i <= 80; i++) {
        mvaddch(0, i, '-');
        mvaddch(31, i, '-');
    }
    for (int i = 1; i <= 30; i++) {
        mvaddch(i, 0, '|');
        mvaddch(i, 81, '|');
    }
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 80; j++) {
            mvaddch(i, j, ' ');
        }
    }
    attroff(COLOR_PAIR(2));
}

int Gui::get() {
    int c = wgetch(win);
    flushinp();
    return c;
}

void Gui::paintat(size_t rw, size_t cl, char c) {
    mvwaddch(win, rw, cl, c);
    return;
}

void Gui::printMsg(int row, int col, const char* prompt, int v) {
    mvwprintw(win, row, col, prompt);
    char s[32];
    sprintf(s, "%d", v);
    mvwprintw(win, row, col+strlen(prompt)+1, s);
}

void Gui::print(int row, int col, const char* prompt) {
    mvwprintw(win, row, col, prompt);
}

void Gui::clear() {
    werase(win);
    attron(COLOR_PAIR(1));
    mvaddch(0, 0, '+');
    mvaddch(0, 81, '+');
    mvaddch(31, 0, '+');
    mvaddch(31, 81, '+');
    for (int i = 1; i <= 80; i++) {
        mvaddch(0, i, '-');
        mvaddch(31, i, '-');
    }
    for (int i = 1; i <= 30; i++) {
        mvaddch(i, 0, '|');
        mvaddch(i, 81, '|');
    }
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 80; j++) {
            mvaddch(i, j, ' ');
        }
    }
    attroff(COLOR_PAIR(2));
}

void Gui::color_on(int num) {
    attron(COLOR_PAIR(num));
}

void Gui::color_off(int num) {
    attroff(COLOR_PAIR(num));
}

void Gui::redraw() {
    wrefresh(win);
}
