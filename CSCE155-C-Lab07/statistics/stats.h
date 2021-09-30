
/**
 * This function prompts and reads in a collection of numbers
 * from the standard input and populates the given array.  The
 * provided array must be properly initialized for this function
 * to work.
 */
void readInArray(int *arr, int size);

/**
 * Generates a random array of integers of the given
 * size.  This function assumes that the random number
 * generator has already been seeded.
 */
int * generateRandomArray(int size);

/**
 * Prints the given array to the standard output
 */
void printArray(const int *arr, int size);

/*
 * TODO:
 *  1. Write prototypes for each of these functions
 *  2. Write documentation for each of these functions
 *  3. Implement the functions in stats.c
 */
double getMean(int *arr, int size);

int getMin(int *arr, int size);

int getMax(int *arr, int size);
