// Card.cpp
#include "../header/Card.hpp"
#include <string>

using std::string;

// Default ctor
Card::Card(): suit(CLUBS), rank(ACE) {}

// Specified ctor
Card::Card(Suit s, Rank r) : suit(s), rank(r) {}

// cctor
Card::Card(const Card& other) : suit(other.suit), rank(other.rank) {}

// Operator
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        suit = other.suit;
        rank = other.rank;
    }
    return *this;
}

bool Card::operator==(const Card& other) const {
    return suit == other.suit && rank == other.rank;
}

// Getters for suit and rank
Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

// Setters for suit and rank
void Card::setSuit(Suit s) {
    suit = s;
}

void Card::setRank(Rank r) {
    rank = r;
}

// String representations
std::string Card::getSuitString() const {
    switch (suit) {
        case CLUBS:
            return "Clubs";
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        default:
            return "";
    }
}

std::string Card::getRankString() const {
    switch (rank) {
        case ACE:
            return "Ace";
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        default:
            return "";
    }
}