#include "DeckOperations.h"

#include <iostream>

using std::cout;
using std::endl;
using std::vector;


void Shuffle(vector<Card> &_deck)
{
    std::random_shuffle(_deck.begin(), _deck.end());

}//


void DeckBuild(vector<Card> &_deck)
{
    _deck.resize(52);

    for(int i = 0, s = Club; s <= Spade; ++s)
        for (int r = Two; r <= Ace; ++r)
    {
        _deck[i++] = Card((Suit)s, (Rank)r);
    }

}//


void PrintDeck(Card const _deck[], int _numbcards, bool _isdealer)
{
    int i = 0;

    // Skip over showing dealer's first card.
    if (_isdealer)
    {
        cout << "Face Down Card." << endl;
        ++i;
    }

    for (; i < _numbcards; ++i)  /// Depending on how we want to print out cards either add a space or new line after
    { _deck[i].PrintCardName(); }

}//
