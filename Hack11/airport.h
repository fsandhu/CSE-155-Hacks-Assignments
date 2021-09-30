/**
  * Author: Fateh Karan Singh Sandhu
  * Collaborators: Saurav Pradhan, Saurav Kushwaha
  * Date: October 30, 2018
  * 
  * This file contains function headings
 **/

/**
 * Define a structure for airport
 */
typedef struct {
    char *gpsID;
    char *nameOfAirport;
    char *typeOfAirport;
    char *city;
    char *country;
    double latitude;
    double longitude;
    int elevation;
} Airport;

/**
 * A factory function to create a new Airport with the given
 * attributes.  This function should make *deep* copies of each
 * of the relevant fields and return a pointer to the newly
 * created Airport structure.
 */
Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv);

/**
 * This function initializes an existing allocated
 * Airport structure with the given attributes.
 */
void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv);

/**
 * Constructs a new string representation of the given
 * Airport structure.
 */
char* airportToString(const Airport* a);

/**
 * Computes the air distance, in kilometers, between
 * the two Airports using their latitude/longitude
 */
double getAirDistance(const Airport* origin, const Airport* destination);

/**
 * Computes the estimated travel time (in hours) for a flight
 * that involves the given stops using the average flight speed
 * (kilometers per hour) and average layover time (in hours)
 */
double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs);

/**
 *  This function converts degrees into radians.
 */
double degreesToRadians (double degree);

/**
 * This function gives the air distance between
 * two places taking in their latitudes and 
 * longitudes
 */
double getAirDistanceFunction  (double latA, double longA,
                                double latB, double longB);

/**
 * This function initializes a new string
 */
char * initString (const char* string1);