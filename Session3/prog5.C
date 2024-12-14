#include <iostream>
using namespace std;

int main()
{
    int k;
    cout << "输入整数：";
    cin >> k;

    if(k < 0 || k == 1){
        cout << "c1" << endl;
    }else if(k == 0 || k > 1){
        cout << "c2" << endl;
    }
}