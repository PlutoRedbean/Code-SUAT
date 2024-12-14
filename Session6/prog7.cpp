#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv) 
{
    ofstream myfile (argv[1]);
    if (!myfile.is_open()) {
        return 0;
    }
    myfile << 10 << " " << 100 << " " << 120 << endl;
    myfile.close();
    return 0;
}