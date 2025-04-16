#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    srand(time(0));
    int txt = rand() % 100;
    char word[100];
    FILE *ptr;
    ptr = fopen("words.txt", "r");
    for (int i = 0; i <= txt; i++)
    {
        fscanf(ptr, "%s", word);
    }
    // printf("Randomly selected word: %s\n", word);
    fclose(ptr);

    int size = strlen(word);
    int tries = 0;
    char guess;
    char guessedWord[100] = {0};
    int correctGuesses[100] = {0};
    printf("------------------------------------------------\n");
    printf("Welcome to Hangman! \n");
    printf("Randomly selected word has %d letters.\n", size);
    printf("------------------------------------------------\n");

    while (strlen(guessedWord) < size && tries < 10){
        printf("Guess a letter (Lowercase): ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < size; i++){
            if (guess == word[i] && correctGuesses[i] == 0){
                guessedWord[strlen(guessedWord)] = guess;
                found = 1;
                correctGuesses[i] = 1;
                // break;l
                
            }
        }

        if(found){
            printf("You Guessed Right! \n");
        }
        else{
            printf("Wrong Guess! \n");
            tries++;
        }

        printf("Guessed so far: ");
        for (int i = 0; i < size; i++){
            if (correctGuesses[i]){
                printf("%c", word[i]);
            }
            else{
                printf("_");
            }
        }
        printf("\n");

        printf("You have %d tries left \n", 10 - tries);
        printf("\n");
    }

    if (strlen(guessedWord) == size){
        printf("Congratulations! You guessed the word: %s\n", word);
    }
    else{
        printf("Game Over! The word was: %s\n", word);
    }
    return 0;
}