/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 2, 2018
  *
  * This is a header file that contains all the function
  * prototypes and enumerated types.
  *
  **/

//enumerated type for errors

typedef enum {
     NO_ERROR,
     NULL_POINTER_VALUE,
     NEGATIVE_PRESSURE_VALUE,
     INVALID_SCALE,
     NO_INPUT
   } Error;

//enumerated type for scale

typedef enum {
  PASCAL = 1,
  PSI,
  ATM,
  TORR
}  Scale;

//function prototype

Error convertPressure (double *pa,
                       double *psi,
                       double *atm,
                       double *torr,
                       Scale scale);
