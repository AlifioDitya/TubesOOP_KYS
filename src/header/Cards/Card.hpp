#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#include "../../enums/CardTypes.hpp"
#include "CardInterface.hpp"

using std::ostream;
using std::string;

class Card : public CardInterface {
   private:
    Color color;
    Rank rank;

   public:
    // CTOR with parameters
    Card(Color, Rank);

    // Getters for color and rank
    Color getColor() const;
    Rank getRank() const;
    string getColorString() const;
    string getRankString() const;

    // Getter for weight based on spec (assumed as high card)
    long double getValue() const override;

    friend ostream& operator<<(ostream&, const Card&);
};

#endif