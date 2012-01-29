#include <string>
#include <cstring>
#include <iostream>
#include "matrix.h"


using namespace std;

int main(int argc, char *argv[])
{
    //read in file
    
    bool verbose = false;
    
    if (argc == 1)
    {
        cout << "Invalid Usage. Please Provide at least 1 command line argument (matrix filename [-v]" << endl;
        return 1;
    }
    else if(argc == 3 && strcmp(argv[2], "-v") == 0)
    {
        verbose = true;
    }
    
    Matrix matrix = Matrix(argv[1]);
    cout << "Initial Matrix" << endl << matrix << endl;
    matrix.solve(verbose);
    cout << "Solution" << endl << matrix << endl;
    
    return 0;
}