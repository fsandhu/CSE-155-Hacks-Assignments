/**
  * Author: Fateh Karan Singh Sandhu
  * Collaborators: Saurav Pradhan, Saurav Kushwaha
  * Date: November 15, 2018
  * 
  * This file contains function headings
 **/

/**
 * Structure defining an airport
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
 * cmputes the air distance, in kilometers, between
 * the two Airports using their latitude/longitude
 */
double getAirDistance(const Airport* origin, const Airport* destination);

/**
 * cmputes the estimated travel time (in hours) for a flight
 * that involves the given stops using the average flight speed
 * (kilometers per hour) and average layover time (in hours)
 */
double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs);

/**
 * A comparator function that orders the two Airport structures by
 * their GPS IDs in lexicographic order.
 */
int cmpByGPSId(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their type.
 */
int cmpByType(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their name in lexicographic order.
 */
int cmpByName(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their name in reverse lexicographic order.
 */
int cmpByNameDesc(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures first by
 * country, then by city
 */
int cmpByCountryCity(const void* a, const void* b);

/**
 * A comparator function that orders the given Airport structures
 * by their latitudes north to south
 */
int cmpByLatitude(const void* a, const void* b);

/**
 * A comparator function that orders the given Airport structures
 * by their longitudes west to east
 */
int cmpByLongitude(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their relative distance from Lincoln Municipal Airport
 * (0R2, 40.846176, -96.75471)
 * in ascending order according (closest to Lincoln would come first)
 */
int cmpByLincolnDistance(const void* a, const void* b);

/**
 * A function that generates and prints several reports on the
 * given array of Airport structures.
 */
void generateReports(Airport *airports, int n);

/**
 * This function converts input degrees to radians.
 */
double degreesToRadians (double degree);

/**
 * This function computes the air distance between
 * two given latitudes and longitudes.
 */
double getAirDistanceFunction  (double latA, double longA,
                                double latB, double longB);

/**
 * This function initializes a new string by
 * copying the given string into it.
 */
char* initString (const char* string1);

/**
 * This function prints the passed in airport.
 */
void printAirport (const Airport* a);