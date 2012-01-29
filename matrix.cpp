#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "matrix.h"

using namespace std;
    
Matrix::Matrix(string filepath)
{
    ifstream inputFile;
    int output;
    int n = 0;
    inputFile.open(filepath.c_str());

    //get matrix dimensions
    inputFile >>  n;
    
    _vector.resize(n);
    _matrix.resize(n);
    for(int i=0; i < n; ++i)
    {
        _matrix[i].resize(n);
    }
    
    int i = 0;
    int j = 0;
    
    while(inputFile >> output)
    {
        if (j == n)
        {
            _vector[i] = output;
            j = 0;
            i++;
        }
        else
        {
            _matrix[i][j] = output;
            j++;
        }
    }
    
    inputFile.close();
}

ostream& operator<<(ostream& out, Matrix x)
{
    out << x.toString();
    return out;
}

string Matrix::toString()
{
    int n = _vector.size();
    stringstream returnString;
    
    for (int i=0; i < n; i++) //go through all elements
    {
        for (int j=0; j < n; j++)
        {
            returnString << _matrix[i][j] << " ";
        }
        returnString << _vector[i] << endl;
    }
    
    return returnString.str();
}


