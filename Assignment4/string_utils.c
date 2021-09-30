/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 20, 2018
  *
  * This is the source code for the functions
  * on Assignment 4
  */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int strContains(const char *str, const char *subStr) {
  // NULL Pointer check
  if (str == NULL || subStr == NULL) {
    return 0;
  }
  int length = strlen (str); // find length of input string
  int lengthSubStr = strlen(subStr); // find length of substring
  // run a loop that ends at length and only compares until lengthSubStr
  for (int i = 0 ; i < (length+1)-lengthSubStr ; i++) {
    if (strncmp(&str[i], subStr, lengthSubStr) == 0) {
      return 1; // if the string contains the substring
    }
  } return 0; // if the substring is not in the string
}

char *concatenate(const char *s, const char *t) {
   int lengthS = strlen(s); // find length of string s
   int lengthT = strlen(t); // find length of string t
   int newLength = lengthS + lengthT; // variable to track size of new string

   // length error check
    if (newLength <= 0) {
     return NULL;
    }

   // NULL Pointer check
   if (s == NULL || t == NULL) {
     return NULL;
    }

   char *newString = (char *) malloc (sizeof(char) * newLength+1); // plus 1 to accomodate the \0

   strcpy(newString, s); // copy first string into new string
   strcat(newString, t); // copy second string into new string

   newString[newLength] = '\0'; // properly null terminate this new string

   return newString; // return new concatenated string
}

char *append(const char *s, const char *t) {
   // NULL Pointer check
   if (s == NULL || t == NULL) {
     return NULL;
   }
   char *appendedString = concatenate(s, t); // reuse function
   return appendedString; //return new appended string
}

char *prepend(const char *s, const char *t) {
   // NULL Pointer check
   if (s == NULL || t == NULL) {
     return NULL;
   }
   char *prependedString = concatenate(t, s); // reuse function
   return prependedString; // return new prepended string
}

char *substringToEnd(const char *s, int beginningIndex) {
   // check beginningIndex error
   if(beginningIndex < 0) {
     return NULL;
   }
   // NULL Pointer check
   if (s == NULL) {
     return NULL;
   }
   int length = strlen(s) - beginningIndex; // find length for new string
   char *newSubString = (char *) malloc (sizeof(char) * length+1); // allocate new string
   strcpy(newSubString, &s[beginningIndex]); // copy
   newSubString[length] = '\0'; // null terminate the new string
   return newSubString; // return
}

char *substringIndex(const char *s, int beginIndex, int endIndex) {
   int size = endIndex - beginIndex; // determine size
   //check size error
   if(size < 0) {
     return NULL;
   }
   // NULL Pointer check
   if (s == NULL) {
     return NULL;
   }
   char *subString = (char *) malloc (sizeof(char) * size+1); // allocate new string
   strncpy(subString, &s[beginIndex], size); // copy
   subString[size] = '\0'; // null terminate the substring that is to be returned
   return subString;
}

char *substringSize(const char *s, int beginningIndex, int size) {
   //check size error
   if(size < 0) {
     return NULL;
   }
   // NULL Pointer check
   if (s == NULL) {
     return NULL;
   }
   char *subString = (char *) malloc (sizeof(char) * size+1); // allocate new string
   strncpy(subString, &s[beginningIndex], size); // copy
   subString[size] = '\0'; // null terminate the substring that is to be returned
   return subString;
}