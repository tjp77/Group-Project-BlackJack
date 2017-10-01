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
    /// ---------------------------- move setup out
    char input;
    int standingplayers = 0;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed);

    players.resize(numbplayers); //Plus one for dealer

    SetupPlayer();

    DeckBuild(GameDeck);

    Shuffle(GameDeck);

    // --- END SET UP ---


    while (!GameOver)
    {
        ++roundnumber;    /// at end of each round reset things like player is out of round, hand's, numbcards, etc.
        winnerindex = 0;
        standingplayers = 0;

        cout << "\nRound Start " << roundnumber << endl;

        for (int i = 1; i < players.size() && players[i].isoutofround == false; ++i)
        { GetPlayerBet(i); }

        DealToAll(2);

        for (int i = 0; i < players.size(); ++i)
        { players[i].handtotal = GetHandTotal(i); }

        /// ----------- If someone other then me actually works on this, remove this line.

        // Players draw or stand until all standing or bust
        while (standingplayers <= players.size())
        {
            for (int i = 0; i < players.size() && players[i].isoutofround == false && players[i].isstanding == false; ++i)
            {
                cout << "Player " << players[i].ID << "'s hand:" << endl;
                PrintDeck(players[i].Hand, players[i].numbcards);

                if (players[i].handtotal  > 21)
                {
                    players[i].isoutofround = true;
                }
                else
                { PlayerChoice(i); }
            }
        }

        // determine who has highest hand total. store hand total in variable to get with funct after draws.
        // need this whole part in loop case people want to keep drawing, end when all have chose to stand.
        // bring in code to determine highest from war


        if (winnerindex != 0)
        {
            // payout say who won
            cout << "Player " << players[winnerindex].ID << " wins the round!" << endl
                 << "Chips won: " << (players[winnerindex].betamount * 2) << endl;
        }
        else
        { cout << "Dealer wins!" << endl; }


        // Payout.
        players[winnerindex].chips += (players[winnerindex].betamount * 2);


        cout << "\nRound end\n";  /// ----- Bellow here can be moved out.

        // Ask each player if they want to play another round.
        for (int i = 1; i < players.size(); ++i)
        {
            cout << "Player " << i << ", would you like to play another round? (y/n)" << endl;
            std::cin >> input;

            if (std::cin.fail()
              || !(input == 'y'
              || input == 'Y'
              || input == 'n'
              || input == 'N'))
            { --i; }

            if (input == 'n' || input == 'N')
            { players.erase(players.begin() + i); }
        }

        // All players other than dealer out of game, end.
        if (players.size() == 1)
        { GameOver = true; }


    }// end of game loop;

}//

///---------------- End Play, used functions below. --------------------------



void Game::SetupPlayer()  /// Add to/remove
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



void Game::DealCards(int _numbofcards, int _playerindex) /// Move to deck options?
{
    for (int i = 0; i < _numbofcards; ++i)
    {
        cout << "Cards dealt to player" << i << endl;

        players[_playerindex].Hand[players[_playerindex].numbcards] = GameDeck.back();
        players[_playerindex].numbcards++;

        GameDeck.pop_back();
    }

}//

void Game::DealToAll(int _numbofcards)
{
    cout << "Cards dealt to all." << endl;

    for (int j = 0; j < players.size() && players[j].isoutofround == false; ++j)
        for (int i = 0; i < _numbofcards; ++i)
    {
        players[j].Hand[players[j].numbcards] = GameDeck.back();
        players[j].numbcards++;
        GameDeck.pop_back();
    }
}//


int Game::GetHandTotal(int _playerindex) const
{
    int total = 0;
    bool containsAce = false;

    for (int i = 0; i < players[_playerindex].numbcards; ++i)
    {
        if (players[_playerindex].Hand[i].GetRank() == Ace)
        {
            containsAce = true;
            total += 11;
        }
        else if (players[_playerindex].Hand[i].GetRank() >= Jack)
        { total += 10; }
        else
        { total += players[_playerindex].Hand[i].GetRank(); }
    }

    if (total > 21 && containsAce)
    {
        total -= 10; // drop ace value down to 1 instead of 11.
    }

    cout << "Hand Total is: " << total << endl << endl;

    return total;
}//


void Game::PlayerChoice(int _playerindex)
{
  // dif case for is dealer.
  if (_playerindex == 0)
  {
      if (players[0].handtotal >= 17)
      { players[0].isstanding = true; }
      else
      { DealCards(1, 0); }
  }
  else
  {
      int input = 0;

      do
      {
          cout << "Player " << _playerindex << ", what will you do?" << endl
               << "1) Stand, 2) Draw" << endl;

          std::cin >> input;


      }while (std::cin.fail()
            || input < 1
            || input > 2);


      // Handle choice
      if (input == 1)
      { players[_playerindex].isstanding = true; }
      else
      { DealCards(1, _playerindex); }

  }// outer else block

}//

