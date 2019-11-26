#ifndef _MY_BANK_H_
#define _MY_BANK_H_

//the functions could be void but I think it is better to receive status of the operation
#define arrSize 50           // array size for the bank numbers
#define statusAndFunds 2     // 2 spots for status of bank account and its funds
#define offsetBankNumber 901 //account numbers start with 901 offsetting for the array indexes

extern double arrAccount[arrSize][statusAndFunds];
extern double openAccounts;
/**
 * Opens the first available bank account with the amount of funds received
 * prints a massage if successful and returns 1
 * prints a massage if not successful and returns 0
 **/
int openAccount(double amount);
/**
 *   Receive a account number
 *   Prints a message with the account number with the amount of funds if the account is open
 *   Prints a error message if account is not open
 *   returns the amount of funds if successful 
 *   returns 0 if not successful
 **/
double getBalance(int accountNumber);
/**
 * Receive account number and amount of funds
 * updates the amount of funds, only positive numbers allowed 
 * Prints a message with the account number with the updated amount of funds if the account is open
 * Prints a error if account is not open
 * returns 1 if successful
 * returns 0 if not successful
 **/
int setBalance(int accountNumber, double amount);
/**
 * Receive account number and amount of funds only positive amount of funds allowed
 * Withdrawing the amount of funds received from the account numbers only if the account is open
 * Prints a message with the account number with the updated amount
 * Prints a error if account is not open or it has insufficient funds
 * returns 1 if successful
 * returns 0 if not successful
 * **/
int withdrawBalance(int accountNumber, double amount);
/**
 * Receive account number
 * Closing the account and zero the funds
 * Prints a message with the account number that is closed
 * Prints error if the account was not open
 * returns 1 if successful
 * returns 0 if not successful
 **/
int closeAccount(int accountNumber);
/**
 * Reverie interest rate must be above 0
 * Iterates through all the open accounts and adds the interest rate
 * Prints a message when it is done
 **/
void addInterestRate(double inter);
/**
 * Iterates through all the open accounts prints the account number and the funds
 **/
void printAccount();
/**
 * Iterates through all the open accounts, close them and zero their funds
 **/
void closeAndExit();

#endif