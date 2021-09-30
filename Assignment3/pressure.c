/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 2, 2018
  *
  * This source file contains source code for the function
  * that converts pressure into pascal, atm, psi and torr.
  *
  **/

#include<stdlib.h>
#include<stdio.h>

#include "pressure.h"

Error convertPressure(double *pa,
                      double *psi,
                      double *atm,
                      double *torr,
                      Scale scale) {

  // NULL Pointer Check

  if (pa == NULL || psi == NULL || atm == NULL || torr == NULL) {
    return NULL_POINTER_VALUE;
  }

  // Scale CHECK

  if (scale == PASCAL) {
    *psi  = (*pa) * 0.0001450377378;
    *atm  = (*pa) * (1/101325.0);
    *torr = (*pa) * (760.0/101325);
  }

else if (scale == PSI) {
    *pa   = (*psi) * 6894.75729;
    *atm  = (*psi) * 0.068045964;
    *torr = (*psi) * 0.068045964 * 760.0;
  }

else if (scale == ATM) {
    *pa   = (*atm) * 101325;
    *psi  = (*atm) * (101325/6894.75729);
    *torr = (*atm) * 760;
  }

else if (scale == TORR) {
    *pa   = (*torr) * (101325/760.0);
    *psi  = (*torr) * (1/760.0) * (1/0.068045964);
    *atm  = (*torr) * (1/760.0);
  }

// return INVALID_SCALE if scale is not between the domain

else {
  return INVALID_SCALE;
}

// Negative Value check and error handling

  if (*pa < 0 || *psi < 0 || *atm < 0 || *torr < 0) {
    return NEGATIVE_PRESSURE_VALUE;
  }

    return NO_ERROR;
}
