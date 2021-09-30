/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 11, 2018
  *
  * This is the header file for my matrix
  * functions.
  */


// this function builds an identity matrix of size namespace n

int **getIdentityMatrix(int n);


// this function takes two matrices and determines if
// they are equal (all of their elements are the same).

int isEqual(int **A, int **B, int n);


// this function takes a matrix and an index i and
//returns a new array that is equal to the i-th row of the matrix.

int *getRow(int **A, int n, int i);


// this function takes a matrix and an index j and returns a new array
// that is equal to the j-th column of the matrix.

int *getCol(int **A, int n, int j);


// this function computes the product of two square matrices

int ** product(int **A, int **B, int n);
