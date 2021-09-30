/**
 * Author: Fateh Karan Singh Sandhu
 * Date: November 29, 2018
 * 
 * This file contains function code for assignment 5
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

void initTransaction  (Transaction *transaction,
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

Transaction* createTransaction (const char* uid,
                                const char* typeOfTransaction,
                                double amountOfTransaction,
                                const char *customerAccountNumber,
                                double customerBalanceBefore,
                                double customerBalanceAfter,
                                char *transferAccountNumber) {

  Transaction *transaction1 = (Transaction*) malloc (sizeof(Transaction) * 1); //dynamic allocation

  initTransaction (transaction1, uid, typeOfTransaction, amountOfTransaction, 
                   customerAccountNumber, customerBalanceBefore, 
                   customerBalanceAfter, transferAccountNumber);

  return transaction1; 
}

void transactionReport (char *filePath) {
    
    // NULL Pointer Check

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

        Transaction* t = createTransaction(uid, typeOfTransaction, amountOfTransaction, 
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

void printTransaction (Transaction* t) {
    printf("%s: %s -> %s", t->uid, t->customerAccountNumber, t->transferAccountNumber);
    printf("(%s) $%.2f : ($%.2f -> $%.2f)\n", t->typeOfTransaction, t->amountOfTransaction, t->customerBalanceBefore, t->customerBalanceAfter);
}

void validateData (char *filePath) {
    
    // NULL Pointer check

    if (filePath == NULL) {
        return;
    }

    FILE *transactionFile = fopen (filePath, "r"); //open file
    char buffer[1000]; //temp buffer
    fgets(buffer, 1000, transactionFile);
    int numberOfTransactions = atoi(buffer); //count number of transactions from the first line for loop
    Transaction* transactions = (Transaction*) malloc (sizeof(Transaction) * numberOfTransactions);
    
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

        transactions[i] = *createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                            customerAccountNumber, balanceBefore, balanceAfter, 
                                            transferAccountNumber); 
    }

        printf ("==================================\n");
        printf ("Balance Validation Report\n");
        printf ("==================================\n");

        int count = 0; // keep count of invalid balances

        // check all transactions inside the loop
        
        for (int i = 0 ; i < numberOfTransactions ; i++) {
            if (strcmp(transactions[i].typeOfTransaction, "DEPOSIT") == 0) {
              if (fabs(transactions[i].amountOfTransaction-(transactions[i].customerBalanceAfter-transactions[i].customerBalanceBefore)) > 0.001) {
                  printf("Invalid Transaction, off by $%.2f\n", fabs(transactions[i].amountOfTransaction-(transactions[i].customerBalanceAfter-transactions[i].customerBalanceBefore)));
                  printTransaction (&transactions[i]);
                  count++;
              } 
            } else {
                if (fabs(transactions[i].amountOfTransaction-(transactions[i].customerBalanceBefore-transactions[i].customerBalanceAfter)) > 0.001) {
                  printf("Invalid Transaction, off by $%.2f\n", fabs(transactions[i].amountOfTransaction-(transactions[i].customerBalanceBefore-transactions[i].customerBalanceAfter)));
                  printTransaction (&transactions[i]);
                  count++;
                }        
            }
        }

        printf("Number of invalid balances found: %d\n", count);

        free(transactions); // free array

        fclose(transactionFile); // close file

        return;
}

void checkLimit (char* filePath) {

    // NULL Pointer Check

    if (filePath == NULL) {
        return;
    }

    FILE *transactionFile = fopen (filePath, "r"); //open file
    char buffer[1000]; //temp buffer
    fgets(buffer, 1000, transactionFile);
    int numberOfTransactions = atoi(buffer); //count number of transactions from the first line for loop
    Transaction *transactions = (Transaction*) malloc (sizeof(Transaction) * numberOfTransactions);
    
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

        transactions[i] = *createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                            customerAccountNumber, balanceBefore, balanceAfter, 
                                            transferAccountNumber); 
    }

    int transactionAbove = 0;
    int transactionApproaching = 0;

    for (int i = 0 ; i < numberOfTransactions ; i++) {
        if (strcmp(transactions[i].typeOfTransaction, "DEPOSIT") == 0) {
          if (transactions[i].amountOfTransaction >= 10000) {
              transactionAbove++;
          } else if (transactions[i].amountOfTransaction >= 9900 && transactions[i].amountOfTransaction <= 9999.99) {
              transactionApproaching++;
          }
        }
    }
    
    printf ("==================================\n");
    printf ("Deposit Limit Report\n");
    printf ("==================================\n");
    printf ("Deposit exceeding 10k: %d\n", transactionAbove);
    printf ("Deposit approaching 10k: %d\n", transactionApproaching);

    free(transactions); // free array

    fclose(transactionFile); // close file
   
    return;
}

int compareByTransactionAmount (const void *a, const void *b) {
    const Transaction *x = (const Transaction *) a;
    const Transaction *y = (const Transaction *) b;

    if (x->amountOfTransaction < y->amountOfTransaction) {
        return -1;
    } else if (x->amountOfTransaction > y->amountOfTransaction) {
        return 1;
    } else {
        return 0;
    }
    
    return 0;
}

void checkRepeatedTransactions (char* filePath) {
    
    // NULL Pointer Check

    if (filePath == NULL) {
        return;
    }

    FILE *transactionFile = fopen (filePath, "r"); //open file
    char buffer[1000]; //temp buffer
    fgets(buffer, 1000, transactionFile);
    int numberOfTransactions = atoi(buffer); //count number of transactions from the first line for loop
    Transaction *transactions = (Transaction*) malloc (sizeof(Transaction) * numberOfTransactions);
    
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

        transactions[i] = *createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                            customerAccountNumber, balanceBefore, balanceAfter, 
                                            transferAccountNumber); 
    }

    qsort (transactions, numberOfTransactions, sizeof(Transaction), compareByTransactionAmount); // sort by amount

    int repeatedTransactions = 0;

    printf ("==================================\n");
    printf ("Repeated Transaction Report\n");
    printf ("==================================\n");

    for (int i = 0 ; i < numberOfTransactions ; i++) {
        if (transactions[i].amountOfTransaction == transactions[i+1].amountOfTransaction &&
        strcmp ((transactions[i].customerAccountNumber), (transactions[i+1]).customerAccountNumber)==0 &&
        strcmp ((transactions[i].transferAccountNumber), (transactions[i+1]).transferAccountNumber)==0) {
        repeatedTransactions++;
        printTransaction (&transactions[i]);
           while (transactions[i].amountOfTransaction == transactions[i+1].amountOfTransaction) {
               printTransaction(&transactions[i+1]);
               i++;
               repeatedTransactions++;
            }
        }
    }

     printf("Total repeated transactions flagged: %d\n", repeatedTransactions);

    free(transactions); // free array

    fclose(transactionFile); // close file

     return;
}

void benfordAnalysis (char* filePath) {
   
    // NULL Pointer Check

    if (filePath == NULL) {
        return;
    }

    FILE *transactionFile = fopen (filePath, "r"); //open file
    char buffer[1000]; //temp buffer
    fgets(buffer, 1000, transactionFile);
    int numberOfTransactions = atoi(buffer); //count number of transactions from the first line for loop
    Transaction *transactions = (Transaction*) malloc (sizeof(Transaction) * numberOfTransactions);
    
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

        transactions[i] = *createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                            customerAccountNumber, balanceBefore, balanceAfter, 
                                            transferAccountNumber); 
    }
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;

    for (int i = 0 ; i < numberOfTransactions ; i++) {
        char buff[1000];
        sprintf (buff, "%f", transactions[i].amountOfTransaction); // convert int to string to compare first number
        if (buff[0] == '1') {
            count1++;
        } else if (buff[0] == '2') {
            count2++;
        } else if (buff[0] == '3') {
            count3++;
        } else if (buff[0] == '4') {
            count4++;
        } else if (buff[0] == '5') {
            count5++;
        } else if (buff[0] == '6') {
            count6++;
        } else if (buff[0] == '7') {
            count7++;
        } else if (buff[0] == '8') {
            count8++;
        } else if (buff[0] == '9') {
            count9++;
        } 
    }

    double expectedFrequency1 = 0.30103;
    double expectedFrequency2 = 0.17609;
    double expectedFrequency3 = 0.12494;
    double expectedFrequency4 = 0.09691;
    double expectedFrequency5 = 0.07918;
    double expectedFrequency6 = 0.06695;
    double expectedFrequency7 = 0.05799;
    double expectedFrequency8 = 0.05115;
    double expectedFrequency9 = 0.04576;

    double actualFrequency1 = (double) count1 / numberOfTransactions;
    double actualFrequency2 = (double) count2 / numberOfTransactions;
    double actualFrequency3 = (double) count3 / numberOfTransactions;
    double actualFrequency4 = (double) count4 / numberOfTransactions;
    double actualFrequency5 = (double) count5 / numberOfTransactions;
    double actualFrequency6 = (double) count6 / numberOfTransactions;
    double actualFrequency7 = (double) count7 / numberOfTransactions;
    double actualFrequency8 = (double) count8 / numberOfTransactions;
    double actualFrequency9 = (double) count9 / numberOfTransactions;

    printf ("===========================================================================\n");
    printf ("Benford Analysis\n");
    printf ("===========================================================================\n");
    printf ("Number\t     Count\t\tFrequency\tExpected\tDifference\n");
    printf ("1  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count1, actualFrequency1, expectedFrequency1, actualFrequency1-expectedFrequency1);
    printf ("2  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count2, actualFrequency2, expectedFrequency2, actualFrequency2-expectedFrequency2);
    printf ("3  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count3, actualFrequency3, expectedFrequency3, actualFrequency3-expectedFrequency3);
    printf ("4  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count4, actualFrequency4, expectedFrequency4, actualFrequency4-expectedFrequency4);
    printf ("5  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count5, actualFrequency5, expectedFrequency5, actualFrequency5-expectedFrequency5);
    printf ("6  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count6, actualFrequency6, expectedFrequency6, actualFrequency6-expectedFrequency6);
    printf ("7  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count7, actualFrequency7, expectedFrequency7, actualFrequency7-expectedFrequency7);
    printf ("8  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count8, actualFrequency8, expectedFrequency8, actualFrequency8-expectedFrequency8);
    printf ("9  \t%9d\t\t%2.2f\t\t%1.3f\t\t%6.3f\n", count9, actualFrequency9, expectedFrequency9, actualFrequency9-expectedFrequency9);

    
    free(transactions); // free array

    fclose(transactionFile); // close file

    return;
}

int compareByUUID (const void *a, const void *b) {
    const Transaction *x = (const Transaction *) a;
    const Transaction *y = (const Transaction *) b;
    
    return strcmp(x->uid, y->uid);
}

void findDataAnomalies (char* filePath1, char* filePath2) {

    // NULL Pointer Check

    if (filePath1 == NULL) {
        return;
    }

    FILE *transactionFile1 = fopen (filePath1, "r"); //open file
    char buffer1[1000]; //temp buffer
    fgets(buffer1, 1000, transactionFile1);
    int numberOfTransactions1 = atoi(buffer1); //count number of transactions from the first line for loop
    Transaction *transactions1 = (Transaction*) malloc (sizeof(Transaction) * numberOfTransactions1);
    
    for (int i = 0; i < numberOfTransactions1; i++) {
        fgets(buffer1, 1000, transactionFile1); //read by line
        char *uid = strtok (buffer1, ","); //tokenize
        char *typeOfTransaction = strtok (NULL, ","); //tokenize
        double amountOfTransaction = atof (strtok (NULL, ",")); //tokenize
        char *customerAccountNumber = strtok (NULL, ","); //tokenize
        double balanceBefore = atof (strtok (NULL, ",")); //tokenize
        double balanceAfter = atof(strtok (NULL, ",")); //tokenize
        char *transferAccountNumber = strtok (NULL, ","); //tokenize

        //create new transaction structure

        transactions1[i] = *createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                            customerAccountNumber, balanceBefore, balanceAfter, 
                                            transferAccountNumber); 
    }

    // NULL Pointer Check

    if (filePath2 == NULL) {
        return;
    }

    FILE *transactionFile2 = fopen (filePath2, "r"); //open file
    char buffer2[1000]; //temp buffer
    fgets(buffer2, 1000, transactionFile2);
    int numberOfTransactions2 = atoi(buffer2); //count number of transactions from the first line for loop
    Transaction *transactions2 = (Transaction*) malloc (sizeof(Transaction) * numberOfTransactions2);
    
    for (int i = 0; i < numberOfTransactions2; i++) {
        fgets(buffer2, 1000, transactionFile2); //read by line
        char *uid = strtok (buffer2, ","); //tokenize
        char *typeOfTransaction = strtok (NULL, ","); //tokenize
        double amountOfTransaction = atof (strtok (NULL, ",")); //tokenize
        char *customerAccountNumber = strtok (NULL, ","); //tokenize
        double balanceBefore = atof (strtok (NULL, ",")); //tokenize
        double balanceAfter = atof(strtok (NULL, ",")); //tokenize
        char *transferAccountNumber = strtok (NULL, ","); //tokenize

        //create new transaction structure

        transactions2[i] = *createTransaction(uid, typeOfTransaction, amountOfTransaction, 
                                            customerAccountNumber, balanceBefore, balanceAfter, 
                                            transferAccountNumber); 
    }

    printf ("==================================\n");
    printf ("Data Anomalies Report\n");
    printf ("==================================\n");

    int inconsistentTransactions = 0;
    int missingTransactions = 0;

    qsort (transactions1, numberOfTransactions1, sizeof(Transaction), compareByUUID);
    qsort (transactions2, numberOfTransactions2, sizeof(Transaction), compareByUUID);

    for (int i = 0 ; i < numberOfTransactions1 ; i++) {
       Transaction *found = bsearch (&transactions1[i], transactions2, numberOfTransactions2, sizeof(Transaction), compareByUUID);
       
       // check if transaction is missing or inconsistent

       if (found == NULL) {
           missingTransactions++;
           printf("Missing Transaction: (%s) in database A but not in B\n", transactions1[i].uid);
       } else if (strcmp(transactions1[i].typeOfTransaction, found->typeOfTransaction) != 0 ||
                  strcmp(transactions1[i].customerAccountNumber, found->customerAccountNumber) != 0 ||
                  transactions1[i].amountOfTransaction != found->amountOfTransaction ||
                  transactions1[i].customerBalanceBefore != found->customerBalanceBefore ||
                  transactions1[i].customerBalanceAfter != found->customerBalanceAfter ||
                  strcmp(transactions1[i].transferAccountNumber, found->transferAccountNumber) != 0) {
                      inconsistentTransactions++;
                      printf("Inconsistent Transaction: \n");
                      printf("A:");
                      printTransaction(&transactions1[i]);
                      printf("B:");
                      printTransaction(found);
                }
    }

    for (int i = 0 ; i < numberOfTransactions2 ; i++) {
       Transaction *found = bsearch (&transactions2[i], transactions1, numberOfTransactions1, sizeof(Transaction), compareByUUID);
       
       // check transaction misses in database A too.

       if (found == NULL) {
           missingTransactions++;
           printf("Missing Transaction: (%s) in database B but not in A\n", transactions2[i].uid);
        }
    }

    printf ("Missing transactions: %d\n", missingTransactions);
    printf ("Inconsistent transactions: %d\n", inconsistentTransactions);

    // free arrays and close file

    free(transactions1);
    free(transactions2);

    fclose(transactionFile1);
    fclose(transactionFile2);

    return;
}