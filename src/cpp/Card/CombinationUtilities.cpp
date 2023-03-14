#include "../../header/Cards/CombinationUtilities.hpp"

bool CombinationUtilities::ofSameColor(vector<Card>& cards) {
    int color = cards[0].getColor();
    for (long unsigned int i = 1; i < cards.size(); i++) {
        if (cards[i].getColor() != color)
            return false;
    }
    return true;
}

bool CombinationUtilities::ofSameRank(vector<Card>& cards) {
    int color = cards[0].getRank();
    for (long unsigned int i = 1; i < cards.size(); i++) {
        if (cards[i].getRank() != color)
            return false;
    }
    return true;
}

bool CombinationUtilities::inSequence(vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 1; i++) {
        if (cards[i].getRank() != cards[i + 1].getRank() - 1)
            return false;
    }
    return true;
}

bool CombinationUtilities::isFullHouse(vector<Card>& cards) {
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

bool CombinationUtilities::hasFourOfAKind(vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 3; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank() &&
            cards[i + 2].getRank() == cards[i + 3].getRank())
            return true;
    }
    return false;
}

bool CombinationUtilities::hasThreeOfAKind(vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 2; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank())
            return true;
    }
    return false;
}

bool CombinationUtilities::isTwoPair(vector<Card>& cards) {
    return cards[0] == cards[1] && cards[1] != cards[2] && cards[2] == cards[3];
}

pair<int, int> CombinationUtilities::findPairIdx(vector<Card>& cards) {
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