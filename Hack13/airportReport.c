#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

#include "airport.h"

int main (int argc, char **argv) {
  
  // create a new array of airports of size 5 for AD-HOC testing
  int n = 5;
  Airport *arrayOfAirports = (Airport *) malloc (sizeof(Airport) * n);
  
  arrayOfAirports[0] = *createAirport ("jfk001" , "large_airport" , "JFK" , 40.6413, -73.7781, 339, "New York" , "USA");
  arrayOfAirports[1] = *createAirport ("lax2" , "large_airport" , "LAX" , 33.9416, -118.4085, 591, "Los Angeles" , "USA"); 
  arrayOfAirports[2] = *createAirport ("yvz19" , "medium_airport" , "YYZ" , 43.6777, -79.6248, 1221, "Toronto" , "CA");
  arrayOfAirports[3] = *createAirport ("ohare19" , "large_airport" , "ORD" , 41.9742, -87.9073, 900, "Chicago" , "USA");
  arrayOfAirports[4] = *createAirport ("igi19" , "small_airport" , "DEL" , 28.5562, 167.1000, 051, "New Delhi" , "IND");

  generateReports(arrayOfAirports, n);

    return 0;
}