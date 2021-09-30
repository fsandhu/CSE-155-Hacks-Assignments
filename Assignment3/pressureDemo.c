/**
  * Name: Fateh Karan Singh Sandhu
  * Date: October 2, 2018
  *
  * This is a demo file for testing my function
  * of converting pressure values.
  */

#include<stdlib.h>
#include<stdio.h>

#include "pressure.h"

int main (void) {

 printf ("Scales:\n");
 printf  ("1. Pascal\n");
 printf  ("2. PSI\n");
 printf  ("3. Atmosphere\n");
 printf  ("4. Torr\n\n");

 int scale = 0;

 printf ("Choose a scale: ");
 scanf  ("%d", &scale);
 printf ("\n");

 double value = 0.0;

 printf ("Enter value: ");
 scanf  ("%lf", &value);
 printf ("\n");


  double pascal = 0.0;
  double psi    = 0.0;
  double atm    = 0.0;
  double torr   = 0.0;

 if (scale == PASCAL) {
   pascal = value;
 }

 if (scale == PSI) {
   psi = value;
 }

 if (scale == ATM) {
   atm = value;
 }

 if (scale == TORR) {
   torr = value;
 }

 int error = convertPressure (&pascal, &psi, &atm, &torr, scale);

 if (error == NULL_POINTER_VALUE) {
   printf("NULL_POINTER_VALUE\n");
   exit(1);
 } else if (error == NEGATIVE_PRESSURE_VALUE) {
   printf("NEGATIVE_PRESSURE_VALUE\n");
   exit(1);
 } else if (error == INVALID_SCALE) {
   printf("INVALID_SCALE\n");
   exit(1);
 } else {
   printf("NO_ERROR\n");
   exit(1);
 }

 printf ("The converted values are:\n %f pascal\n %f psi\n %f atm\n %f torr\n error code = %d\n",
          pascal, psi, atm, torr, error);

 printf ("\n");

 return 0;
}
