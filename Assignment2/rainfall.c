/*
 *  Author: Fateh Karan Singh Sandhu
 *  Date: September 16, 2018
 *
 *  This problem prompts the user for inputs for rainfall
 *  until they put in a value of 99999 and then computes then
 *  average rainfall.
 */

 #include<stdio.h>
 #include<stdlib.h>

 int main (int argc, char **argv) {

   // declare all variables

   double inputRainfall = 0;
   double rainfall = 0;
   double days = 0;

      while (inputRainfall != 99999) {
        scanf ("%lf", &inputRainfall);
        if (inputRainfall < 0) {
          inputRainfall = 0;
          days = days - 1;
        }
        rainfall = rainfall + inputRainfall;
        days = days + 1;
   }

   // decrease the last input of 99999 and days by 1

   rainfall = rainfall - 99999;
   days = days - 1;

   // if no input is entered

   if (days == 0) {
     printf("Error: no input\n");
     exit(1);
   }

   //calculate average rainfall by declaring a new variable

   double averageRainfall;

   averageRainfall = rainfall / days ;

   printf ("The average rainfall is = %.2f\n", averageRainfall);

   return 0;
 }
