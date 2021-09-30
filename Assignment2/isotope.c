/**
  * Author: Fateh Karan Singh Sandhu
  * Date: September 19, 2018
  *
  * This program will then produce a table detailing
  * the amount of the element that remains after each year
  * until less than 50% of the original amount remains.
  *
  **/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (int argc, char **argv) {

// argument count error handling

if ( argc != 6 ) {
  printf("Usage: %s Element Name, Element Symbol, H (half life), m (initial mass)\n", argv[0]);
  exit (1);
}

// declare all variables

int atomNumber;
double halfLife, initialMass;

// prompting for command line arguments

atomNumber = atoi(argv[1]);
halfLife   = atof(argv[4]);
initialMass = atof(argv[5]);

// initalize year = 0 for the loop

double year = 0;
double remainingMass = initialMass;
double power;

// error handling

if (halfLife < 0) {
  printf("Error: Half Life cannot be less than 0 years\n");
  exit (1);
}

if (atomNumber < 0) {
  printf("Error: Atomic Number cannot be negative\n");
  exit (1);
}

if (initialMass < 0) {
  printf("Error: Inital Mass cannot be less than 0 grams\n");
  exit (1);
}

printf("%s  (%d-%s)\n", argv[2], atomNumber, argv[3]);
printf("Year\t Amount\n");
printf("------------------\n");

// for loop to calculate amount remaining until it is less than 50%

for (year = 0 ; year <= halfLife + 1 ; year++) {

  power = year/halfLife;

  remainingMass = initialMass * pow (0.5, power);

  printf("%.f\t %.3fg \n", year, remainingMass);

}

  return 0;
}
