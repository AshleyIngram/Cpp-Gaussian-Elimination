#include <string>
#include <iostream>
#include "matrix.h"


using namespace std;

int main()
{
    //read in file
    Matrix matrix = Matrix("./input.txt");
    cout << matrix << endl;
    
    return 0;
}