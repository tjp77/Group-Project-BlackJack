#ifndef GAME_H
#define GAME_H

#include "DeckOperations.h"

struct Player
{
    int ID;
    int chips = 1000;
    int betamount;
    int numbcards = 0;
    int handtotal = 0; // call func after draws, to recalculate. store in here so don't need to calculate mult times.
    bool isstanding = false;
    bool isoutofround = false;

    Card Hand[10];
};

class Game  /// Break up more somehow, game getting long
{
    private:

    int SingleDeckSize = 52;
    int numbplayers; // Dealer + actual players, let dealer always be 'player' zero
    int numbdecks;
    int maxbet = 100; //increase in game as needed
    int standingplayers = 0;

    bool GameOver = false;


    std::vector<Player> players;
    std::vector<Card> GameDeck;

    void SetupPlayer();
    void GetPlayerBet(int _playerindex);

    void DealCards(int _numbofcards, int _playerindex);
    void DealToAll(int _numbofcards);

    int GetHandTotal(int _playerindex) const;

    void PlayerChoice(int _playerindex);

    // Return # corresponding to index of winning player.
    int CompareCards();

    public:

    Game (int _numbplayers);

    void Play();

    int winnerindex;
    int roundnumber = 0;

};


#endif // GAME_H
