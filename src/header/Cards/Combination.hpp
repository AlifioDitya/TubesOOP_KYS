#ifndef COMBINATION_HPP
#define COMBINATION_HPP

// #include "../../enums/CombinationTypes.hpp"
#include <utility>
#include <vector>

#include "Card.hpp"

using std::pair;
using std::vector;

/**
 * @class Combination
 * @brief A class representing a combination of cards.
 * @extends CardInterface
 *
 * This class represents a combination of cards, consisting of both table cards and
 * player's hand cards, and provides methods for determining the best possible
 * combination from the available cards.
 */
class Combination : public CardInterface {
   private:
    // vector<Card> findBestCombination(const vector<Card>& tableCards, const vector<Card>&
    // handCards); double calculateWeightedValue(vector<Card>, ComboTypes);

   protected:
    vector<Card> tableCards;
    vector<Card> handCards;
    vector<Card> bestCombination;

   public:
    /**
     * @brief Construct a new Combination object
     *
     */
    Combination(const vector<Card> tableCards, const vector<Card> handCards,
                const vector<Card> bestCombination);

    /**
     * @brief Destroy the Combination object
     *
     */
    ~Combination();

    /**
     * @brief Get the Cards on the table
     *
     * @return Table cards
     */
    vector<Card> getTableCards() const;

    /**
     * @brief Get the Hand Cards
     *
     * @return Hand cards
     */
    vector<Card> getHandCards() const;

    /**
     * @brief Get the Best Combination of cards
     *
     * @return Best card combination
     */
    vector<Card> getBestCombination() const;

    virtual string getComboTypeString() const;  // TODO: IMPLEMENTATION

    /**
     * @brief Get the Value of cards
     *
     * @return Card value
     */
    virtual long double getValue() const = 0;
};

#endif