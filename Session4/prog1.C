#include <iostream>
using namespace std;

int main()
{
    int product = 2;
    while (product <= 1024){
        product *= 2;
    }
    cout << product << endl;

    int product2 = 2;
    while (product2 < 1024){
        product2 *= 2;
    }
    cout << product2 << endl;
}