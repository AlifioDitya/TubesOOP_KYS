#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <utility>
#include <vector>

#include "../../enums/CombinationTypes.hpp"
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
    bool ofSameColor(const vector<Card>&);
    bool inSequence(const vector<Card>&);
    bool hasFourOfAKind(const vector<Card>&);
    bool isFullHouse(const vector<Card>&);
    bool hasThreeOfAKind(const vector<Card>&);
    pair<int, int> findPairIdx(const vector<Card>&);

    vector<Card> findBestCombination(const vector<Card>& tableCards, const vector<Card>& handCards);
    ComboTypes findComboType(const vector<Card>&);
    double calculateWeightedValue(vector<Card>, ComboTypes);

   protected:
    vector<Card> tableCards;
    vector<Card> handCards;
    vector<Card> bestCombination;
    ComboTypes comboType;

   public:
    // CTOR
    Combination(const vector<Card>&, const vector<Card>&);

    ~Combination();

    vector<Card> getTableCards() const;
    vector<Card> getHandCards() const;
    vector<Card> getBestCombination() const;
    ComboTypes getComboType() const;
    double getValue() const;
};

#endif