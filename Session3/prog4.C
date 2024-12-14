#include <iostream>
using namespace std;

int main()
{
    int i, j;
    cout << "输入第一个整数：";
    cin >> i;
    cout << "输入第二个整数：";
    cin >> j;

    if(i < j){
        cout << j << endl;
    }else if(i > j){
        cout << i << endl;
    }else{
        cout << "i == j\n";
    }
}