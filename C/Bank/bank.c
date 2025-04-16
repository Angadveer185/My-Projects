#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int createAccount(int *idx, int* accountDB[], float* balanceDB[]){

    float balance = 0;
    int accountNo = 200000 + rand() % 100000;
    printf("Generated Account Number: %d\n", accountNo);
    printf("Enter Balance in account: ");
    scanf("%f", &balance);

    for (int i = 0; i < *idx; i++)
    {
        if (*accountDB[i] == accountNo)
        {
            printf("Account already exists\n");
            return 1;
        }
    }
    

    accountDB[*idx] = malloc(sizeof(int));
    balanceDB[*idx] = malloc(sizeof(float));

    *accountDB[*idx] = accountNo;
    *balanceDB[*idx] = balance;
    (*idx)++;
    printf("Account Created Successfully\n");
    return 0;
}

int deposit(int* idx, int* accountDB[], float* balanceDB[]){
    int accountNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNo);

    for (int i = 0; i < *idx; i++)
    {
        if (*accountDB[i] == accountNo)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            *balanceDB[i] += amount;
            printf("Amount Deposited Successfully\n");
            return 0;
        }
        else
        {
            printf("Account Not Found\n");
            return 1;
        }
    }   
}

int withdraw(int* idx, int* accountDB[], float* balanceDB[]){
    int accountNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNo);

    for (int i = 0; i < *idx; i++)
    {
        if (*accountDB[i] == accountNo)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            *balanceDB[i] -= amount;
            printf("Amount Withdrawn Successfully\n");
            return 0;
        }
        else
        {
            printf("Account Not Found\n");
            return 1;
        }
    }   
}

int checkBalance(int* idx, int* accountDB[], float* balanceDB[]){
    int accountNo;
    printf("Enter Account Number: ");
    scanf("%d", &accountNo);

    for (int i = 0; i < *idx; i++)
    {
        if (*accountDB[i] == accountNo)
        {
            printf("Balance in account: $%.2f\n", *balanceDB[i]);
            return 0;
        }
        else
        {
            printf("Account Not Found\n");
            return 1;
        }
    }   
}

void displayAccounts(int *idx, int* accountDB[], float* balanceDB[]){
    if (*idx == 0)
    {
        printf("Database is empty.\n");
        return;
    }

    printf("\nDatabase contains:\n");
    printf("--------------------\n");

    for (int i = 0; i < *idx; i++)
    {
        printf("Entry %d\n", i + 1);
        printf("    Account Number: %d\n", *accountDB[i]);
        printf("    Balance: $%.2f\n", *balanceDB[i]);
        printf("\n");
    }
}

int main()
{
    srand(time(0));
    int choice, flag = 1, idx = 0;
    int *accountDB[1000];
    float *balanceDB[1000];
    while (flag != 0)
    {
        printf("\n---Chhoker National Bank---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Accounts\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount(&idx, accountDB, balanceDB);
            break;
        case 2:
            deposit(&idx, accountDB, balanceDB);
            break;
        case 3:
            withdraw(&idx, accountDB, balanceDB);
            break;
        case 4:
            checkBalance(&idx, accountDB, balanceDB);
            break;
        case 5:
            displayAccounts(&idx, accountDB, balanceDB);
            break;
        case 6:
            printf("\nThank You for using Chhoker National Bank\n");
            printf("Exiting...\n");
            flag = 0;
            break;
        
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}