Gaussian Elimination in C++
============================

Introduction
------------

This is a small tool in C++ created to solve an nxn matrix and its coefficient vector using Gaussian Elimination. 

It was created as part of a University Assignment.

Requirements
-------------

This tool is built entirely in ANSI C++ using only standard library functions, and therefore has no external dependencies.

Instructions
------------

After compilation, create an 'input.txt' file in the same directory as the executable with the following format.

* The first line of the file is how big the nxn matrix is
* Every subsequent line represents a row in the matrix, which is n+1 digits long (the last digit being part of the co-efficient vector). Numbers are space delimited

An example of the input.txt would be

```
3
1 2 3 5
0 2 4 4
3 0 9 1
```


