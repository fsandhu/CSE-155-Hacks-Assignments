/*  Author: Fateh Karan Singh Sandhu
*   Date: September 17, 2018
*
*   This program computes the arithmetic-geometric mean of two positive
*   numbers by reading x; y and e as command line arguments and
*   outputs the AGM to the standard output.
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main (int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: %s x y e (first number, second number, small number e)\n", argv[0]);
    exit(1); }

  double x, y;
  double e;

  x = atof(argv[1]);
  y = atof(argv[2]);
  e = atof(argv[3]);

  double a, g;

  a = (x + y) / 2; // arithmetic mean

  g = sqrt (x * y); // geometric mean

  double absoluteValue = fabs (a - g); // for the first check of the loop

  while (absoluteValue > e) {

    double intermediateA = a; // use intermediate a value to use in loop

    a =  (a + g) / 2 ;

    g =  sqrt (intermediateA * g);

    absoluteValue = fabs (a - g); // update absolute value

  }

  printf ("AGM(%f, %f) = %f\n", x, y, g);
  return 0;
}
