
~tjp77 -TODO/Notes:

"Ties between players are irrelevant, as every player plays against the dealer only and not each other. If your hand is better than the dealers you win your bet, if it is worse you lose your bet"

comparing hands function

double down

'blackjack' 21 and non blackjack 21?
"If both the dealer and player have a non-blackjack 21, it is considered a push. You neither win nor lose.You keep your original bet."



# Group-Project-BlackJack, outline by Brian

Goal is to get to 21

2 players (user against dealer)

Start with two cards

start with 1000 chips

  default bet is 100 chips
  
  if win, increase 200
  
  if win, increase to 500
  
  if win, increase to 1000
  
    if lose at any time, go back to 100 chip cap
    
bet before you recieve hand

Dealer draws to 16, stands on 17

User can stand, draw, or double down, or quit

  stand - don't draw another card
  
  draw - draw cards until stand or bust
  
  double down - double bet, draw one more card
  
User or dealer loses by drawing past 21, called a bust

Bet at beginning

  payout 2 to 1
  
  payout for blackjack(21) is 3 to 2 (1.5)
  
aces can be 1 or 11

  11 is default value
  
  if bust for dealer or user, reverts to 1
  
2 through 10 are self explanatory

all face cards are 10

2 menus

  how much bet
  
  what to do with hand
  
dislpay users cards and total

display dealers value minus face down cards

display turn's bet and max range

display turn count


Objects:
 card.cpp - the cards
  card.hpp

 game.cpp - display/run/settings
  game.hpp
 
deck.cpp - main deck and user hands
 deck.hpp

deckFunctions.cpp - display hands/deck, shuffle
deckFunctions.hpp

player.cpp - holds player hand, settings
 player.hpp

main.cpp

