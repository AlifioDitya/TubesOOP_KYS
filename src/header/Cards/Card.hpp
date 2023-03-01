// Card.hpp
#ifndef CARD_HPP
#define CARD_HPP

#include "../../enums/CardTypes.hpp"
#include "CardInterface.hpp"
#include <string>

using std::string;

class Card : public CardInterface {
   private:
    const Color color;
    const int rank;

   public:
    // Constructor with parameters
    Card(Color, int);

    // Copy constructor
    Card(const Card&);

    // Assignment operator
    Card& operator=(const Card&);

    // Compaarison operator
    bool operator==(const Card&);
    bool operator>(const Card&);
    bool operator<(const Card&);
    bool operator>=(const Card&);
    bool operator<=(const Card&);

    // Getters for color and rank
    Color getColor() const;
    int getRank() const;

    float getValue() const;

    // Get string representation
    string getColorString() const;
};

#endif