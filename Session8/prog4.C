#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    vector<double> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i*1.1);
    }
    vector<double>::iterator vt;
    for (vt = v1.begin(); vt != v1.end(); vt++) {
        cout << *vt << " ";
    }
    cout << endl;
    cout << v1[2] << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
    return 0;
}