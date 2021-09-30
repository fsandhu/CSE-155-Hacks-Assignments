/**
  * Author: Fateh Karan Singh Sandhu
  * Collaborators: Saurav Pradhan, Saurav Kushwaha
  * Date: October 30, 2018
  * 
  * This file contains source code for
  * airport functions
 **/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#include"airport.h"

// reuse old function

double degreesToRadians (double degree) {
  return (degree / 180) * M_PI;
}

// reuse old function

double getAirDistanceFunction  (double latA, double longA,
                                double latB, double longB) {
  // error checking for input values                              
  if (latA > 90 || latB > 90 || latA < -90 || latB < -90) {
   return 0;
  }
  if (longA > 180 || longB > 180 || longA < -180 || longB < -180) {
   return 0;
  }

  // convert to radians
  double latA_R  =  degreesToRadians (latA);
  double latB_R  =  degreesToRadians (latB);
  double longA_R =  degreesToRadians (longA);
  double longB_R =  degreesToRadians (longB);

  return acos ((sin(latA_R) * sin(latB_R)) +
              (cos(latA_R) * cos(latB_R) *
               cos(longB_R - longA_R))) * 6371;
}

char* initString (const char* string1) {
   // allocate new string
   char* string = (char*) malloc (sizeof(char) * strlen(string1)+1);
   strcpy (string, string1); // copy
   return string;
}

void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv) {

  airport->gpsID = initString (gpsId);
  airport->typeOfAirport = initString(type);
  airport->nameOfAirport = initString(name);
  airport->city = initString(city);
  airport->country = initString(countryAbbrv);

  airport->latitude = latitude;
  airport->longitude = longitude;
  airport->elevation = elevationFeet;

  return;
}

Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv) {

  Airport *airport = (Airport*) malloc (sizeof(Airport) * 1); // dynamic allocation

  initAirport (airport, gpsId, type, name, 
               latitude, longitude, elevationFeet, 
               city, countryAbbrv); // reuse function

  return airport;
}

char* airportToString(const Airport* a) {
  // NULL pointer check
  if (a == NULL) {
    return NULL;
  }
    char tempBuffer[1000]; // use a temp buffer to hold string
    sprintf(tempBuffer, "%s, %s, %s, %f, %f, %d, %s, %s", a->gpsID, a->typeOfAirport, 
                                                            a->nameOfAirport, 
                                                            a->latitude, a->longitude,
                                                            a->elevation, 
                                                            a->city, a->country);
    char *result = (char*) malloc (sizeof(tempBuffer)+1); // allocate a new string
    strcpy (result, tempBuffer); // copy elements
    return result;
}

double getAirDistance(const Airport* origin, const Airport* destination) {
  // NULL pointer check
  if (origin == NULL || destination == NULL) {
    return 0;
  }
    double airDistance = getAirDistanceFunction(origin->latitude, 
                                                origin->longitude, 
                                                destination->latitude, 
                                                destination->longitude);
    return airDistance;
}

double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs) {
  
  // NULL pointer check and error check
  if (stops == NULL || size < 0 || aveKmsPerHour < 0 || aveLayoverTimeHrs < 0) {
    return 0;
  }
  double airKMS = 0;
  double layoverTime = 0;
  double totalTime = 0;
  if (size >= 1) {
   layoverTime = (size-1) * aveLayoverTimeHrs;
  } 
  else {
    layoverTime = 0;
  } 
  for (int i = 1 ; i < size ; i++) {
    airKMS += getAirDistance (&stops[i-1], &stops[i]); // iterate over array
  }
  totalTime = (airKMS/aveKmsPerHour) + layoverTime; // calculate total time
  return totalTime; 
}