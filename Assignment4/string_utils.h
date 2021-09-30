/**
  * Author: Fateh Karan Singh Sandhu
  * Date: October 20, 2018
  *
  * This is the prototype file for the Assignment 4
  * part 1 program containing different functions.
  */


/**
  * This function checks if a string contains a
  * a certain substring and returns 1 if true and 0
  * if false
  */

  int strContains(const char *str, const char *subStr);

/**
  * This function takes two strings and concatenates
  * them toghther into a new string
  */

  char *concatenate(const char *s, const char *t);

/**
  * This function takes in two strings and
  * appends t to the end of s
  */

  char *append(const char *s, const char *t);

/**
  * This function takes in two strings and
  * prepends t to s
  */

  char *prepend(const char *s, const char *t);

/**
  * This function takes a string and returns a
  * new copy of a substring of it starting from a
  * speciﬁed index to the end of the string.
  */

  char *substringToEnd(const char *s, int beginningIndex);

/**
  * This function takes a string and returns a
  * new copy of a substring of it starting from a
  * speciﬁed index (inclusive) and going a speciﬁed
  * ending index (exclusive).
  */

  char *substringIndex(const char *s, int beginIndex, int endIndex);

/**
  * This function that takes a string and returns a new copy
  * of a substring of it starting from a speciﬁed index
  * of a particular size.
  */

  char *substringSize(const char *s, int beginningIndex, int size);
