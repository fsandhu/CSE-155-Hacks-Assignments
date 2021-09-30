/**
 * Uses ODBC to establish a connection to a mySQL database
 * filled with various game information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

#include "games.h"
#include "odbc_utils.h"
#include "databaseInfo.h"

int main(int argc, char** argv) {
  int i;

  // Each stores various information about the connection
  SQLHANDLE sqlenvhandle;
  SQLHANDLE sqlconnectionhandle;
  SQLHANDLE sqlstatementhandle;

  // String to store info that will be used to connect
  char* connectionInfo;

  // Create the string containing information about the database connection
  asprintf(&connectionInfo,
           "DRIVER={%s};SERVER=%s;"
           "PORT=%s;DATABASE=%s;UID=%s;PWD=%s;",
           driver, server, port, database, userID, password);

  // Connect to the DB.  Exit if there's a problem.
  if (!setupConnection(&sqlenvhandle, &sqlconnectionhandle, &sqlstatementhandle,
                       connectionInfo)) {
    // Cleans up the connection before exiting
    finishConnection(sqlenvhandle, sqlstatementhandle, sqlconnectionhandle);
    return -1;
  }

  // at this point, we have our sql connection handle; we can use it in the
  // games API...

  addVideoGame("Pac Man's Revenge", 12345678, sqlstatementhandle);
  extractError("", sqlstatementhandle, SQL_HANDLE_STMT);


  // TODO: 1. Define string variables to hold your game's name, publisher,
  // platform

  char *name = "PUBG";
  char *publisher = "Bluehole";
  char *platform = "PC";
  int publishedYear = 2017;
  // TODO: 2. Check that your game does not already exist, quit if it does

  VideoGame *PUBG = getGame ("PUBG", sqlstatementhandle);

  if (PUBG != NULL) {
     exit(1);
  }

  // TODO: 3. Check that a record for your publisher doesn't already exist,
  //         if it does use it, otherwise add it

  Publisher *Bluehole = getPublisher ("Bluehole", sqlstatementhandle);

  if (Bluehole == NULL) {
    addPublisher ("Bluehole", sqlstatementhandle);
    Bluehole = getPublisher ("Bluehole", sqlstatementhandle);
  } 
  
  // TODO: 4. Check that a record for your platform doesn't already exist,
  //         if it does use it, otherwise add it

  Platform *PC = getPlatform ("PC", sqlstatementhandle);

  if (PC == NULL) {
    addPlatform ("PC", sqlstatementhandle);
    PC = getPlatform ("PC", sqlstatementhandle);
  } 

  // TODO: 5. Add the video game to the database

  addVideoGame ("PUBG", Bluehole->id, sqlstatementhandle);

  // TODO: 6. Load the game from the database

  PUBG = getGame ("PUBG", sqlstatementhandle);

  // TODO: 7. Associate your game with the platform with a particular release
  // year

  addAvailability (PUBG->id, PC->id, publishedYear, sqlstatementhandle);

  // Cleans up connection before exiting
  finishConnection(sqlenvhandle, sqlstatementhandle, sqlconnectionhandle);
}
