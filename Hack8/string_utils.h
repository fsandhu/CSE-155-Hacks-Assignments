/**
  * Author: Fateh Karan Singh Sandhu & SungHa Park
  * Date: October 10, 2018
  *
  * This is a prototype file for Hack8.
  */

// this function removes instances of char oldChar and
// replaces it with a new char newChar

void replaceChar(char *s, char oldChar, char newChar);

// this function removes instances of char oldChar and
// replaces it with a new char newChar but creates a new copy

char * replaceCharCopy(const char *s, char oldChar, char newChar);

// this function removes instances of a char from an array

void removeChar(char *s, char c);

// this function removes instances of a char from an array
// but creates a new copy

char * removeCharCopy(const char *s, char c);

// this function splits and array into many char arrays
// split at instances of n

char **lengthSplit(const char *s, int n);
