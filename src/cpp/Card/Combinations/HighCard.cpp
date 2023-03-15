#include "../../../header/Cards/Combinations/HighCard.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

HighCard::HighCard(const vector<Card>& combinationCards) : Combination(combinationCards) {
}

string HighCard::getComboTypeString() const {
    return "High Card";
}

long double HighCard::getValue() const {
    return combinationCards[0].getValue();
}

Combination* HighCard::getHighCard(const vector<Card>& tableCards, const vector<Card>& handCards) {
    Card high = handCards[0] > handCards[1] ? handCards[0] : handCards[1];

    vector<Card> hand;
    hand.push_back(high);

    return new HighCard(hand);
}