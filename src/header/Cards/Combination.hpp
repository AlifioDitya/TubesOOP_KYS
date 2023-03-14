#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <utility>
#include <vector>

// #include "../../enums/CombinationTypes.hpp"
#include "Card.hpp"

using std::pair;
using std::vector;

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

    // vector<Card> findBestCombination(const vector<Card>& tableCards, const vector<Card>&
    // handCards); double calculateWeightedValue(vector<Card>, ComboTypes);

   protected:
    vector<Card> tableCards;
    vector<Card> handCards;
    vector<Card> bestCombination;
    // ComboTypes comboType;

   public:
    Combination(const vector<Card> tableCards, const vector<Card> handCards);

    ~Combination();

    vector<Card> getTableCards() const;
    vector<Card> getHandCards() const;
    vector<Card> getBestCombination() const;
    // ComboTypes getComboType() const;
    virtual string getComboTypeString() const;  // TODO: IMPLEMENTATION

    virtual double getValue() const = 0;
};

#endif