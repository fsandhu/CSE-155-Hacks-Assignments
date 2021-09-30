/**
 * Statistics main driver program
 */
#include <stdlib.h>
#include <stdio.h>

#include "stats.h"

#define SIZE 500

int main(int argc, char** argv) {

  //seed the random number generator with the current time
  srand(time(NULL));

  int min, max, size;
  double mean;

  printf("Enter the amount of numbers you'd like to find the stats for: ");
  scanf("%d", &size);

  /*

    if(size > SIZE) {
    printf("ERROR: program does not support that many integers!\n");
	  exit(1);
	}

  */

	//TODO: declare a static array "large enough" to hold as many integers as we'll need

  // int array[SIZE];

	//TODO (Activity 3): change your delcaration and initialization to use
	// a dynamic array and malloc instead

//  int *array = (int *) malloc (sizeof(int) * size);

	//TODO: pass the appropriate variable
//	readInArray(array, size);

	//TODO: pass the appropriate variables to your functions here


  int *array = generateRandomArray (size);

  min = getMin(array, size);
  max = getMax(array, size);
  mean = getMean(array, size);
  printArray(array, size);

  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  printf("Mean: %.2f\n", mean);

  free(array);

  return 0;
}
