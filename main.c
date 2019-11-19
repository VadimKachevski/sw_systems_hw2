#include "myBank.h"
#include <stdio.h>

int getAccountNumber()
{
    int accountNumber;
    do
    {
        printf("\nPlease enter account number (Must be between 901-950): ");
        scanf("\n%d", &accountNumber);
    } while (accountNumber < 901 || accountNumber > 950);
    return accountNumber;
}
double getFunds()
{
    double funds;
    do
    {
        printf("\n Please enter amount of funds (Must not be negative): ");
        scanf("\n%lf", &funds);
    } while (funds < 0);
    return funds;
}
double getInterset()
{
    double intrest;
    do
    {
        printf("\nPlease enter intrest number (Must not be negative): ");
        scanf("\n%lf", &intrest);
    } while (intrest < 0);
    return intrest;
}

int main()
{
    char ans;
    int accountNumber;
    double funds;
    double intrest;
    do
    {
        printf("\nPlease enter the transaction code\n 'O':Open account \n 'B':Get Balance information \n");
        printf(" 'D':Deposit funds into account \n 'W':Withdraw funds from account \n 'C':Close account \n");
        printf(" 'I':Add interset to open accounts \n 'P':prints all the open accounts \n 'E':Close accounts and exit program\n");
        scanf("\n%c", &ans);
        switch (ans)
        {
        case 'O':
            printf("\nCreating new account: \n");
            funds = getFunds();
            openAccount(funds);
            break;
        case 'B':
            printf("\nGetting balance information:\n ");
            accountNumber = getAccountNumber();
            getBalance(accountNumber);
            break;
        case 'D':
            printf("\n Depositing funds:\n ");
            accountNumber = getAccountNumber();
            funds = getFunds();
            setBalance(accountNumber, funds);
            break;
        case 'W':
            printf("\nWithdrawing funds: \n");
            accountNumber = getAccountNumber();
            funds = getFunds();
            withdrawBalance(accountNumber, funds);
            break;
        case 'C':
            printf("\nClosing account: \n");
            accountNumber = getAccountNumber();
            closeAccount(accountNumber);
            break;
        case 'I':
            printf("\n Add interst to accounts : \n");
            intrest = getInterset();
            addInterestRate(intrest);
            break;
        case 'P':
            printf("\nPrinting accounts information: \n");
            printAccount();
            break;
        case 'E':
            printf("\nClosing accounts and exiting the program \n");
            closeAndExit();
            break;
        default:
            printf("\nThe value you entered is not valid \n");
            break;
        }
    } while (ans != 'E');

    return 0;
}