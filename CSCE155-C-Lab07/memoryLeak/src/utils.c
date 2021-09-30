#include <stdlib.h>

#include "utils.h"

int findMedian(const int *array, int size) {
  //make a copy
  int *copy = deepCopy(array, size);
  //sort the copy
  selectionSort(copy, size);
  int medianValue = copy[size/2];
  free(copy);
  return medianValue;
}

int * generateRandomArray(int size) {
  int * randomArr = malloc(sizeof(int) * size);
  for(int i=0; i<size; i++) {
    randomArr[i] = rand();
  }
  return randomArr;
}

int * deepCopy(const int *array, int size) {
  int *copy = malloc(sizeof(int) * size);
  for(int i=0; i<size; i++) {
    copy[i] = array[i];
  }
  return copy;
}

void selectionSort(int *a, int size) {
  int min_index;
  for(int i=0; i<size-1; i++) {
    min_index = i;
    for(int j=i+1; j<size; j++) {
      if(a[min_index] > a[j]) {
        min_index = j;
      }
    }
    //swap
    int t = a[i];
    a[i] = a[min_index];
    a[min_index] = t;
  }
}
