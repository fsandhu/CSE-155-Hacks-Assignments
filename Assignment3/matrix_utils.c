/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 11, 2018
  *
  * This file contains source code for functions
  */

#include<stdio.h>
#include<stdlib.h>

#include "matrix_utils.h"

//function 1

int **getIdentityMatrix(int n) {

  // initialize new multi dimensional matrix

  int **identityMatrix = NULL;
  identityMatrix = (int **) malloc (sizeof(int *) * n);

   for (int i = 0 ; i < n ; i++) {
    identityMatrix[i] = (int *) malloc (sizeof(int) * n);
   }

  int i = 0;
  int j = 0;

  // set all elements equal to 1 where i = j
  // set all other elements to 0

  for (i = 0 ; i < n ; i++) {
    for (j = 0 ; j < n ; j++) {
      if (i == j) {
        identityMatrix[i][j] = 1;
      } else {
        identityMatrix[i][j] = 0;
      }
    }
  }

  return identityMatrix;
}

//function 2

int isEqual(int **A, int **B, int n) {

  int equals = 0;

  // use variable equals to see if all elements are equal

  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n ; j++) {
      if (A[i][j] == B[i][j]) {
        equals++; // increment
      }
    }
  } if (equals == (n*n)) {
    return 1;
  }
 return 0;
}

//function 3

int *getRow(int **A, int n, int i) {
  int *row = (int *) malloc (sizeof(int) * n); // initialize new array

  for (int j = 0 ; j < n ; j++) {
    row[j] = A[i][j]; // set all element is row array to specified row
  }

  return row;
}

//function 4

int *getCol(int **A, int n, int j) {
  int *col = (int *) malloc (sizeof(int) * n); //initialize new array

  for (int i = 0 ; i < n ; i++) {
    col[i] = A[i][j]; // set all element is column array to specified column
  }

  return col;
}

// function 5

int ** product(int **A, int **B, int n) {

  //initialize a multi dimensional array for product

  int **product = NULL;
  product = (int **) malloc (sizeof(int*) * n);
  for (int i = 0 ; i < n ; i++) {
    product[i] = (int *) malloc (sizeof(int) * n);
  }

  //set all elements to 0 because we append on something and
  //appending on unitialized elements might give garbage values.

for (int i = 0 ; i < n ; i++) {
  for (int j = 0 ; j < n ; j++) {
    product[i][j] = 0;
  }
}

  for (int k = 0 ; k < n ; k++) {
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < n ; j++) {
        product[i][j] += (A[i][k]) * (B[k][j]); //formula from assignment 
      }
    }
  }
  return product;
}
