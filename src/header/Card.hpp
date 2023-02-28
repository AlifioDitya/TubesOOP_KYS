// Card.hpp
#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using std::string;

class Card {
private:
    string suit;
    string rank;

public:
    // Default constructor
    Card() : suit(""), rank("") {}

    // Constructor with parameters
    Card(string s, string r) : suit(s), rank(r) {}

    // Copy constructor
    Card(const Card& other) : suit(other.suit), rank(other.rank) {}

    // Assignment operator
    Card& operator=(const Card& other) {
        if (this != &other) {
            suit = other.suit;
            rank = other.rank;
        }
        return *this;
    }

    // Equality operator
    bool operator==(const Card& other) const {
        return suit == other.suit && rank == other.rank;
    }

    // Getters for suit and rank
    string getSuit() const {
        return suit;
    }

    string getRank() const {
        return rank;
    }

    // Setters for suit and rank
    void setSuit(string s) {
        suit = s;
    }

    void setRank(string r) {
        rank = r;
    }
};

#endif
