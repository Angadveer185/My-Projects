import random as rand
import time

rock = ['r', 'R', 'Rock', 'rock']
paper = ['p', 'P', 'Paper', 'paper']
scissors = ['s', 'S', 'Scissors', 'scissors', 'Scissor', 'scissor']


def RPS():
    player_score = 0
    comp_score = 0
    game_number = 1


    total_games = int(input('How Many Games Would You Like To Play? '))
    time.sleep(2)
    
    while game_number <= total_games:
        print()
        print('*'*30)
        print('Game Number:', game_number)
        print('*'*30)
        print()
        time.sleep(2)
        player_choice = input('Enter Your Choice (Rock/Paper/Scissors) OR (r/p/s): ').lower()
        comp_choice = rand.choice(['Rock', 'Paper', 'Scissors'])
        print()
        time.sleep(2)
        if player_choice in rock and comp_choice in rock:
            print('''Both chose Rock...It's a Tie!''')
        elif player_choice in paper and comp_choice in paper:
            print('''Both chose Paper...It's a Tie!''')
        elif player_choice in scissors and comp_choice in scissors:
            print('''Both chose Scissors...It's a Tie!''')
        elif player_choice in rock and comp_choice in paper:
            print('Computer chooses Paper...You lose!!')
            comp_score += 1
        elif player_choice in rock and comp_choice in scissors:
            print('Computer chooses Scissors...You Win!!')
            player_score += 1
        elif player_choice in paper and comp_choice in rock:
            print('Computer chooses Rock...You Win!!')
            player_score += 1
        elif player_choice in paper and comp_choice in scissors:
            print('Computer chooses Scissors...You Lose!!')
            comp_score += 1
        elif player_choice in scissors and comp_choice in rock:
            print('Computer chooses Rock...You Lose!!')
            comp_score += 1
        elif player_choice in scissors and comp_choice in paper:
            print('Computer chooses Paper...You Win!!')
            player_score += 1
        else:
            print('Invalid Choice! Game Discarded!')
        game_number += 1
        time.sleep(2)

    print()
    print('*'*30)
    print('FINAL SCORES:')
    time.sleep(2)
    print('Player Score:', player_score)
    time.sleep(2)
    print('Computer Score:', comp_score)
    print('*'*30)
    print()
    time.sleep(2)
    print('Thank You for playing')

RPS()


