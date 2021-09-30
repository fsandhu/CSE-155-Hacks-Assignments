#include<stdlib.h>
#include<stdio.h>

#include "array_utils.h"

int main(int argc, char **argv) {

  int n = 5;
  int a[] = {1, 6, 7, 2, 3};
  int b[] = {9, 4, 2, 5, 2};

  int d;
  int err = dotProduct(a, b, n, &d);
  if(err) {
    printf("There were an error.\n");
  } else {
    printf("dot product = %d\n", d);
  }

  int*appendedArray = append (a, 5, b, 5);

  printf ("Appended Array:");
  for (int i = 0 ; i < n+n ; i++) {
    printf("(%d)",  appendedArray[i]);
  }
  return 0;
}
