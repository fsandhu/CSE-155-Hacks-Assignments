/**
 * Author: Fateh Karan Singh Sandhu
 * Date: November 29, 2018
 * 
 * This file prints out a report of transaction files.
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include "transaction.h"


int main (int argc, char** argv) {
   
  //argument count check
   if (argc > 3 || argc < 2) {
      printf ("Error: provide file path\n");
      exit(1);
   }

   // print out a report

   transactionReport(argv[1]);
   printf ("\n\n");
   validateData(argv[1]);
   printf ("\n\n");
   checkLimit(argv[1]);
   printf ("\n\n");
   checkRepeatedTransactions(argv[1]);
   printf ("\n\n");
   benfordAnalysis(argv[1]);
   printf ("\n\n");
   findDataAnomalies(argv[1], argv[2]);

   return 0;
}