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
    const long double HIGHCARD_MAX = 1.4;
    const long double PAIR_MAX = 1.4 + HIGHCARD_MAX;
    const long double TWOPAIR_MAX = 1.3 + PAIR_MAX;
    const long double THREEOFAKIND_MAX = 1.3 + TWOPAIR_MAX;
    const long double STRAIGHT_MAX = 1.3 + THREEOFAKIND_MAX;
    const long double FLUSH_MAX = 3.8 + STRAIGHT_MAX;
    const long double FULLHOUSE_MAX = 1.3 + FLUSH_MAX;
    const long double FOUROFAKIND_MAX = 1.3 + FULLHOUSE_MAX;
    const long double STRAIGHTFLUSH_MAX = 1.4 + FOUROFAKIND_MAX;

    vector<Card> combinationCards;

    static bool ofSameColor(const vector<Card>&);
    static bool ofSameRank(const vector<Card>&);
    static bool inSequence(const vector<Card>&);
    static bool hasFourOfAKind(const vector<Card>&);
    static bool isFullHouse(const vector<Card>&);
    static bool hasThreeOfAKind(const vector<Card>&);
    static bool isTwoPair(const vector<Card>&);
    static pair<int, int> findPairIdx(const vector<Card>&);

   public:
    /**
     * @brief Construct a new Combination object
     *
     */
    Combination(const vector<Card>& combinationCards);

    /**
     * @brief Destroy the Combination object
     *
     */
    ~Combination();

    /**
     * @brief Get the Best Combination of cards
     *
     * @return Best card combination
     */
    vector<Card> getCombinationCards() const;

    /**
     * @brief Get string representation of combination type
     *
     * @return Best card combination
     */
    virtual string getComboTypeString() const = 0;

    /**
     * @brief Get the Value of cards
     *
     * @return Card value
     */
    virtual long double getValue() const = 0;
};

#endif