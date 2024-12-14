#include <iostream>
using namespace std;

int main()
{
    int product = 2;
    while (true)
    {
        product *= 2;
        cout << product << endl;
        if (product > 10){
            break;
        }
    }
    cout << product << endl;
}