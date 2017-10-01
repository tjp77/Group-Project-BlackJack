#ifndef DECKOPERATIONS_H
#define DECKOPERATIONS_H

#include "Card.h"

#include <vector>
#include <chrono>
#include <random>
#include <algorithm>


void Shuffle(std::vector<Card> &_deck);
void DeckBuild(std::vector<Card> &_deck);

/// Just pass in player hand instead of the game deck to print their hand.
void PrintDeck(Card const _deck[], int _numbcards, bool _isdealer = false);



#endif // DECKOPERATIONS_H
