/**
 * Author: Fateh Karan Singh Sandhu
 * Date: November 29, 2018
 * 
 * This file contains function tester for hack 14
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include "transaction.h"


int main (int argc, char** argv) {
   transactionReport (argv[1]); //pass in argv as file path
   return 0;
}