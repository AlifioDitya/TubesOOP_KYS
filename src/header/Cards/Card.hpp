// Card.hpp
#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#include "../../enums/CardTypes.hpp"
#include "CardInterface.hpp"

using std::string;

class Card : public CardInterface {
   private:
    const Color color;
    const Rank rank;

   public:
    // CTOR with parameters
    Card(Color, Rank);

    // Getters for color and rank
    Color getColor() const;
    Rank getRank() const;

    // Getter for weight based on spec (assumed as high card)
    double getWeightedValue() const;
};

#endif