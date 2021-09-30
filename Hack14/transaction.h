/**
 * Author: Fateh Karan Singh Sandhu
 * Date: November 29, 2018
 * 
 * This file contains function prototypes for hack 14
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
} transaction;

/**
 * This function initializes a new string by
 * copying the given string into it.
 */
char* initString (const char* string1);

/**
 * This function initializes an existing allocated
 * transaction structure.
 */
void initTransaction (transaction *transaction,
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
transaction* createTransaction (const char* uid,
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
