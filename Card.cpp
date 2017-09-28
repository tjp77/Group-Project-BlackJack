#include <iostream>
#include <string>
#include "Card.h"

using std::cout;
using std::endl;

std::string Ranks[] = {"Jack", "Queen", "King", "Ace"};
std::string Suits[] = {" of Clubs", " of Diamonds", " of Hearts", " of Spades"};

void Card::PrintCardName() const
{
    if (rank < 11)
    { cout << rank; }
    else
    { cout << Ranks[rank - 11]; }

    cout << Suits[suit] << endl;

}//


bool Card::operator<(const Card &_card)
{
    if (rank < _card.rank)
        return true;

    return false;

}//





