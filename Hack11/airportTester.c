/**
 * Author: Fateh Karan Singh Sandhu
 * Collaborators: Saurav Pradhan, Saurav Kushwaha
 * Date: October 30, 2018
 * 
 * This is the tester file for functions
 * in Hack11.
 **/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#include "airport.h"

int main (int argc, char** argv) {

  double epsilon = 0.0001; // small value to check error

  // initialize airports for AD-HOC testing

  Airport* JFK = createAirport ("jfk001" , "commercial" , "JFK" , 40.6413, 73.7781, 339, "New York" , "USA"); 
  Airport* LAX = createAirport ("lax2" , "commercial" , "LAX" , 33.9416, 118.4085, 591, "Los Angeles" , "USA"); 
  Airport* YYZ = createAirport ("yvz19" , "commercial" , "YYZ" , 43.6777, 79.6248, 1221, "Toronto" , "CAN");
  Airport* ORD = createAirport ("ohare19" , "commercial" , "ORD" , 41.9742, 87.9073, 900, "Chicago" , "USA");
  Airport* DEL = createAirport ("igi19" , "commercial" , "DEL" , 28.5562, 167.1000, 051, "New Delhi" , "IND");
 
  // convert to strings

  char *jfkString = airportToString (JFK); 
  char *laxString = airportToString (LAX);
  char *yyzString = airportToString (YYZ);

  char expectedString1[] = "jfk001, commercial, JFK, 40.641300, 73.778100, 339, New York, USA";
  printf("Expected String: %s\n", expectedString1);
  printf ("Output String: %s\n", jfkString);
  if (strcmp(expectedString1, jfkString) == 0) {
    printf("Passed!\n\n");
  } else {
    printf("Failed\n\n");
  }
  
  char expectedString2[] = "lax2, commercial, LAX, 33.941600, 118.408500, 591, Los Angeles, USA";
  printf("Expected String: %s\n", expectedString2);
  printf ("Output String: %s\n", laxString);
  if (strcmp(expectedString2, laxString) == 0) {
    printf("Passed!\n\n");
  } else {
    printf("Failed\n\n");
  }
  
  char expectedString3[] = "yvz19, commercial, YYZ, 43.677700, 79.624800, 1221, Toronto, CAN";
  printf("Expected String: %s\n", expectedString3);
  printf ("Output String: %s\n", yyzString);
  if (strcmp(expectedString3, yyzString) == 0) {
    printf("Passed!\n\n");
  } else {
    printf("Failed\n\n");
  }

  double jfkANDlax = getAirDistance (JFK, LAX);
  double expectedValue1 = 3974.336200;
  printf("Expected value (JFK to LAX) = %f\n", expectedValue1);
  printf("Output Value: %f\n", jfkANDlax);

  if (fabs(jfkANDlax-expectedValue1) <= epsilon) {
    printf("Passed!\n\n");
  } else {
    printf("Failed!\n\n");
  }

  double laxANDyyz = getAirDistance (LAX, YYZ);
  double expectedValue2 = 3494.507444;
  printf("Expected value (LAX to YYZ) = %f\n", expectedValue2);
  printf("Output Value: %f\n", laxANDyyz);

  if (fabs(laxANDyyz-expectedValue2) <= epsilon) {
    printf("Passed!\n\n");
  } else {
    printf("Failed!\n\n");
  }

  double jfkANDyyz = getAirDistance (JFK, YYZ);
  double expectedValue3 = 588.189066;
  printf("Expected value (JFK and YYZ) = %f\n", expectedValue3);
  printf("Output Value: %f\n", jfkANDyyz);

  if (fabs(jfkANDyyz-expectedValue3) <= epsilon) {
    printf("Passed!\n\n");
  } else {
    printf("Failed!\n\n");
  }

  Airport* stops = (Airport*) malloc (sizeof(Airport) * 3);
  stops[0] = *LAX;
  stops[1] = *JFK;
  stops[2] = *YYZ;

  double timeLAXtoYYZ = getEstimatedTravelTime (stops, 3, 600, 3.5);
  double expectedValue4 = 14.604209;
  printf("Expected travel time (LAX to YYZ) = %f\n", expectedValue4);
  printf("Output time = %f\n", timeLAXtoYYZ);

  if (fabs(timeLAXtoYYZ-expectedValue4) <= epsilon) {
    printf("Passed!\n\n");
  } else {
    printf("Failed!\n\n");
  }


  Airport* stops1 = (Airport*) malloc (sizeof(Airport) * 3);
  stops1[0] = *JFK;
  stops1[1] = *YYZ;
  stops1[2] = *DEL;

  double timeJFKtoDEL = getEstimatedTravelTime (stops1, 3, 600, 5);
  double expectedValue5 = 23.770716;
  printf("Expected travel time (JFK to DEL) = %f\n", expectedValue5);
  printf("Output time = %f\n", timeJFKtoDEL);

  if (fabs(timeJFKtoDEL-expectedValue5) <= epsilon) {
    printf("Passed!\n\n");
  } else {
    printf("Failed!\n\n");
  }

  Airport* stops2 = (Airport*) malloc (sizeof(Airport) * 3);
  stops2[0] = *ORD;
  stops2[1] = *YYZ;
  stops2[2] = *LAX;

  double timeORDtoLAX = getEstimatedTravelTime (stops2, 3, 600, 1);
  double expectedValue6 = 8.992797;
  printf("Expected travel time (ORD to LAX) = %f\n", expectedValue6);
  printf("Output time = %f\n", timeORDtoLAX);

  if (fabs(timeORDtoLAX-expectedValue6) <= epsilon) {
    printf("Passed!\n\n");
  } else {
    printf("Failed!\n\n");
  }

  return 0;
}