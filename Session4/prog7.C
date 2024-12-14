#include <iostream>
using namespace std;

int main()
{
    int lineN, spNum;
    cin >> lineN;
    for (int i = 1; i <= lineN; i++){
        for (spNum = lineN - i; spNum > 0; spNum--)
        {
            cout << " ";
        }
        for (int k = 1;k <= i; k++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    
}
