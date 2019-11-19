#include "myBank.h"
#include <stdio.h>

#define arrSize 50

double arrAccount[arrSize][2];
double openAccounts = 0;

int openAccount(double amount)
{
    if (openAccounts == arrSize)
    {
        printf("No more accounts available \n");
        return 0;
    }
    for (int i = 0; i < arrSize; i++)
    {
        if (arrAccount[i][0] == 0)
        {
            arrAccount[i][0] = 1;
            arrAccount[i][1] = amount;
            printf("The account number is %d and it has %.2lf funds \n", i + 901, amount);
            openAccounts++;
            return 1;
        }
    }
    return 0;
}
double getBalance(int accountNumber)
{
    if (arrAccount[accountNumber - 901][0] == 1)
    {
        printf("The account number is %d and it now has %.2lf funds \n", accountNumber, arrAccount[accountNumber - 901][1]);
        return 1;
    }
    else
    {
        printf("The account number is %d is not open, please open the account first \n", accountNumber);
        return 0;
    }
}
int setBalance(int accountNumber, double amount)
{
    if (arrAccount[accountNumber - 901][0] == 1)
    {
        arrAccount[accountNumber - 901][1] += amount;
        printf("The account number is %d and it now has %.2lf funds \n", accountNumber, arrAccount[accountNumber - 901][1]);
        return 1;
    }
    else
    {
        printf("The account number is %d is not open, please open the account first \n", accountNumber);
        return 0;
    }
}
int withdrawBalance(int accountNumber, double amount)
{
    if (arrAccount[accountNumber - 901][0] == 1)
    {
        if (arrAccount[accountNumber - 901][1] >= amount)
        {
            arrAccount[accountNumber - 901][1] -= amount;
            printf("The account number is %d and it now has %.2lf funds \n", accountNumber, arrAccount[accountNumber - 901][1]);
            return 1;
        }
        else
        {
            printf("The account number is %d doesn't have enough funds, it only have %.2lf \n", accountNumber, arrAccount[accountNumber - 901][1]);
            return 0;
        }
    }
    else
    {
        printf("The account number is %d is not open, please open the account first \n", accountNumber);
        return 0;
    }
}
int closeAccount(int accountNumber)
{
    if (arrAccount[accountNumber - 901][0] == 1)
    {
        arrAccount[accountNumber - 901][0] = 0;
        arrAccount[accountNumber - 901][1] = 0;
        printf("The account number is %d is closed \n", accountNumber);
        openAccounts--;
        return 1;
    }
    else
    {
        printf("The account number is %d is not open, please open the account first \n", accountNumber);
        return 0;
    }
}
//int add‫‪InterestRate‬‬(double ‫‪inter)
int addInterestRate(double inter)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arrAccount[i][0] == 1)
        {
            double interest = arrAccount[i][1] * inter;
            arrAccount[i][1] += interest;
        }
    }
    return 1;
}
void printAccount()
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arrAccount[i][0] == 1)
        {
            printf("The account number is %d and it now has %.2lf funds \n", i + 901, arrAccount[i][1]);
        }
    }
}
void closeAndExit()
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arrAccount[i][0] == 1)
        {
            arrAccount[i][0] = 0;
            arrAccount[i][1] = 0;
            openAccounts--;
            
        }
    }
     printf("all accounts are closed prepering for exit \n");
}
