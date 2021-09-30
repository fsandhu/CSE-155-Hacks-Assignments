
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function should return true if the given (sub)string is
 * a palindrome.  The function should be recursive.
 */
int isPalindrome(const char *str, int left_index, int right_index);
void suffixSTR (char *s, int i);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: isPalindrome word\n");
    exit(1);
  }

  //int isPal = isPalindrome(argv[1], 0, strlen(argv[1]) - 1);
  //if (isPal) {
   // printf("%s is a palindrome!\n", argv[1]);
  //} else {
   // printf("%s is NOT a palindrome!\n", argv[1]);
  //}
  suffixSTR(argv[1], 0);
  return 0;
}

int isPalindrome(const char *str, int left_index, int right_index) {
  // TODO: implement this function as specified, DONE MF
  if(left_index >= right_index ) {
    return 1;
  } else {
     if (str[left_index] == str[right_index]) {
       isPalindrome(str, left_index+1, right_index-1); //left+1 because it's increasing and right-1 to decrease 
      } else if (str[left_index] != str[right_index]) {
       return 0;
        }
    }
}


// you need i as a parameter for loop like recursive functions 
void suffixSTR (char *s, int i) {
  if (i < strlen(s)) {
  printf ("%s\n", &s[i]);
  i++; } else {
    return;
  }
  suffixSTR (s, i);
  return;
}
