#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

int main(int argc, char** argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s <number of random lists to generate>\n", argv[0]);
    exit(1);
  }

  //initialize random number generator with current time:
  srand(time(NULL));

  int size = 50000;
  int n = atoi(argv[1]);
  for(int i=0; i<n; i++) {
    //generate a random array and find the median:
    int * randomArray = generateRandomArray(size);
    int medianValue = findMedian(randomArray, size);
    printf("The median element of the randomly generated array is %d\n", medianValue);
    free(randomArray);
  }

  return 0;
}
