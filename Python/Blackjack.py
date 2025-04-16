import random as rand
import time

class Card:
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank
    
    def __str__(self):
        return f"{self.rank['rank']} {self.suit}"

class Deck:
    def __init__(self):
        self.cards = []
        suits = ['♣', '♦', '♥', '♠']
        ranks = [{'rank': 'A', 'value': 11}, 
                 {'rank': '2', 'value': 2}, 
                 {'rank': '3', 'value': 3}, 
                 {'rank': '4', 'value': 4}, 
                 {'rank': '5', 'value': 5}, 
                 {'rank': '6', 'value': 6}, 
                 {'rank': '7', 'value': 7}, 
                 {'rank': '8', 'value': 8}, 
                 {'rank': '9', 'value': 9}, 
                 {'rank': '10', 'value': 10}, 
                 {'rank': 'J', 'value': 10}, 
                 {'rank': 'Q', 'value': 10}, 
                 {'rank': 'K', 'value': 10}]
        
        for suit in suits:
            for rank in ranks:
                self.cards.append(Card(suit, rank))


    def shuffle(self):
        if len(self.cards) > 1:
            rand.shuffle(self.cards)

    def deal(self, num):
        cards_dealt = []
        for i in range(num):
            if len(self.cards) > 0:
                card = self.cards.pop()
                cards_dealt.append(card)
        return cards_dealt

class Hand:
    def __init__(self, dealer=False):
        self.cards = []
        self.value = 0
        self.dealer = dealer

    def add_card(self, card_list):
        self.cards.extend(card_list)
    
    def calculate_value(self):
        self.value = 0
        has_ace = False

        for card in self.cards:
            card_value = int(card.rank['value'])
            self.value += card_value
            if card.rank['rank'] == 'A':
                has_ace = True

        if self.value > 21 and has_ace:
            self.value -= 10

    def get_value(self):
        self.calculate_value()
        return self.value
    
    def is_blackjack(self):
        return self.get_value() == 21 and len(self.cards) == 2
    
    def display(self, show_all_dealer_cards=False):
        print(f'''{"Dealer's" if self.dealer else "Your"} hand: ''')
        for index, card in enumerate(self.cards):
            if index == 0 and self.dealer and not show_all_dealer_cards and not self.is_blackjack():
                print('Hidden')
            else:
                print(card)
        if not self.dealer:
            print(f"Value: {self.get_value()}")
        print()

class Game:
    def play(self):
        game_number = 0
        games_to_play = 0

        while games_to_play <= 0:
            try:
                games_to_play = int(input("How many games would you like to play? "))
            except:
                print("Please enter a number.")

        while game_number < games_to_play:
            game_number += 1
            deck = Deck()
            deck.shuffle()
            player_hand = Hand()
            dealer_hand = Hand(dealer=True)

            for i in range(2):
                player_hand.add_card(deck.deal(1))
                dealer_hand.add_card(deck.deal(1))

            print()
            print('*' * 30)
            print(f"Game {game_number} of {games_to_play}")
            print('*' * 30)
            time.sleep(2)
            player_hand.display()
            time.sleep(2)
            dealer_hand.display()
            time.sleep(2)

            if self.check_winner(player_hand, dealer_hand):
                continue

            choice = ""
            while player_hand.get_value() < 21 and choice not in ['stand', 's']:
                choice = input("Would you like to Hit or Stand (H/S)? ").lower()
                print()
                if choice in ["hit", "h"]:
                    player_hand.add_card(deck.deal(1))
                    time.sleep(2)
                    player_hand.display()
                    time.sleep(2)

                if self.check_winner(player_hand, dealer_hand):
                    break

            if not self.check_winner(player_hand, dealer_hand):
                player_hand_value = player_hand.get_value()
                dealer_hand_value = dealer_hand.get_value()

                while dealer_hand_value < 17 and dealer_hand_value<player_hand_value:
                    print("Dealer hits.")
                    print(dealer_hand.display(show_all_dealer_cards=True))
                    print(dealer_hand.get_value())
                    time.sleep(2)
                    dealer_hand.add_card(deck.deal(1))
                    dealer_hand_value = dealer_hand.get_value()

                self.check_winner(player_hand, dealer_hand, game_over=True)

        print("\nThanks for Playing!")

    def check_winner(self, player_hand, dealer_hand, game_over=False):
        if game_over:
            self.display_final_hands(player_hand, dealer_hand)
        
        if not game_over:
            if player_hand.get_value() > 21:
                print('Bust! Dealer wins.')
                return True
            elif dealer_hand.get_value() > 21:
                print('Dealer busts! You win.')
                return True
            elif player_hand.is_blackjack() and dealer_hand.is_blackjack():
                print("Both player and dealer have blackjack! It's a tie.")
                return True
            elif player_hand.is_blackjack():
                print('You have blackjack! You win!')
                return True
            elif dealer_hand.is_blackjack():
                print('Dealer has blackjack! Dealer wins!')
                return True
        else:
            if player_hand.get_value() > dealer_hand.get_value() and player_hand.get_value() <= 21:
                print('You win!')
            elif player_hand.get_value() < dealer_hand.get_value() and dealer_hand.get_value() <= 21:
                print('Dealer wins!')
            elif dealer_hand.get_value() > 21:
                print('Dealer busts! You win.')
            elif player_hand.get_value() == dealer_hand.get_value():
                print("It's a tie!")
            return True
        return False

    def display_final_hands(self, player_hand, dealer_hand):
        print()
        print()
        print("Final Results:")
        time.sleep(2)
        player_hand.display()
        print('Your Hand:', player_hand.get_value())
        time.sleep(2)
        dealer_hand.display(show_all_dealer_cards=True)
        print('Dealer Hand:', dealer_hand.get_value())
        time.sleep(2)

game = Game()
game.play()