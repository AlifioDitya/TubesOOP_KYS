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
   protected:
    enum ComboMaxTimesTen {
        HighCard = 14,
        Pair = 28,
        TwoPair = 42,
        ThreeOfAKind = 56,
        Straight = 70,
        Flush = 87,
        FullHouse = 101,
        FourOfAKind = 115,
        StraightFlush = 129
    };

    vector<Card> tableCards;
    vector<Card> handCards;
    vector<Card> bestCombination;

    static bool ofSameColor(vector<Card>&);
    static bool ofSameRank(vector<Card>&);
    static bool inSequence(vector<Card>&);
    static bool hasFourOfAKind(vector<Card>&);
    static bool isFullHouse(vector<Card>&);
    static bool hasThreeOfAKind(vector<Card>&);
    static bool isTwoPair(vector<Card>&);
    static pair<int, int> findPairIdx(vector<Card>&);

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

    virtual string getComboTypeString() const = 0;  // TODO: IMPLEMENTATION

    /**
     * @brief Get the Value of cards
     *
     * @return Card value
     */
    virtual long double getValue() const = 0;
};

#endif