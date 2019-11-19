#ifndef _MY_BANK_H
#define _MY_BANK_H

int openAccount(double amount);
double getBalance(int accountNumber);
int setBalance(int accountNumber,double amount);
int withdrawBalance(int accountNumber,double amount);
int closeAccount(int accountNumber);
//int add‫‪InterestRate‬‬(double ‫‪inter);
int addInterestRate(double inter);
void printAccount();
void closeAndExit();

#endif