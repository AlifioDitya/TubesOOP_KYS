// Card.hpp
#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include "../enums/CardTypes.hpp"

using std::string;

class Card {
private:
    Suit suit;
    Rank rank;

public:
    // Default constructor
    Card();

    // Constructor with parameters
    Card(Suit s, Rank r);

    // Copy constructor
    Card(const Card& other);

    // Assignment operator
    Card& operator=(const Card&);

    // Equality operator
    bool operator==(const Card&) const;

    // Getters for suit and rank
    Suit getSuit() const;

    Rank getRank() const;

    // Setters for suit and rank
    void setSuit(Suit s);

    void setRank(Rank r);

    // Get string representation of suit and rank
    string getSuitString() const;
    string getRankString() const;
};

#endif