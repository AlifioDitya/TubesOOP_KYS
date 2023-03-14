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
    // vector<Card> findBestCombination(const vector<Card>& tableCards, const vector<Card>&
    // handCards); double calculateWeightedValue(vector<Card>, ComboTypes);

   protected:
    vector<Card> tableCards;
    vector<Card> handCards;
    vector<Card> bestCombination;
    // ComboTypes comboType;

   public:
    Combination(const vector<Card> tableCards, const vector<Card> handCards,
                const vector<Card> bestCombination);

    ~Combination();

    vector<Card> getTableCards() const;
    vector<Card> getHandCards() const;
    vector<Card> getBestCombination() const;
    // ComboTypes getComboType() const;
    virtual string getComboTypeString() const;  // TODO: IMPLEMENTATION

    virtual long double getValue() const = 0;
};

#endif