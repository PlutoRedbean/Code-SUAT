#include <iostream>
using namespace std;

int main()
{
    int product = 2;
    do {
        product *= 2;
    } while (product < 1000);
    cout << product << endl;
}