#ifndef GAME_H
#define GAME_H

#include "DeckOperations.h"

struct Player
{
    int ID;
    int chips = 1000;
    int betamount;
    bool isstanding = false;

    std::vector<Card> Hand;
};

class Game  /// Break up more somehow, game getting long
{
    private:

    int SingleDeckSize = 52;
    int numbplayers; // Dealer + actual players, let dealer always be 'player' zero
    int numbdecks;
    int maxbet = 100; //increase in game as needed

    bool GameOver = false;


    std::vector<Player> players;
    std::vector<Card> GameDeck;

    void SetupPlayer();
    void GetPlayerBet(int _playerindex);

    void DealCards(int _numbofcards, Player _player);
    void DealToAll(int _numbofcards);

    int GetHandTotal(std::vector<Card> _hand) const;

    void Dealer();

    public:

    Game (int _numbplayers); /// I use _ in parameter/argument names to distinguish
                                                                  /// them easily in long functions.
    void Play();

    int winnerindex; /// keeps track of who won the round, assuming an array of players, this being the corresponding array index.
    int roundnumber = 0;

};


#endif // GAME_H
