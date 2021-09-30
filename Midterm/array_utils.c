/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 17, 2018
  *
  * This is the source file containing function code for
  * the midterm exam
  */

#include<stdlib.h>
#include<stdio.h>

int dotProduct(const int *a, const int *b, int n, int *result) {

if (result == NULL) {
  return 1;
}

// check for size error

if (n < 0) {
  return 1;
}

*result = 0;

for (int i = 0 ; i < n ; i++) {
    *result += (a[i]*b[i]);
  }

  return 0;

}

int * append(const int *a, int n, const int *b, int m) {

  int newSize = n + m; // declare new size for new array

 // error checking for size

  if (n < 0) {
    return NULL;
  }

  if (m < 0) {
    return NULL;
  }

  //dynamically allocate new array

  int* appendedArray = (int *) malloc (sizeof(int) * newSize);

 // if malloc fails return NULL

  if (appendedArray == NULL) {
    return NULL;
  }

for (int i = 0 ; i < n ; i++) {
  appendedArray[i] = a[i];
}

for (int j = 0 ; j < m ; j++) {
  appendedArray[n+j] = b[j];
}

return appendedArray;

}
