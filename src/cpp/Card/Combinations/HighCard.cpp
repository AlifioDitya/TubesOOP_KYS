#include "../../../header/Cards/Combinations/HighCard.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

HighCard::HighCard(const vector<Card> tableCards, const vector<Card> handCards,
                   const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string HighCard::getComboTypeString() const {
    return "High Card";
}

long double HighCard::getValue() const {
    return bestCombination[0].getValue();
}

Combination* HighCard::getHighCard(const vector<Card> tableCards, const vector<Card> handCards) {
    Card first = handCards[0];
    Card second = handCards[1];
    Card high = first > second ? first : second;

    vector<Card> emptyTable;
    vector<Card> hand;
    hand.push_back(high);

    return new HighCard(emptyTable, hand, hand);
}