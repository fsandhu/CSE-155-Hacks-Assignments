/**
 * Author: Fateh Karan Singh Sandhu
 * Date: November 29, 2018
 * 
 * This file contains function prototypes for Assignment 5
 */

/**
 * Structure definition for Transaction
 */
typedef struct {
  char *uid;
  char *typeOfTransaction;
  double amountOfTransaction;
  char *customerAccountNumber;
  double customerBalanceBefore;
  double customerBalanceAfter;
  char *transferAccountNumber;
} Transaction;

/**
 * This function initializes a new string by
 * copying the given string into it.
 */
char* initString (const char* string1);

/**
 * This function initializes an existing allocated
 * transaction structure.
 */
void initTransaction (Transaction *transaction,
                       const char* uid,
                       const char* typeOfTransaction,
                       double amountOfTransaction,
                       const char *customerAccountNumber,
                       double customerBalanceBefore,
                       double customerBalanceAfter,
                       char *transferAccountNumber);

/**
 * This function creates a new transaction structure
 */
Transaction* createTransaction (const char* uid,
                                const char* typeOfTransaction,
                                double amountOfTransaction,
                                const char *customerAccountNumber,
                                double customerBalanceBefore,
                                double customerBalanceAfter,
                                char *transferAccountNumber);

/**
 * This function prints a report of a transaction
 * file
 */
void transactionReport (char *filePath);

/**
 * This function prints out a passed in 
 * transaction structure.
 */
void printTransaction (Transaction* t);

/**
 * This function validates the data in a transaction
 * array by checking amount before and after
 * the transaction
 */
void validateData (char *filePath);

/**
 * This function checks all the deposit where
 * they approach or exceed $10,000
 */
void checkLimit (char* filePath);

/**
 * Comparator function by transaction amount.
 */
int compareByTransactionAmount (const void *a, const void *b);

/**
 * This function checks transaction file for
 * all repeated transactions.
 */
void checkRepeatedTransactions (char* filePath);

/**
 * This function prints out a 
 * Benford analysis of a transaction file.
 */
void benfordAnalysis (char* filePath);

/**
 * Comparator function by UUID.
 */
int compareByUUID (const void *a, const void *b);

/**
 * This function compares two transaction files for inconsistencies.
 */
void findDataAnomalies (char* filePath1, char* filePath2);