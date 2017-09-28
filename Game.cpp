#include "Game.h"
#include "TestFunctions.h"

#include <iostream>
using std::cout;
using std::endl;


Game::Game(int _numbplayers)
{
    numbplayers = _numbplayers;

    if (numbplayers < 2)
    { numbplayers = 2; }

}//


void Game::Play()
{
    // --- SETUP ---
    /// If setup gets longer move to own function

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed);

    players.resize(numbplayers); //Plus one for dealer

    SetupPlayer();

    DeckBuild(GameDeck);

    Shuffle(GameDeck);

    // --- END SET UP ---


    while (!GameOver)
    {
        ++roundnumber;

        cout << "\nRound Start " << roundnumber << endl;

        if (CheckForGameOver())
            { break; }


        for (int i = 1; i < players.size(); ++i)
        {
            GetPlayerBet(i);
        }

        DealToAll(2);

        winnerindex = 0;





        if (winnerindex != 0)
        {
            // payout say who won
            cout << "Player " << winnerindex << " wins the round!" << endl
                 << "Chips won: " << (players[winnerindex].betamount * 2) << endl;
        }
        else
        {
            cout << "Dealer wins!" << endl;
        }


        cout << "\nRound end\n";
        std::cin.get();

        /// Game over when....

        // if game over then do things like give winner the chips, up max bet, etc.

    }// end of game loop;

}//

///---------------- End Play, used functions below. --------------------------




bool Game::CheckForGameOver()
{
    /// Add more

    for (int i = 0; i < players.size(); ++i)
    {
        if (GetHandTotal(players[i].Hand)  > 21)
        {
            // Burst, handle that

            GameOver = true;
        }
    }


    return false;
}//


void Game::SetupPlayer()  /// Add to
{
    for (int i = 0; i < numbplayers; ++i)
    {
        players[i].ID = i;



    }
}//


void Game::GetPlayerBet(int _playerindex)
{
    while (true)
    {
        cout << "Enter a bet amount from " << 0 << " to " << maxbet << ":" << endl;
        std::cin >> players[_playerindex].betamount;
        cout << endl;

        if (std::cin.fail()
         || players[_playerindex].betamount <= 0
         || players[_playerindex].betamount > maxbet)
        {
            cout << "Invalid bet amount." << endl;
        }
        else { break; }
    }

    players[_playerindex].chips -= players[_playerindex].betamount;

    cout << "You bet: " << players[_playerindex].betamount << "."
         << " you have " << players[_playerindex].chips << " chips left." << endl;

}//



void Game::DealCards(int _numbofcards, Player _player)
{
    for (int i = 0; i < _numbofcards; ++i)
    {
        _player.Hand.push_back(GameDeck.back());
        GameDeck.pop_back();
    }

}//

void Game::DealToAll(int _numbofcards)
{
    for (int j = 0; j < players.size(); ++j)
        for (int i = 0; i < _numbofcards; ++i)
    {
        players[j].Hand.push_back(GameDeck.back());
        GameDeck.pop_back();
    }

}//


int Game::GetHandTotal(std::vector<Card> _hand) const
{
    int total = 0;
    bool containsAce = false;

    for (int i = 0; i < _hand.size(); ++i)
    {
        if (_hand[i].GetRank() == Ace)
        { containsAce = true; }

        total += _hand[1].GetRank();
    }

    if (total > 21 && containsAce)
    {
        total -= 10; // drop ace value down to 1 instead of 11.
    }

    return total;
}//


void Game::Dealer() ///-------------------------- maybe don't need if nothing more to go here
{
    if (GetHandTotal(players[0].Hand) < 17)
    {
        DealCards(1, players[0]);
    }

}//