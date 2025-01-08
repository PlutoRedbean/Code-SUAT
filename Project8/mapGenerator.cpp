#include <fstream>
#include <iostream>

#define COL 80
#define ROW 30

using namespace std;

int main()
{
    ofstream Map("empty_map.txt");
    for (int i = 0; i <= ROW + 1; i++) {
        for (int j = 0; j <= COL + 1; j++) {
            if (j == 0 || j == COL + 1) {
                if (i == 0 || i == ROW + 1) Map << '+';
                else Map << '|';
            } else {
                if (i == 0 || i == ROW + 1) Map << '-';
                else Map << ' ';
            }
        }
        Map << "\n";
    }
    Map.close();
    return 0;
}
