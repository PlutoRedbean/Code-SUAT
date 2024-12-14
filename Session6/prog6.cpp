#include <iostream>
#include <iomanip>

using namespace std;

int main () 
{
    cout << hex << 100 << endl;
    char ch = 'a';
    cout << setw(10) << setfill('*') << ch << endl;
    cout << dec << showpos << 100 << " " << -100 << endl;
    cout << noshowpos << 100 << " " << -100 << endl;
    cout << scientific << -100.0123 << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << -100.0123 << endl;
    return 0;
}