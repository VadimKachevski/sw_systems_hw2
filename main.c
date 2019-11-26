#include "myBank.h"
#include <stdio.h>

int getAccountNumber()
{
    int accountNumber;
    printf("\nPlease enter account number (Must be between 901-950): ");
    if (scanf("%d", &accountNumber) == 1 && (accountNumber >= 901 && accountNumber <= 950))
    {
        return accountNumber;
    }
    printf("\nYou entered wrong nubmer\n");
    return -1;
}
double getFunds()
{
    double funds;
    printf("\nPlease enter amount of funds (Must not be negative): ");
    if (scanf("%lf", &funds) == 1 && funds >= 0)
    {
        return funds;
    }
    printf("\nYou entered wrong nubmer\n");
    return -1;
}
double getInterset()
{
    double intrest;
    printf("\nPlease enter intrest number (Must not be negative): ");
    if (scanf("\n%lf", &intrest) == 1 && intrest > 0)
    {
        return intrest;
    }
    printf("\nYou entered wrong nubmer\n");
    return -1;
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
            if (funds != -1)
            {
                openAccount(funds);
            }
            break;
        case 'B':
            printf("\nGetting balance information:\n");
            accountNumber = getAccountNumber();
            if (accountNumber != -1)
            {
                getBalance(accountNumber);
            }
            break;
        case 'D':
            printf("\n Depositing funds:\n ");
            accountNumber = getAccountNumber();
            if(accountNumber == -1)
            {
                break;
            }
            funds = getFunds();
            if(funds == -1)
            {
                break;
            }
            setBalance(accountNumber, funds);
            break;
        case 'W':
            printf("\nWithdrawing funds: \n");
            accountNumber = getAccountNumber();
            if(accountNumber == -1)
            {
                break;
            }
            funds = getFunds();
            if(funds == -1)
            {
                break;
            }
            withdrawBalance(accountNumber, funds);
            break;
        case 'C':
            printf("\nClosing account: \n");
            accountNumber = getAccountNumber();
            if(accountNumber == -1)
            {
                break;
            }
            closeAccount(accountNumber);
            break;
        case 'I':
            printf("\n Add interst to accounts : \n");
            intrest = getInterset();
            if(intrest == -1)
            {
                break;
            }
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