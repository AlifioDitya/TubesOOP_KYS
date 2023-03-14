#ifndef COMBINATION_HPP
#define COMBINATION_HPP


#include "../../enums/CombinationTypes.hpp"
#include "Card.hpp"

#include <utility>
#include <vector>

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

    /**
     * @brief Predicate to check whether a list of cards are of the same color
     * 
     * @return true if list contains same color of cards, 
     * @return false otherwise
     */
    bool ofSameColor(const vector<Card>&);

    /**
     * @brief Predicate to check whether there are a contigous sequence of ranks in the list of cards
     * 
     * @return true if list contains a sequence, 
     * @return false otherwise
     */
    bool inSequence(const vector<Card>&);

    /**
     * @brief Predicate to check whether the list of cards contains a four of a kind.
     * 
     * @return true if list contains four of a kind, 
     * @return false otherwise
     */
    bool hasFourOfAKind(const vector<Card>&);

    /**
     * @brief Predicate to check whether the list of cards contains a full house.
     * 
     * @return true if list contains full house, 
     * @return false otherwise
     */
    bool isFullHouse(const vector<Card>&);

    /**
     * @brief Predicate to check whether the list of cards contains a three of a kind.
     * 
     * @return true if list contains three of a kind, 
     * @return false otherwise
     */
    bool hasThreeOfAKind(const vector<Card>&);

    /**
     * @brief Finds the index of a pair
     * 
     * @return Card pair index
     */
    pair<int, int> findPairIdx(const vector<Card>&);

    /**
     * @brief Finds the best possible combination of cards from the available table and hand cards.
     * 
     * This method determines the best possible combination of cards from the available table 
     * and hand cards, based on the combination types defined in the CombinationTypes enum.
     * 
     * @param tableCards The cards on the table.
     * @param handCards The player's hand cards.
     * @return The best possible combination of cards.
     */
    vector<Card> findBestCombination(const vector<Card>& tableCards, const vector<Card>& handCards);

    /**
     * @brief Finds the combination type of the cards in a list
     * 
     * This method determines the combination type of a given list of cards
     * 
     * @param cardList List of cards to search for combinations
     * @return Combination type
     */
    ComboTypes findComboType(const vector<Card>&);

    /**
     * @brief Finds the weighted value of the given card list
     * 
     * This method calculated a value of the given card list by weighted sum
     * 
     * @return Value of the cards
     */
    double calculateWeightedValue(vector<Card>, ComboTypes);

protected:
    vector<Card> tableCards;
    vector<Card> handCards;
    vector<Card> bestCombination;
    ComboTypes comboType;

public:
    /**
     * @brief Construct a new Combination object
     *
     */
    Combination(const vector<Card>&, const vector<Card>&);

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

    /**
     * @brief Get the Combination type of cards
     * 
     * @return Combination type
     */
    ComboTypes getComboType() const;

    /**
     * @brief Get the Value of cards
     * 
     * @return Card value
     */
    double getValue() const;
};

#endif