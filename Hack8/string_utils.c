/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 10, 2018
  *
  * This is a source file containing function code
  * for Hack 8.
  */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

void replaceChar(char *s, char oldChar, char newChar) {

  int length = strlen (s); // find length
  int i = 0;
  for (i = 0 ; i < length ; i++) {
    if (s[i] == oldChar) {
      s[i] = newChar; //replace char with new char
    }
  } s[length] = '\0'; // null terminate the string
}

char * replaceCharCopy(const char *s, char oldChar, char newChar) {

  int length = strlen(s); // find length

  // initialize new copy

  char * newCopy = (char *) malloc (sizeof(char) * (length+1));

  strcpy (newCopy, s); // copy string elements

  // reuse old function

  replaceChar (newCopy, oldChar, newChar);

  return newCopy;
}

void removeChar(char *s, char c) {

  int length = strlen (s); // find length
  int i = 0;
  int j = 0;
  int numberOfTimes = 0; // variable to track number of times char is removed
  for (i = 0 ; i < length ; i++) {
    if (s[i] == c) {
       for (j = i ; j < length ; j++) {
         s[j] = s[j+1]; // set all elements 1 back
        } numberOfTimes++;
          i--; // recheck again if same char is together
    }
  } length = length - numberOfTimes;
    s[length] = '\0';
    return;
}

char * removeCharCopy(const char *s, char c) {

  int length = strlen(s); // find length

  // initialize new copy

  char *newCopy = (char *) malloc (sizeof(char) * (length+1) );

  strcpy (newCopy, s); // copy all string elements

  removeChar (newCopy, c); // reuse old function

  return newCopy;
}

char **lengthSplit(const char *s, int n) {

  int length = strlen(s); // find length

  // deep copy

  char **newCopy = NULL;
  newCopy = (char **) malloc ( sizeof(char *) *  ceil ( (double) length / n )  );

  int i = 0;
  for (i = 0 ; i < ceil ( (double) length/n)  ; i++) {
     newCopy[i] = (char *) malloc (sizeof(char) * n );

     strncpy (newCopy[i], &s[i*n], n); // fill with substring at each instance of n

     newCopy[i][n] = '\0'; // null terminate the new substring
   }
   return newCopy;
}
