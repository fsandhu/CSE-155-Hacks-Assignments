/*  Author: Fateh Karan Singh Sandhu
*   Date: October 17, 2018
*
*   This is the program 1 for midterm.
*/

#include<stdlib.h>
#include<stdio.h>

int main (int argc, char **argv) {

int i = 0;

for(i = 1 ; i <= 100 ; i++) {

  if (i % 15 == 0) {

    printf("FizzBuzz\n"); // if divisible by 3 and 5 i.e 15
  }
  else if (i % 3 == 0) {

    printf("Fizz\n"); // if divisible by only 3
  }
  else if (i % 5 == 0) {

    printf ("Buzz\n"); // if divisible by only 5
  }
  else {

    printf ("%d\n", i); // not divisible by 3 or 5
  }
}
  return 0;
}
