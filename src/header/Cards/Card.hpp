/**
 * @file Card.hpp
 * @brief Header file for the Card class
 *
 */
#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#include "../../enums/CardTypes.hpp"
#include "CardInterface.hpp"

using std::ostream;
using std::string;

/**
 * @class Card
 * @brief Class that defines a card in game
 * @extends CardInterface
 *
 */
class Card : public CardInterface {
   private:
    Color color;
    Rank rank;

   public:
    Card(Color, Rank);

    // ========== Operators ==========

    /**
     * @brief Operator << overload
     *
     * @return Reference to ostream object
     */
    friend ostream& operator<<(ostream&, const Card&);

    // ========== Getters ==========

    /**
     * @brief Get the Color type of the card
     *
     * @return Color type
     */
    Color getColor() const;

    /**
     * @brief Get the Rank of the card
     *
     * @return Rank
     */
    Rank getRank() const;

    /**
     * @brief Get the string representation of the card color
     *
     * @return Color string
     */
    string getColorString() const;

    /**
     * @brief Get the string representation of the card rank
     *
     * @return Rank string
     */
    string getRankString() const;

    /**
     * @brief Get the High Card value
     *
     * @return Value of high card
     */
    long double getValue() const;
};

#endif