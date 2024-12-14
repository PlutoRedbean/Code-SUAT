#include <ncurses.h>

int main () 
{
    initscr(); refresh(); curs_set(0); noecho(); cbreak();
    int row = 10, col = 10, dir = 0;
    char a;
    mvaddch(row, col, 'M');
    while (true) {
        a = getch();
        switch (a) {
        case 'a':
        dir = -1; break;
        case 'd':
        dir = 1; break;
        default:
        break;
        }
        mvaddch(row, col, ' ');
        col += dir;
        mvaddch(row, col, 'M');
    }
    endwin();

    return 0;
}