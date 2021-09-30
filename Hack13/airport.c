/**
  * Author: Fateh Karan Singh Sandhu
  * Collaborators: Saurav Pradhan, Saurav Kushwaha
  * Date: November 15, 2018
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
    char *result = (char*) malloc (sizeof(char)*strlen(tempBuffer)+1); // allocate a new string
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

// comparator by gps ID

int cmpByGPSId(const void* a, const void* b){
	const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
	int result = strcmp(x->gpsID ,y->gpsID);
  return result;
}

// comparator by type

int cmpByType(const void* a, const void* b) {
	const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
	int result = strcmp(x->typeOfAirport ,y->typeOfAirport);
	return result;
}

// comparator by name

int cmpByName(const void* a, const void* b) {
	const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
	int result = strcmp(x->nameOfAirport ,y->nameOfAirport);
	return result;
}

// comparator by gps name (descending)

int cmpByNameDesc(const void* a, const void* b) {
	const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
	int result = strcmp(y->nameOfAirport ,x->nameOfAirport);
	return result;
}

// comparator by country and city

int cmpByCountryCity(const void* a, const void* b) {
	const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
	int result = strcmp(x->country ,y->country);
  if (result == 0) {
    int newResult = strcmp (x->city ,y->city);
    return newResult;
  }
	return result;
}

// comparator by latitude (north to south)

int cmpByLatitude(const void* a, const void* b){
	const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
  if (x->latitude > y->latitude) {
    return -1;
  } else if (x->latitude < y->latitude) {
    return 1;
  } else {
    return 0;
  }
}

// comparator by longitude (west to east)

int cmpByLongitude(const void* a, const void* b) {
  const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
  if (x->longitude > y->longitude) {
    return 1;
  } else if (x->longitude < y->longitude) {
    return -1;
  } else {
    return 0;
  }
}

// comparator by distance from lincoln airport

int cmpByLincolnDistance(const void* a, const void* b){
  const Airport* x = (const Airport *) a;
	const Airport* y = (const Airport *) b;
  Airport* lincoln = createAirport("", "", "", 40.846176, -96.75471, 0, "", ""); // hardcode lat, long values
  if (getAirDistance(x, lincoln) < getAirDistance(y, lincoln)) {
    return -1;
  } else if (getAirDistance(x, lincoln) > getAirDistance(y, lincoln)) {
    return 1;
  } else {
    return 0;
  }
  free (lincoln); // free to prevent memory leak
}

// function to print airport

void printAirport(const Airport* a) {
  if (a == NULL) {
    printf("null\n");
    return;
  }
  char *airport = airportToString (a);
  printf ("%s\n", airport);
  return;
}

void generateReports(Airport *airports, int n) {

  // NULL array check

  if (airports == NULL || n < 0) {
    return;
  }
  
  printf ("Printing all airports:\n");
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf ("Airports sorted by GPS ID:\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf ("Airport sorted by Type:\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf("Printing large airports if any in database:\n");

  // write a for loop to check for all the large airports in the sorted array
  for (int i = 0 ; i < n ; i++) {
    if (strcmp(airports[i].typeOfAirport, "large_airport")==0) {
      printAirport(&airports[i]);
    }
  }

  printf("\n");

  printf ("Airport sorted by Name:\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf ("Airport sorted by Name Descending:\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf ("Airport sorted by Country-City:\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf("Printing airports in New York:\n");

  int y = 0; // variable to keep check of number of airports in new york found

  for (int i = 0 ; i < n ; i++) {
    if (strcmp(airports[i].city, "New York") == 0) {
      printAirport(&airports[i]);
      y++;
    } 
  } 

    // if no airports found print an appropriate message
    if (y == 0) {
      printf("No Airports in New York!\n");
    }

  printf("\n");

  printf("Printing airports in Canada:\n");
 
  int x = 0; // variable to keep check of number of airports in canada found
 
  for (int i = 0 ; i < n ; i++) {
    if (strncmp(airports[i].country, "CA", 2) == 0) {
      printAirport(&airports[i]);
      x++;
    }
  } 

    // if no airports found print an appropriate message
    if (x == 0) {
      printf("No Airports in Canada!\n");
    }

  printf("\n");

  printf ("Airports sorted by Latitude:\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf ("Airports sorted by Longitude:\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }

  printf("\n");

  printf("Geographic Median Longitude Airport:\n");
  if (n % 2 == 0) {
  printAirport(&airports[(n/2)-1]); // print airport at n/2 index because array is sorted by longitudes
  } else {
  printAirport(&airports[(n/2)]); // no need for -1 now because it is automatically truncated when converted to int
  }

  printf("\n");

  printf ("Airports sorted by Lincoln Distance:\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  for (int i = 0 ; i < n ; i++) {
    printAirport(&airports[i]);
  }
  
  printf("\n");

  printf("Airport closest to Lincoln:\n");
  printAirport(&airports[0]); // print first airport because array is sorted by distance from lincoln

  printf("\n");

  return;
}