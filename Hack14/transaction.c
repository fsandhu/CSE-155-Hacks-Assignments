/**
 * Author: Fateh Karan Singh Sandhu
 * Date: November 29, 2018
 * 
 * This file contains function code for hack 14
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include "transaction.h"

char* initString (const char* string1) {
    if (string1 == NULL) {
        return NULL;
    }
   // allocate new string
   char* string = (char*) malloc (sizeof(char) * strlen(string1)+1);
   strcpy (string, string1); // copy
   return string;
}

void initTransaction  (transaction *transaction,
                       const char* uid,
                       const char* typeOfTransaction,
                       double amountOfTransaction,
                       const char *customerAccountNumber,
                       double customerBalanceBefore,
                       double customerBalanceAfter,
                       char *transferAccountNumber) {
  
  transaction->uid = initString (uid);
  transaction->typeOfTransaction = initString (typeOfTransaction);
  transaction->customerAccountNumber = initString(customerAccountNumber);
  transaction->transferAccountNumber = initString(transferAccountNumber);

  transaction->amountOfTransaction = amountOfTransaction;
  transaction->customerBalanceBefore = customerBalanceBefore;
  transaction->customerBalanceAfter = customerBalanceAfter;

  return;
}

transaction* createTransaction (const char* uid,
                                const char* typeOfTransaction,
                                double amountOfTransaction,
                                const char *customerAccountNumber,
                                double customerBalanceBefore,
                                double customerBalanceAfter,
                                char *transferAccountNumber) {

  transaction *transaction1 = (transaction*) malloc (sizeof(transaction) * 1); //dynamic allocation

  initTransaction (transaction1, uid, typeOfTransaction, amountOfTransaction, 
                   customerAccountNumber, customerBalanceBefore, 
                   customerBalanceAfter, transferAccountNumber);

  return transaction1; 
}

void transactionReport (char *filePath) {
    if (filePath == NULL) {
        return;
    }
    FILE *transactionFile = fopen (filePath, "r"); //open file
    char buffer[1000]; //temp buffer
    fgets(buffer, 1000, transactionFile);
    int numberOfTransactions = atoi(buffer); //count number of transactions from the first line for loop

    //transaction *transactions = (transaction*) malloc (sizeof(transaction) * numberOfTransactions);
    
    int paymentCount = 0;
    int transferCount = 0;
    int withdrawalCount = 0;
    int debitCount = 0;
    int depositCount = 0;
    double paymentTotal = 0;
    double transferTotal = 0;
    double withdrawalTotal = 0;
    double debitTotal = 0;
    double depositTotal = 0;
    for (int i = 0; i < numberOfTransactions; i++) {
        fgets(buffer, 1000, transactionFile); //read by line
        char *uid = strtok (buffer, ","); //tokenize
        char *typeOfTransaction = strtok (NULL, ","); //tokenize
        double amountOfTransaction = atof (strtok (NULL, ",")); //tokenize
        char *customerAccountNumber = strtok (NULL, ","); //tokenize
        double balanceBefore = atof (strtok (NULL, ",")); //tokenize
        double balanceAfter = atof(strtok (NULL, ",")); //tokenize
        char *transferAccountNumber = strtok (NULL, ","); //tokenize

        //create new transaction structure

        transaction* t = createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                           customerAccountNumber, balanceBefore, balanceAfter, 
                                           transferAccountNumber);
        
        // check for type of transaction and increment following type

        if (strcmp(t->typeOfTransaction, "PAYMENT") == 0) {
            paymentCount ++;
            paymentTotal += t->amountOfTransaction;
        } else if (strcmp(t->typeOfTransaction, "TRANSFER") == 0) {
            transferCount ++;
            transferTotal += t->amountOfTransaction;
        } else if (strcmp(t->typeOfTransaction, "WITHDRAWAL") == 0) {
            withdrawalCount ++;
            withdrawalTotal += t->amountOfTransaction;
        } else if (strcmp(t->typeOfTransaction, "DEPOSIT") == 0) {
            depositCount ++;
            depositTotal += t->amountOfTransaction;
        } else if (strcmp(t->typeOfTransaction, "DEBIT") == 0) {
            debitCount ++;
            debitTotal += t->amountOfTransaction;
        }
    }

    double total = paymentTotal + transferTotal + withdrawalTotal + depositTotal + debitTotal; //count total transaction
    int totalCount = paymentCount + transferCount + withdrawalCount + depositCount + debitCount; //total count
    
    // print report

    printf ("==========================================================================\n");
    printf ("TOTALS REPORT :\n");
    printf ("==========================================================================\n");
    printf ("Type        \t\t\t  Count\t\t\t\tTotal\n");
    printf ("==========================================================================\n");
    printf ("Payment     :\t\t\t%7d\t\t\t$%15.2f\n", paymentCount, paymentTotal);
    printf ("Transfer    :\t\t\t%7d\t\t\t$%15.2f\n", transferCount, transferTotal);
    printf ("Withdrawal  :\t\t\t%7d\t\t\t$%15.2f\n", withdrawalCount, withdrawalTotal);
    printf ("Debit       :\t\t\t%7d\t\t\t$%15.2f\n", debitCount, debitTotal);
    printf ("Deposit     :\t\t\t%7d\t\t\t$%15.2f\n", depositCount, depositTotal);
    printf ("==========================================================================\n");
    printf ("Total       :\t\t\t%7d\t\t\t$%15.2f\n", totalCount, total);
    printf ("==========================================================================\n");

    fclose(transactionFile); //close file

    return;
    }