/* Author: Fateh Karan Singh Sandhu & SungHa Park
 * Date: September 20, 2018
 *
 * Function Definitions
 */

 #include<math.h>
#include "utils.h"


double degreesToRadians (double degree) {
  return ( degree / 180 ) * M_PI;
}

double getAirDistance  (double latA, double longA,
                       double latB, double longB) {

  double latA_R  =  degreesToRadians (latA);
  double latB_R  =  degreesToRadians (latB);
  double longA_R =  degreesToRadians (longA);
  double longB_R =  degreesToRadians (longB);

  return acos ((sin(latA_R) * sin(latB_R)) +
              (cos(latA_R) * cos(latB_R) *
               cos(longB_R - longA_R))) * 6371;
}

double lorentzTimeDilation (double t, double percentC) {
  return ( t / sqrt (1 - (percentC*percentC)) );
}
