/**
 * Author: Fateh Karan Singh Sandhu, Saurav Pradhan, Saurav Kushwaha
 * Date: November 7, 2018
 * 
 * This file is tester for Hack12
 **/

#include<stdio.h>
#include<stdlib.h>

#include "binomial.h"

int main (int argc, char** argv) {

    // argument count check
    if (argc != 3) {
        printf("Usage: %s n k\n", argv[0]);
    }
    
    // set argument to integers
    int n = atoi(argv[1]); 
    int k = atoi(argv[2]);
    
    // allocate n x k table 
    long** binomial = (long**) malloc (sizeof(long*) * (n+1));
    for (int i = 0 ; i <= n ; i++) {
        binomial[i] = (long*) malloc (sizeof(long)* (k+1));
    }
    
    // initialize every element to -1 (flag value)
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= k ; j++) {
            binomial[i][j] = -1;
        }
    }
   
   // call recursive function
   long result = choose (n, k, binomial);

   // print result
   printf("c(%d, %d) = %ld\n", n, k, result);
    
    return 0;
}