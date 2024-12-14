#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please input an integer\n";
    cin >> n;
    if(n > 10){
        cout << "it is larger that 10\n";
    }
    else {
        cout << "it is <= 10\n"; 
    }
    return 0;
}