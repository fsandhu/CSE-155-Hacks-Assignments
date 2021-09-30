/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 9, 2018
  *
  * This is the source file that contains funciton code
  */

#include<stdlib.h>
#include<stdio.h>


int subSum(const int *a, int size, int i, int j) {

  int m = 0;
  int total = 0; //new variable to track total
  for (m = i ; m <= j ; m++) {
    total += a[m]; //append total for all elements between indices
  }
  return total;
}


int sum(const int *a, int size) {

  int i = 0;
  int total = 0; //new variable to track total
  for (i = 0 ; i < size ; i++) {
    total += a[i]; //increment total for all elements
  }
  return total;
}

int maxSubArraySum(const int *a, int size) {

int max = 0; // new variable to keep track of max sum
int subArraySum = 0; //new variable to track sum of each subarray
for (int i = 0; i < size ; i++) {
  for (int j = i ; j < size ; j++) {
   subArraySum = subSum(a, size, i, j);
   // check if subarray sum exceed the last subarray sum
   if (subArraySum >= max) {
     max = subArraySum;
   }
  }
}
  return max;
}


int isEqual(const int *a, const int *b, int size) {
  int i = 0;
  int equal = 0; // variable to keep track to equal elements
  for (i = 0 ; i < size ; i++) {
    if ( a[i] == b[i] ) {
      equal++; //increment for each equal element
    }
  } if ( equal == size ) {
    // if variable equal is same as size, elements are equal
     return 1;
    }
    return 0;
}

int containsSameElements(const int *a, int sizeOfA,
                         const int *b, int sizeOfB) {
   int i = 0;
   int j = 0;
   int equals = 0;

  // loop if size A is bigger

      for (i = 0 ; i < sizeOfA ; i++) {
        for (j = 0 ; j < sizeOfB ; j++) {
          if (b[j] == a[i]) {
            equals++;
          }
        } if (equals == 0) {
          return 0;
        } else {
          equals = 0;
        }
      }

  // loop if size B is bigger

      for (i = 0 ; i < sizeOfB ; i++) {
        for (j = 0 ; j < sizeOfA ; j++) {
          if (a[j] == b[i]) {
            equals++;
          }
        } if (equals == 0) {
          return 0;
        } else {
          equals = 0;
        }
      }

  // return 1 after both loops
  // matrices are equal

       return 1;
 }

 void selectionSort(int *a, int size) {

  int i, j, minIndex;
  for(i=0; i<size-1; i++) {
   minIndex = i;
  for(j=i+1; j<size; j++) {
    if(a[minIndex] > a[j]) {
    minIndex = j;
    }
  }
   //swap
    int t = a[i];
    a[i] = a[minIndex];
    a[minIndex] = t;
   }
 }

 int orderStatistic(const int *a, int size, int k) {

  // initialize a deep copy

   int *deepCopy = (int *) malloc (sizeof(int) * size);
   int i = 0;
   for (i = 0 ; i < size ; i++) {
     deepCopy[i] = a[i];
   }

   //apply selection sort algorithm

   selectionSort(deepCopy, size);

   return deepCopy[k];
  }
