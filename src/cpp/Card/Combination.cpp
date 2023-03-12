#include "../../header/Cards/Combination.hpp"

#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::sort;

Combination::Combination(const vector<Card>& tableCards, const vector<Card>& handCards)
    : CardInterface(0),
      tableCards(tableCards),
      handCards(handCards),
      bestCombination(findBestCombination(tableCards, handCards)),
      comboType(findComboType(bestCombination)) {
    this->value = calculateWeightedValue(bestCombination, comboType);
}

Combination::~Combination() {
}


ComboTypes Combination::findComboType(const vector<Card>& cards) {
    ComboTypes type;
    pair<int, int> cardPair;

    if (ofSameColor(cards) && inSequence(cards)) {
        type = ComboTypes::StraightFlush;
    } else if (hasFourOfAKind(cards)) {
        type = ComboTypes::FourOfAKind;
    } else if (isFullHouse(cards)) {
        type = ComboTypes::FullHouse;
    } else if (ofSameColor(cards)) {
        type = ComboTypes::Flush;
    } else if (inSequence(cards)) {
        type = ComboTypes::Straight;
    } else if (hasThreeOfAKind(cards)) {
        type = ComboTypes::ThreeOfAKind;
    } else if ((cardPair = findPairIdx(cards)).first != -1) {
        type = ComboTypes::Pair;
        vector<Card> rest;
        rest.insert(rest.end(), cards.begin() + cardPair.second + 1, cards.end());
        if (findPairIdx(rest).first != -1)
            type = ComboTypes::TwoPair;
    } else {
        type = ComboTypes::HighCard;
    }

    return type;
}

vector<Card> Combination::findBestCombination(const vector<Card>& tableCards, const vector<Card>& handCards) {
    vector<Card> cards(tableCards);
    cards.insert(cards.end(), handCards.begin(), handCards.end());
    sort(cards.begin(), cards.end());

    vector<Card> maxCombo;
    double maxValue = 0;

    for (long unsigned int i = 0; i < cards.size() - 1; i++) {
        for (long unsigned int j = i + 1; j < cards.size(); j++) {
            if ((cards[i].getValue() == handCards[0].getValue() ||
                 cards[i].getValue() == handCards[1].getValue()) &&
                (cards[j].getValue() == handCards[0].getValue() ||
                 cards[j].getValue() == handCards[1].getValue()))
                continue;

            vector<Card> currPerm(cards);
            currPerm.erase(currPerm.begin() + j);
            currPerm.erase(currPerm.begin() + i);

            ComboTypes currType = findComboType(currPerm);
            double currValue = calculateWeightedValue(currPerm, currType);

            if (currValue >= maxValue) {
                maxCombo = currPerm;
                maxValue = currValue;
            }
        }
    }

    return maxCombo;
}

double Combination::calculateWeightedValue(vector<Card> cards, ComboTypes type) {
    sort(cards.begin(), cards.end());

    if (type == ComboTypes::StraightFlush)
        return ComboMaxTimesTen::FourOfAKind / 10 + cards[4].getValue();
    if (type == ComboTypes::FourOfAKind)
        return ComboMaxTimesTen::FullHouse / 10 + cards[2].getRank() / 10;
    if (type == ComboTypes::FullHouse)
        return ComboMaxTimesTen::Flush / 10 + cards[2].getRank() / 10;
    if (type == ComboTypes::Flush) {
        int encoded = (1 << cards[0].getRank()) | (1 << cards[1].getRank()) |
                      (1 << cards[2].getRank()) | (1 << cards[3].getRank()) |
                      (1 << cards[4].getRank());
        double flushValue = (double)encoded / 10000 + cards[0].getColor() * 0.00003;
        return ComboMaxTimesTen::Straight / 10 + flushValue;
    }
    if (type == ComboTypes::Straight)
        return ComboMaxTimesTen::ThreeOfAKind / 10 + cards[4].getValue();
    if (type == ComboTypes::ThreeOfAKind)
        return ComboMaxTimesTen::TwoPair / 10 + cards[2].getRank();
    if (type == ComboTypes::TwoPair) {
        Card high = cards[3].getRank() == cards[4].getRank() ? cards[4] : cards[3];
        return ComboMaxTimesTen::Pair / 10 + high.getValue();
    }
    if (type == ComboTypes::Pair)
        return ComboMaxTimesTen::HighCard / 10 + cards[findPairIdx(cards).second].getValue();
    return cards[4].getValue();
}

bool Combination::ofSameColor(const vector<Card>& cards) {
    int color = cards[0].getColor();
    for (long unsigned int i = 1; i < cards.size(); i++) {
        if (cards[i].getColor() != color)
            return false;
    }
    return true;
}

bool Combination::inSequence(const vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 1; i++) {
        if (cards[i].getRank() != cards[i + 1].getRank() - 1)
            return false;
    }
    return true;
}

bool Combination::isFullHouse(const vector<Card>& cards) {
    if (cards.size() == 5) {
        pair<int, int> pairIdx = findPairIdx(cards);
        if (pairIdx.second == 1 || pairIdx.first == 3) {
            vector<Card> rest;
            if (pairIdx.second == 1) {
                rest.insert(rest.end(), cards.begin() + pairIdx.second + 1, cards.end());
            } else {
                rest.insert(rest.end(), cards.begin(), cards.end() - 2);
            }

            if (hasThreeOfAKind(rest))
                return true;
        }
    }
    return false;
}

bool Combination::hasFourOfAKind(const vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 3; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank() &&
            cards[i + 2].getRank() == cards[i + 3].getRank())
            return true;
    }
    return false;
}

bool Combination::hasThreeOfAKind(const vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 2; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank())
            return true;
    }
    return false;
}

pair<int, int> Combination::findPairIdx(const vector<Card>& cards) {
    pair<int, int> cardPairIdx(-1, -1);
    for (long unsigned int i = 0; i < cards.size() - 1; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank()) {
            cardPairIdx.first = i - 1;
            cardPairIdx.second = i;
            return cardPairIdx;
        }
    }
    return cardPairIdx;
}

vector<Card> Combination::getTableCards() const {
    return tableCards;
};
vector<Card> Combination::getHandCards() const {
    return handCards;
}

vector<Card> Combination::getBestCombination() const {
    return bestCombination;
}
ComboTypes Combination::getComboType() const {
    return comboType;
}

double Combination::getValue() const {
    return value;
}