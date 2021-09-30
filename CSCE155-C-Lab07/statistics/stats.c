#include<stdlib.h>
#include<stdio.h>

#include "stats.h"

//TODO: fix the error in this function
void readInArray(int *arr, int size) {
  int i = 0;
  printf("Enter your list of numbers: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  return;
}

int * generateRandomArray(int size) {
  int * randomArr = malloc(sizeof(int) * size);
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}

void printArray(const int *arr, int size) {
  printf("[");
  for(int i=0; i<size-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n ", arr[size-1]);
}

double getMean(int *arr, int size) {
  int sum = 0;
  for (int i=0 ; i < size ; i++) {
    sum += arr[i];
  }

  return (double) sum / size ;

}

int getMin(int *arr, int size){

int minElement = arr[0];

for (int i=0 ; i < size ; i++) {
  if (minElement > arr[i]) {
    minElement = arr[i];
  }
}

return minElement;
}

int getMax(int *arr, int size){

  int maxElement = arr[0];

  for (int i=0 ; i < size ; i++) {
    if (maxElement < arr[i]) {
      maxElement = arr[i];
    }
  }

  return maxElement;
}
