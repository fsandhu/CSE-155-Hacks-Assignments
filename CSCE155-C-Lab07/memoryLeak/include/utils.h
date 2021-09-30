

/**
 * Generates a random array of integers of the given
 * size.  This function assumes that the random number
 * generator has already been seeded.
 */
int * generateRandomArray(int size);

/**
 * Finds the median of the given array, returning
 * the value of the median element.
 */
int findMedian(const int *array, int size);

/**
 * Returns a deep copy of the given array.
 */
int * deepCopy(const int *array, int size);

/**
 * Sorts the given array of integers using the
 * slow selection sort algorithm
 */
void selectionSort(int *a, int size);
