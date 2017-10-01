#ifndef TESTFUNCTIONS_H_INCLUDED
#define TESTFUNCTIONS_H_INCLUDED

#include "DeckOperations.h"

#include <iostream>
using std::cout;
using std::endl;

void PrintPlayerhands(std::vector<Player> _players)
{
    cout << endl;

    for (int i = 0; i < _players.size(); ++i)
    {
        cout << "Player " << i << " ";
       // PrintDeck(_players[i].Hand, );
    }

    cout << endl;
}//



#endif // TESTFUNCTIONS_H_INCLUDED
