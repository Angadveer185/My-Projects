#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* validateEmail(){
    char* email = malloc(1000);
    int flag = 0;
    
    while (flag!=1)
    {
        int at = 0, atpos = -1, atcount = 0; 
        int dot = 0, dotpos = -1;
        printf("Enter Your Email: ");
        scanf("%s", email);

        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@')
            {
                at = 1;
                atpos = i;
                atcount++;
            }
            else if (email[i] == '.')
            {
                dot = 1;
                dotpos = i;
            }
        }

        if (at == 1 && dot == 1 && atpos < dotpos && atcount == 1)
        {
            flag = 1;
        }
        else
        {
            printf("Invalid Email, Please Enter a valid email.\n");
        }
    }
    return email;
}

char* validatePassword(){
    char* password = malloc(1000);
    int flag = 0;
    while (flag!=1)
    {
        int upper = 0, lower = 0, digit = 0, special = 0;
        printf("Enter Your Password (Must contain the following: Uppercase, lowercase, digit & special character): ");
        scanf("%s", password);

        for (int i = 0; i < strlen(password); i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                upper = 1;
            }
            else if (password[i] >= 'a' && password[i] <= 'z')
            {
                lower = 1;
            }
            else if (password[i] >= '0' && password[i] <= '9')
            {
                digit = 1;
            }
            else
            {
                special = 1;
            }
        }

        if (upper == 1 && lower == 1 && digit == 1 && special == 1 && strlen(password) >= 8)
        {
            flag = 1;
        }
        else
        {
            printf("Invalid Password, Please Enter a valid password.\n");
        }
    }
    return password;
}


void login(int *idx, char *emailDB[], char *passwordDB[])
{
    if (*idx == 0)
    {
        printf("Database is empty... Sign in first\n");
        return;
    }
    
    char email[1000];
    char password[1000];
    printf("Enter Your Email: ");
    scanf("%s", email);
    printf("Enter Your Password: ");
    scanf("%s", password);

    for (int i = 0; i < *idx; i++)
    {
        if (strcmp(email, emailDB[i]) == 0 && strcmp(password, passwordDB[i]) == 0)
        {
            printf("Login Successful\n");
            return;
        }
        else if ((strcmp(email, emailDB[i]) == 0 && strcmp(password, passwordDB[i]) != 0))
        {
            printf("Invalid Password\n");
            return;
        }
        else if ((strcmp(email, emailDB[i]) != 0 && strcmp(password, passwordDB[i]) == 0))
        {
            printf("Invalid Email\n");
            return;
        }
        else
        {
            printf("Account does not exist... Sign in first\n");
            return;
        }
    }
};

void signin(int *idx, char *emailDB[], char *passwordDB[])
{
    char *email = validateEmail();
    char *password = validatePassword();

    for (int i = 0; i < *idx; i++)
    {
        if (strcmp(email, emailDB[i]) == 0)
        {
            printf("Account already exists\n");
            free(email);
            free(password);
            return;
        }
    }

    emailDB[*idx] = malloc(strlen(email) + 1);
    passwordDB[*idx] = malloc(strlen(password) + 1);

    strcpy(emailDB[*idx], email);
    strcpy(passwordDB[*idx], password);

    free(email);
    free(password);

    (*idx)++;
    printf("Account Created Successfully\n");
};

void displayDatabase(int *idx, char *emailDB[], char *passwordDB[])
{
    if (*idx == 0)
    {
        printf("Database is empty.\n");
        return;
    }

    printf("\nDatabase contains:\n");
    printf("--------------------\n");

    for (int i = 0; i < *idx; i++)
    {
        if (emailDB[i] != NULL && passwordDB[i] != NULL)
        {
            printf("User %d:\n", i + 1);
            printf("  Email   : %s\n", emailDB[i]);
            printf("  Password: %s\n\n", passwordDB[i]);
            printf("\n");
        }
    }
}

int main()
{
    int choice, flag = 1, idx = 0;
    char *emailDB[1000];
    char *passwordDB[1000];

    while (flag)
    {
        printf("------------------------\n");
        printf("Welcome to GameScience!\n");
        printf("------------------------\n");
        printf("Enter Your Choice:\n");
        printf("1. Display Database\n");
        printf("2. LogIn\n");
        printf("3. SignUp\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayDatabase(&idx, emailDB, passwordDB);
            break;
        case 2:
            login(&idx, emailDB, passwordDB);
            break;
        case 3:
            signin(&idx, emailDB, passwordDB);
            break;
        case 4:
            flag = 0;
            printf("Thanks for using GameScience Database! \n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}