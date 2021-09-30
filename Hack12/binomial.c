/**
 * Author: Fateh Karan Singh Sandhu, Saurav Pradhan, Saurav Kushwaha
 * Date: November 7, 2018
 * 
 * This file contains function code for the function
 * in Hack12.
 **/


#include<stdio.h>
#include<stdlib.h>

#include "binomial.h"


long choose(int n, int k, long** binomial) {
    // base cases & size error check
    if (n == k || k == 0) {
        return 1;
    } else if ( k > n || n < 0 || k < 0) {
        return -1;
    }

    // NULL pointer check
    if (binomial == NULL) {
        return -1;
    }
    
    // check if value has already been computed
    if (binomial[n][k] != -1) {
        return binomial[n][k];
    } else {
        long result = choose(n-1, k, binomial) + choose(n-1, k-1, binomial);
        binomial[n][k] = result;
        return result;
    }
}