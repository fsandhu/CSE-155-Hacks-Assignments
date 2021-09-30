/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 9, 2018
  *
  * This is the prototype file for my array
  * functions.
  */

// this function gives sum of array elements between indices i and j

int subSum(const int *a, int size, int i, int j);


// this function gives sum of all elements of array

int sum(const int *a, int size);


// this function gives sum of subarray

int maxSubArraySum(const int *a, int size);


// this function takes in two arrays of same size and checks if they
// they are equal

int isEqual(const int *a, const int *b, int size);


// this function that takes two integer arrays
// and determines if they both contain the same elements

int containsSameElements(const int *a, int sizeOfA,
                         const int *b, int sizeOfB);


// sorting funciton

int orderStatistic(const int *a, int size, int k);

// selection sort algorithm

void selectionSort(int *a, int size);
