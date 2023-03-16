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
    /**
     * @brief Maximum value of High Card combination
     */
    const long double HIGHCARD_MAX = 100;

    /**
     * @brief Maximum value of Pair combination
     */
    const long double PAIR_MAX = 100 + HIGHCARD_MAX;

    /**
     * @brief Maximum value of Two Pair combination
     */
    const long double TWOPAIR_MAX = 100 + PAIR_MAX;

    /**
     * @brief Maximum value of Three of a Kind combination
     */
    const long double THREEOFAKIND_MAX = 100 + TWOPAIR_MAX;

    /**
     * @brief Maximum value of Straight combination
     */
    const long double STRAIGHT_MAX = 100 + THREEOFAKIND_MAX;

    /**
     * @brief Maximum value of Flush combination
     */
    const long double FLUSH_MAX = 300 + STRAIGHT_MAX;

    /**
     * @brief Maximum value of Full House combination
     */
    const long double FULLHOUSE_MAX = 100 + FLUSH_MAX;

    /**
     * @brief Maximum value of Four of a Kind combination
     */
    const long double FOUROFAKIND_MAX = 100 + FULLHOUSE_MAX;

    /**
     * @brief Maximum value of Straight Flush combination
     */
    const long double STRAIGHTFLUSH_MAX = 100 + FOUROFAKIND_MAX;

    /**
     * @brief List of cards in combination
     */
    vector<Card> combinationCards;

    /**
     * @brief Check if list of cards is of the same color
     * @param cards List of cards
     * @return Boolean of list of cards is of the same color
     */
    static bool ofSameColor(const vector<Card>& cards);

    /**
     * @brief Check if list of cards is of the same rank
     * @param cards List of cards
     * @return Boolean of list of cards is of the same rank
     */
    static bool ofSameRank(const vector<Card>& cards);

    /**
     * @brief Check if list of cards is in sequence
     * @param cards List of cards
     * @return Boolean of list of cards is in sequence
     */
    static bool inSequence(const vector<Card>& cards);

    /**
     * @brief Check if list of cards is a four of a kind
     * @param cards List of cards
     * @return Boolean of list of cards is a four of a kind
     */
    static bool hasFourOfAKind(const vector<Card>& cards);

    /**
     * @brief Check if list of cards is a full house
     * @param cards List of cards
     * @return Boolean of list of cards is a full house
     */
    static bool isFullHouse(const vector<Card>& cards);

    /**
     * @brief Check if list of cards is a three of a kind
     * @param cards List of cards
     * @return Boolean of list of cards is a three of a kind
     */
    static bool hasThreeOfAKind(const vector<Card>& cards);

    /**
     * @brief Check if list of cards is a two pair
     * @param cards List of cards
     * @return Boolean of list of cards is a two pair
     */
    static bool isTwoPair(const vector<Card>& cards);

    /**
     * @brief Find pair in list of cards
     * @param cards List of cards
     * @return Pair of indexes of pair of cards in list
     */
    static pair<int, int> findPairIdx(const vector<Card>& cards);

   public:
    /**
     * @brief Construct a new Combination object
     * @param combinationCards List of cards in combination
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