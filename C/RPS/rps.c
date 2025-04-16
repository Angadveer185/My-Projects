#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void rps(int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int computer = rand() % 3;
        int player;
        printf("\n Enter your choice (0-Rock, 1-Paper, 2-Scissors): ");
        scanf("%d", &player);

        if (computer == player)
        {
            printf("Both Chose the same... It's a tie!! \n");
        }
        else if (computer == 0 && player == 1)
        {
            printf("Computer chose Rock... Player Wins! \n");
        }
        else if (computer == 0 && player == 2)
        {
            printf("Computer chose Rock... Computer Wins! \n");
        }
        else if (computer == 1 && player == 2)
        {
            printf("Computer chose Paper... Player Wins! \n");
        }
        else if (computer == 1 && player == 0)
        {
            printf("Computer chose Paper... Computer Wins! \n");
        }
        else if (computer == 2 && player == 0)
        {
            printf("Computer chose Scissors... Player Wins! \n");
        }
        else if (computer == 2 && player == 1)
        {
            printf("Computer chose Scissors... Computer Wins! \n");
        }
        else{
            printf("Invalid choice... Please try again! \n");
            i--;
            continue;
        }
    }
}
int main()
{
    rps(3);
    return 0;
}
