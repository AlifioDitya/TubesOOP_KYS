#ifndef CARD_HPP
#define CARD_HPP

#include "../../enums/CardTypes.hpp"
#include "CardInterface.hpp"

#include <string>

using std::string;
using std::ostream;

class Card : public CardInterface {
private:
    Color color;
    Rank rank;

public:
    // Ctor
    Card(Color, Rank);

    // ========== Operators ==========
    friend ostream& operator<<(ostream&, const Card&);

    // ========== Getters ==========

    // Getter for color type
    Color getColor() const;
    // Getter for rank type
    Rank getRank() const;
    // Getter for color string
    string getColorString() const;
    // Getter for rank string
    string getRankString() const;
    // Getter for high card value
    double getValue() const;
    
};

#endif