#ifndef CARD_H
#define CARD_H

enum Suit {Club, Diamond, Heart, Spade};

enum Rank {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
           Jack = 10, Queen = 10, King = 10, Ace = 11};

class Card
{
    private:

    Suit suit;
    Rank rank;


    public:

    Card() = default;

    Card(Suit _suit, Rank _rank) : suit(_suit), rank(_rank)
    {};

    // Prints: "Rank: -card rank-, Suit: -card suit-"
    void PrintCardName() const;

    bool operator<(const Card &_card);

    Suit GetSuit() const { return suit; }
    Rank GetRank() const { return rank; }

};

#endif // CARD_H
