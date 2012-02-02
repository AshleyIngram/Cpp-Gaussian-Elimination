#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "matrix.h"

using namespace std;
    
Matrix::Matrix(string filepath)
{
    //Constructor - takes file path and constructs
    //matrix object from correctly formatted file
    ifstream inputFile;
    int output;
    int n = 0;
    inputFile.open(filepath.c_str());
    if (!inputFile)
    {
        cout << "Please provide a valid file as input." << endl;
        exit(1);
    }

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
    //Overload the cout operator (<<) for easy printing
    out << x.toString();
    return out;
}

string Matrix::toString()
{
    //Return a string representation of the matrix
    int n = _vector.size();
    stringstream returnString;
    
    for (int i=0; i < n; ++i) 
    {
        for (int j=0; j < n; ++j)
        {
            returnString << _matrix[i][j] << " ";
        }
        returnString << " | " << _vector[i] << endl;
    }
    
    if (!_solution.empty())
    {
        returnString << endl << "Solution Vector: ";
        
        for (unsigned int i=0; i < _solution.size(); ++i)
        {
            returnString << _solution[i];
            if (i != _solution.size()-1)
                returnString << ", ";
            else
                cout << endl;
        }
        returnString << endl;
    }
        
    return returnString.str();
}

void Matrix::solve(bool verbose)
{
    _verbose = verbose;
    triangularForm();
    _solution = backwardsSubstitution();
}

void Matrix::triangularForm()
{
    //Perform Gaussian elimination on the matrix and
    //return the solved system
    int n = _vector.size();
   
   for (int i = 0; i < n; ++i)
   {
        //for every row...
        for (int j = i+1; j < n; ++j)
        {
            //calculate ratio for every row below it using the triangular
            double ratio = _matrix[j][i] / _matrix[i][i];
            for(int k = 0; k < n; ++k)
            {
                //Eliminate every column based on that ratio
                _matrix[j][k] = _matrix[j][k] - (_matrix[i][k] * ratio);
            }
            //elimination on the coefficient vector
            _vector[j] = _vector[j] - (_vector[i] * ratio);
            
            if (_verbose)
                cout << *this << endl;
        }
   }
}

vector<double> Matrix::backwardsSubstitution()
{
    vector<double> rhs = vector<double>(_vector.size());

    for (int i = _vector.size()-1; i > -1; --i)
    {
        double current = 0;
        for (unsigned int j = i; j < _vector.size(); ++j)
        {
            current = current + (_matrix[i][j] * rhs[j]);
        }
        rhs[i] = (_vector[i] - current) / _matrix[i][i];
    }
        
    return rhs;
}


