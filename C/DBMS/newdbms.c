#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* validateEmail(){
    char* email = malloc(100);
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
    char* password = malloc(100);
    int flag = 0;
    while (flag!=1)
    {
        int upper = 0, lower = 0, digit = 0, special = 0;
        printf("Enter Your Password: ");
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

int countWords(FILE *f){
    int count = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF){
        if (ch == '\n')
            count++;
    }
    return count;
 }

void login()
{
    
    FILE *emailP = fopen("mails.txt", "r");
    FILE *passwordP = fopen("passwords.txt", "r");
    int DBsize = countWords(emailP);
    rewind(emailP);
    printf("DBsize: %d\n", DBsize);

    if (DBsize == 0)
    {
        printf("Database is empty... Sign in first\n");
        fclose(emailP);
        fclose(passwordP);
        return;
    }
    
    char email[100], password[100];
    printf("Enter Your Email: ");
    scanf("%s", email);
    printf("Enter Your Password: ");
    scanf("%s", password);
    int found = 0, emailfound = 0;

    for (int i = 0; i < DBsize; i++)
    {
        char scannedMail[100], scannedPassword[100];

        fscanf(emailP, "%s", scannedMail);
        fscanf(passwordP, "%s", scannedPassword);
        
        if (strcmp(email, scannedMail) == 0) {
            emailfound = 1;
            if (strcmp(password, scannedPassword) == 0) {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("Login Successful, Welcome to GameScience\n");
    }
    else if(emailfound){
        printf("Incorrect password\n");
    }
    else
    {
        printf("Account does not exist... Sign in first\n");
    }
    fclose(emailP);
    fclose(passwordP);
};

void signin()
{
    FILE *emailP = fopen("mails.txt", "a+");
    FILE *passwordP = fopen("passwords.txt", "a+");
    int DBsize = countWords(emailP);

    char *email = validateEmail();
    char *password = validatePassword();
    
    for (int i = 0; i < DBsize; i++)
    {
        char scanned[100];
        fscanf(emailP, "%s", scanned);
        if (strcmp(email, scanned) == 0)
        {
            printf("Account already exists\n");
            fclose(emailP);
            fclose(passwordP);
            return;
        }
    }
    
    fprintf(emailP, "%s\n", email);
    fprintf(passwordP, "%s\n", password);

    fclose(emailP);
    fclose(passwordP);

    printf("Account Created Successfully\n");
};

void displayDatabase()
{
    FILE *emailP = fopen("mails.txt", "r");
    FILE *passwordP = fopen("passwords.txt", "r");
    int DBsize = countWords(emailP);
    rewind(emailP);
    if (emailP == NULL || DBsize == 0)
    {
        printf("Database is empty.\n");
        return;
    }

    printf("\nDatabase contains:\n");
    printf("--------------------\n");

    for (int i = 0; i < DBsize; i++)
    {
        char scannedMail[100], scannedPassword[100];

        fscanf(emailP, "%s", scannedMail);
        fscanf(passwordP, "%s", scannedPassword);

        if (scannedMail != NULL && scannedPassword != NULL)
        {
            printf("User %d:\n", i + 1);
            printf("  Email   : %s\n", scannedMail);
            printf("  Password: %s\n\n", scannedPassword);
            printf("\n");
        }
    }
}

int main()
{
    int choice, flag = 1;

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
            displayDatabase();
            break;
        case 2:
            login();
            break;
        case 3:
            signin();
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