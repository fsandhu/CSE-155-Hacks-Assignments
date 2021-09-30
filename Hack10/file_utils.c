/**
  * Author: Fateh Karan Singh Sandhu & SungHa Park
  * Date: October 25, 2018
  *
  * This file contains function code
  */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *getFileContents(const char *filePath) {
  
   if (filePath == NULL) {
    return NULL;
  }

  FILE *input = fopen (filePath, "r"); // open file

  char c;
  int counter = 0; // set a counter
  c = fgetc (input); // check character
  // if there is nothing in file, counter is zero
  if (c == EOF) {
     counter = 0;
  } else {
    counter = 1;
  }

  // iterate over file to number of characters

  while (fgetc (input) != EOF) {
    counter++;
  }

  fclose(input); // close file

  input = fopen (filePath, "r"); // open again to start from beginning

  char *result = (char *) malloc (sizeof(char) * counter+1); // initialize new string
  char buffer[1000]; // temp buffer
  char *s = fgets (buffer, 1000, input); // read each line
  result[0] = '\0'; // set the first to null terminating so that strcat works
  while (s != NULL) {
    strcat(result, buffer); // fill the new string
    s = fgets (buffer, 1000, input);
  }

  fclose(input); // close file

  return result;
}

char **getFileLines(const char *filePath, int *numLines) {

  if (filePath == NULL) {
    return NULL;
  }

  FILE *input = fopen (filePath, "r"); // open file

  char buffer[1000]; // temp buffer
  int counter; // set counter
  char *s = fgets(buffer, 1000, input);
  if (s == NULL) {
    counter = 0;
  } else {
    counter = 1;
  }

  while (fgets(buffer, 1000, input) != NULL) {
  counter++; // find num of lines
  }

  *numLines = counter; // find num of lines

  fclose(input); // close file

  input = fopen (filePath, "r");

  int i = 0;

  // dynamically allocate multidimensional array

  char **result = NULL;
  result = (char **) malloc (sizeof(char*) * (*numLines));
  for (int i = 0 ; i < *numLines ; i++) {
  result[i] = (char *) malloc (sizeof(char) * 1000);
  }

  char *x = fgets (buffer, 1000, input);
  i = 0;

  while (x != NULL) {
    buffer[strlen(buffer)-1] = '\0'; // chomp endline character
    strcpy (result[i], buffer); // copy into array at i
    i++;
    x = fgets (buffer, 1000, input);
  }

  fclose(input); // close file

  return result;
}
