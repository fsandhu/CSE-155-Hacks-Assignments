/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 23, 2018
  *
  * This is the part 2 of assignment 4.
  * It takes instances of some characters from
  * input file and replaces them in a new output
  * file.
  */

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv) {

  // error checking

  if (argc != 3) {
    printf("Usage: %s, input file, output file", argv[0]);
  }

  char *inputPath  = argv[1]; // create new string for input
  char *outputPath = argv[2]; // create new string for output

  FILE *input  = fopen(inputPath, "r"); // open file for input
  FILE *output = fopen(outputPath, "w"); // open file for output

  // NULL Pointer check
  if (input == NULL || output == NULL) {
      printf("Error: Invalid Input or Output Path\n");
      exit(1);
  }

  char c;
  c = fgetc(input); // read file by character

  //replace within loop

  while (c != EOF) {
    if (c == '&') {
      fprintf(output, "&amp;");
    } else if (c == '<') {
      fprintf(output, "&lt;");
    } else if (c == '>') {
      fprintf(output, "&gt;");
    } else if (c == '"') {
      fprintf(output, "&quot;");
    } else {
      fprintf(output, "%c", c);
    }
    c = fgetc(input);
  }

  fclose(input); // close file
  fclose(output); // close file

  return 0;
}
