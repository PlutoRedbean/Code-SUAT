#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main (int argc, char **argv) 
{
    ifstream infile (argv[1]);
    if (!infile.is_open()) {
        return 0;
    }
    int id;
    double msalary, months;
    infile >> id >> msalary >> months;
    infile.close();

    ofstream outfile (argv[2]);
    if (!outfile.is_open()) {
        return 0;
    }
    outfile << setw(9) << setfill(' ') << id << endl;
    outfile << scientific << msalary << endl;
    outfile.unsetf(ios::scientific);
    outfile << setw(4) << setfill(' ') << months << endl;
    // cout << id << " " << msalary << " " << months << endl;
    outfile.close();
    return 0;
}