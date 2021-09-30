/**
  * Author: Fateh Karan Singh Sandhu & SungHa Park
  * Date: October 24, 2018
  *
  * This is the prototype file for Hack 10
  * containing function definitions
  */

/**
  * This function returns elements of a
  * file in a single line
  */

char *getFileContents(const char *filePath);


/**
  * This function returns elements of a file
  * corresponding line to line and chomps out any
  * endline characters.
  */

  char **getFileLines(const char *filePath, int *numLines);
