/*  Author: Fateh Karan Singh Sandhu
*   Date: September 6, 2018
*
*   The program computes a monthly savings table detailing the
*   (inflation-adjusted) interest earned each month, contribution,
*   and new balance.
*/

#include<stdlib.h>
#include<stdio.h>

int main (int argc, char **argv) {

if (argc != 6) {
  printf ("Error: Put in all command line inputs\n");
  exit(1);
}

// declare all inital input variables

double initalBalance;
double monthlyContribution;
double annualRateOfReturn;
double annualRateOfInflation;
double yearsUntilRetirement;

initalBalance          =  atof (argv[1]);
monthlyContribution    =  atof (argv[2]);
annualRateOfReturn     =  atof (argv[3]);
annualRateOfInflation  =  atof (argv[4]);
yearsUntilRetirement   =  atof (argv[5]);

// error handling

if (initalBalance < 0) {
  printf ("Inital Balance has to be more than $0\n");
  exit(1);
}

// annual contribution can be declared as monthly contribution into 12

double annualContribution = monthlyContribution * 12;

if (annualContribution > 18500) {
  printf ("Maximum annual contribution cannot be more than $18,500\n");
  exit(1);
}

if (annualRateOfReturn < 0 || annualRateOfReturn > 1) {
  printf ("Invalid annual rate of return\n");
  exit(1);
}

if (annualRateOfInflation < 0 || annualRateOfInflation > 1) {
  printf ("Invalid annual rate of inflation\n");
  exit(1);
}

if (yearsUntilRetirement < 0) {
  printf ("Invalid input for years until retirement\n");
  exit(1);
}

// write the formula for the inflated rate of return

double inflationAdjustedRateOfReturn;

inflationAdjustedRateOfReturn = ((1 + annualRateOfReturn) / (1 + annualRateOfInflation)) - 1;

inflationAdjustedRateOfReturn = inflationAdjustedRateOfReturn / 12;

// declare variables for use in loop

double monthsUntilRetirement = yearsUntilRetirement * 12;

double months;

double interest;

double totalBalance;

double remainingBalance = initalBalance;

printf ("Month\t Interest\t Balance\n");

// for loop to be used for savings

for ( months = 1 ; months <= monthsUntilRetirement ; months += 1 ) {

   interest = remainingBalance * inflationAdjustedRateOfReturn;

   totalBalance = remainingBalance + interest + monthlyContribution;

   printf ("%.f\t $%10.2f\t $%10.2f\n", months, interest, totalBalance);

   remainingBalance = remainingBalance + interest + monthlyContribution;
}

printf ("\n");

// calculate total interest earned

double totalInterest = ( totalBalance - initalBalance ) - (monthsUntilRetirement * monthlyContribution);

printf ("Total Interest Earned = $%.2f\n", totalInterest);
printf ("Total Nest Egg. = $%.2f\n\n", totalBalance);

  return 0;

}
