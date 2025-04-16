#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int difficulty;

#define BOARD_SIZE 3
#define X 'X'
#define O 'O'

void setDifficulty();
void clearTerminal();
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player);
int checkDraw(char board[BOARD_SIZE][BOARD_SIZE]);
void playGame();
void playerMove(char board[BOARD_SIZE][BOARD_SIZE]);
void computerMove(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

typedef struct
{
    int player;
    int computer;
    int draws;
} Score;

Score score = {.player = 0, .computer = 0, .draws = 0};

int main()
{
    srand(time(0));
    int choice;
    setDifficulty();
    do
    {
        playGame();
        printf("Play again? (1 - yes or 0 - no): ");
        scanf("%d", &choice);
    } while (choice);
    printf("Exiting...\n");
    return 0;
}

void playGame()
{
    int choice;
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    char currentTurn = rand() % 2 == 0 ? X : O;
    printBoard(board);

    while (1)
    {
        if (currentTurn == X)
        {
            playerMove(board);
            printBoard(board);
            if (checkWin(board, X))
            {
                score.player++;
                printBoard(board);
                printf("Player X Wins\n");
                break;
            }
            currentTurn = O;
        }
        else
        {
            computerMove(board);
            printBoard(board);
            if (checkWin(board, O))
            {
                score.computer++;
                printBoard(board);
                printf("Computer O Wins\n");
                break;
            }
            currentTurn = X;
        }

        if (checkDraw(board))
        {
            score.draws++;
            printf("It's a Draw\n");
            break;
        }
    }
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    return !(row < 1 || row > 3 ||
             col < 1 || col > 3 ||
             board[row - 1][col - 1] != ' ');
}

void playerMove(char board[BOARD_SIZE][BOARD_SIZE])
{
    int count = 0, x, y;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                count++;
                x = i;
                y = j;
            }
        }
    }

    if (count == 1)
    {
        board[x][y] = X;
        return;
    }

    int row, col;
    do
    {
        printf("Player %c's Move\n", X);
        printf("Enter Row and column (1-3) for %c: ", X);
        scanf("%d %d", &row, &col);
    } while (!is_valid_move(board, row, col));
    board[row - 1][col - 1] = X;
}

void computerMove(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Immediate Win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = O;
                if (checkWin(board, O))
                {
                    return;
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }

    // Immediate Block
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = X;
                if (checkWin(board, X))
                {
                    board[i][j] = O;
                    return;
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }

    // In Stockfish Mode
    if (difficulty == 2)
    {
        // Play Center if Available
        if (board[1][1] == ' ')
        {
            board[1][1] = O;
            return;
        }

        // Play Corner if Available
        int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
        for (int i = 0; i < 4; i++)
        {
            if (board[corners[i][0]][corners[i][1]] == ' ')
            {
                board[corners[i][0]][corners[i][1]] = O;
                return;
            }
        }
    }

    // Play First Available Move
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = O;
                return;
            }
        }
    }
    return;
}

void setDifficulty()
{
    while (1)
    {
        printf("Select Dificulty Level:\n");
        printf("1. Standard\n");
        printf("2. Stockfish\n");
        printf("Enter Your Choice: ");

        scanf("%d", &difficulty);

        if (difficulty != 1 && difficulty != 2)
        {
            printf("Invalid Choice\n");
        }
        else
        {
            break;
        }
    }
}

void clearTerminal()
{
    system("cls");
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    clearTerminal();
    printf("Score - Player: %d, Computer: %d, Draws: %d \n", score.player, score.computer, score.draws);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        if (i < BOARD_SIZE - 1)
        {
            printf("\n---+---+---");
        }
    }
    printf("\n\n");
};

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player || board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            return 1;
        }
    }
    return 0;
}

int checkDraw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}