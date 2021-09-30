/**
 * Author: Fateh Karan Singh Sandhu & SungHa Park
 * Date: October 26, 2018
 * 
 * This program converts DNA from a file
 * to protein and places it in a new input
 * file taking both input and output path
 * as command line arguments.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "protein_utils.h"
#include "file_utils.h"

void removeChar(char *s, char c); // reuse old function
char **lengthSplit(const char *s, int n, int *size); // reuse
void replaceChar(char *s, char oldChar, char newChar); // reuse

int main (int argc, char **argv) {

  // argument count error check

  if (argc != 3) {
    printf("Error: provide input and out\n");
    exit(1);
  }

  char *inputPath = argv[1]; // create a string for input path
  char *outputPath = argv[2]; // create a string for output path

  FILE *output = fopen (outputPath, "w"); // open file for output

  char *stringDNA = getFileContents (inputPath);

    replaceChar(stringDNA, 'T', 'U'); // convert DNA to RNA by replacing T with U
    removeChar(stringDNA, ' '); // remove whitespace
    removeChar(stringDNA, '\n'); // remove endline characters
    int size = 0;
    char **splittedBuffer = lengthSplit(stringDNA, 3, &size); // split buffer at 3
      for(int j = 0 ; j < size ; j++) {
       char amino = rnaToProtein (splittedBuffer[j]); // convert to protein
        if(amino == 'x') {
         break; // premature end
        } else {
           fprintf(output, "%c", amino); // print to output file
          }
      }

  return 0;
}

void removeChar(char *s, char c) {
  // NULL Pointer Check
  if (s == NULL) {
    return;
  }
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

char **lengthSplit(const char *s, int n, int *size) {
  // NULL Pointer Check
  if (s == NULL || size == NULL) {
    return NULL;
  }
  int length = strlen(s); // find length
  // deep copy
  char **newCopy = NULL;
  newCopy = (char **) malloc (sizeof(char *) *  ceil ((double) length/n));
  int i = 0;
  *size = ceil ( (double) length/n); // pass by refrence to find size
  for (i = 0 ; i < *size  ; i++) {
     newCopy[i] = (char *) malloc (sizeof(char) * n );
     strncpy (newCopy[i], &s[i*n], n); // fill with substring at each instance of n
     newCopy[i][n] = '\0'; // null terminate the new substring
   }
   return newCopy;
}

void replaceChar(char *s, char oldChar, char newChar) {
  // NULL Pointer Check
  if (s == NULL) {
    return;
  }
  int length = strlen (s); // find length
  int i = 0;
  for (i = 0 ; i < length ; i++) {
    if (s[i] == oldChar) {
      s[i] = newChar; //replace char with new char
    }
  } s[length] = '\0'; // null terminate the string
}