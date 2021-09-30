/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 10, 2018
  *
  * This is a tester file for Hack 8
  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

int main (void) {

  char message1 [] = "Hello World, how are you?";
  int length1      = strlen (message1);

  char message2 [] = "This is my Hack 8";
  int length2      = strlen (message2);

  char message3 [] = "Today is October 10";
  int length3      = strlen (message3);

  char *newString1Remove  = removeCharCopy  (message1 , 'o');
  char *newString1Replace = replaceCharCopy (message1 , 'o' , 'i');
  char **stringSplit1     = lengthSplit     (message1 , 3);

  printf ("String 1: %s\n", message1);
  printf ("Removed copy (o) is: %s\n", newString1Remove);
  printf ("Replaced copy (o with i) is: %s\n", newString1Replace);
  printf ("Split String (3) is: \n");
  for (int i = 0 ; i < (length1/3)+1 ; i++) {
   printf ("{%s}", stringSplit1[i]);
 } printf ("\n\n");

  char *newString2Remove  = removeCharCopy  (message2 , 'i');
  char *newString2Replace = replaceCharCopy (message2 , 'i' , 'v');
  char **stringSplit2     = lengthSplit     (message2 , 4);

  printf ("String 2: %s\n", message2);
  printf ("Removed copy (i) is: %s\n", newString2Remove);
  printf ("Replaced copy (i with v) is: %s\n", newString2Replace);
  printf ("Split String (4) is: \n");
  for (int i = 0 ; i < (length2/4)+1 ; i++) {
   printf ("{%s}", stringSplit2[i]);
 } printf ("\n\n");

  char *newString3Remove  = removeCharCopy  (message3 , 'a');
  char *newString3Replace = replaceCharCopy (message3 , 'a' , 'e');
  char **stringSplit3     = lengthSplit     (message3 , 5);

  printf ("String 3: %s\n", message3);
  printf ("Removed copy (a) is: %s\n", newString3Remove);
  printf ("Replaced copy (a with e) is: %s\n", newString3Replace);
  printf ("Split String (5) is: \n");
  for (int i = 0 ; i < (length3/5)+1 ; i++) {
   printf ("{%s}", stringSplit3[i]);
 } printf ("\n\n");

}
