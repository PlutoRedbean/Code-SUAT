#include <iostream>
#include "max.h"
#include "min.h"
#include "average.h"

using namespace std;

int main()
{
    float x, y;
    cout << "input 2 numbers\n";
    cin >> x >> y;
    cout << "max = " << max(x, y) << endl;
    cout << "min = " << min(x, y) << endl;
    cout << "average = " << average(x, y) << endl;
    return 0;
}