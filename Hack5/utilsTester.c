/* Author: Fateh Karan Singh Sandhu & SungHa Park
 * Date: September 20, 2018
 *
 * AD-HOC testing
 */

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#include "utils.h"

int main (int argc, char **argv) {
double E = 0.00001;

double deg = 90;

double rad;
double expectedRad = M_PI/2;
rad = degreesToRadians (deg);

printf ("%.2f converted to %.2f\n", deg, rad);

if(fabs(expectedRad - rad) <= E) {
  printf("PASS\n");
} else {
  printf ("FAIL\n");
}

double deg1 = 45;

double rad1;
double expectedRad1 = M_PI/4;
rad1 = degreesToRadians (deg1);

printf ("%.2f converted to %.2f\n", deg1, rad1);

if(fabs(expectedRad1 - rad1) <= E) {
  printf("PASS\n");
} else {
  printf ("FAIL\n");
}

double deg2 = 30;

double rad2;
double expectedRad2 = M_PI/6;
rad2 = degreesToRadians (deg2);

printf ("%.2f converted to %.2f\n", deg2, rad2);

if(fabs(expectedRad2 - rad2) <= E) {
  printf("PASS\n");
} else {
  printf ("FAIL\n");
}

double latitudeA, latitudeB, longitudeA, longitudeB;

latitudeA  = 41.948300;
latitudeB  = 40.820600;
longitudeA = -87.655600;
longitudeB = -96.705600;

double airDistance;

airDistance = getAirDistance (latitudeA, longitudeA, latitudeB, longitudeB);

double expectedDistance = 764.990931;

printf ("%.4f km\n", airDistance);

if (fabs (expectedDistance - airDistance) <= E) {
  printf ("PASS\n");
} else {
  printf ("FAIL\n");
}

double latitudeA1, latitudeB1, longitudeA1, longitudeB1;

latitudeA1  = 35.689500;
latitudeB1  = 51.482600;
longitudeA1 = 139.691700;
longitudeB1 = 0.007700;

double airDistance1;

airDistance1 = getAirDistance (latitudeA1, longitudeA1, latitudeB1, longitudeB1);

double expectedDistance1 = 9556.124161;

printf ("%.4f km\n", airDistance1);

if (fabs (expectedDistance1 - airDistance1) <= E) {
  printf ("PASS\n");
} else {
  printf ("FAIL\n");
}
double latitudeA2, latitudeB2, longitudeA2, longitudeB2;

latitudeA2  = 40.825800;
latitudeB2  = 41.252400;
longitudeA2 = -96.685200;
longitudeB2 = -95.998000;

double airDistance2;

airDistance2 = getAirDistance (latitudeA2, longitudeA2, latitudeB2, longitudeB2);

double expectedDistance2 = 74.645402;

printf ("%.4f km\n", airDistance2);

if (fabs (expectedDistance2 - airDistance2) <= E) {
  printf ("PASS\n");
} else {
  printf ("FAIL\n");
}

double t, t1, t2, percentC, percentC1, percentC2;

t = 20;
percentC = 0.25;

double T;

T = lorentzTimeDilation (t, percentC);

printf ("%f\n", T);

double expectedT = 20.655911;

if (fabs (expectedT - T) <= E) {
  printf ("PASS\n");
} else {
  printf ("FAIL\n");
}

t1 = 10;
percentC1 = 0.25;

double T1;

T1 = lorentzTimeDilation (t1, percentC1);

printf ("%f\n", T1);

double expectedT1 = 10.327955;

if (fabs (expectedT1 - T1) <= E) {
  printf ("PASS\n");
} else {
  printf ("FAIL\n");
}

t2 = 5;
percentC2 = 0.25;

double T2;

T2 = lorentzTimeDilation (t2, percentC2);

printf ("%f\n", T2);

double expectedT2 = 5.163977;

if (fabs (expectedT2 - T2) <= E) {
  printf ("PASS\n");
} else {
  printf ("FAIL\n");
}

return 0;

}
