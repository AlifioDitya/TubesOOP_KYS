#include "../../header/Cards/CombinationUtilities.hpp"

#include "../../header/Cards/Combinations/Flush.hpp"
#include "../../header/Cards/Combinations/FourOfAKind.hpp"
#include "../../header/Cards/Combinations/FullHouse.hpp"
#include "../../header/Cards/Combinations/HighCard.hpp"
#include "../../header/Cards/Combinations/Pair.hpp"
#include "../../header/Cards/Combinations/Straight.hpp"
#include "../../header/Cards/Combinations/StraightFlush.hpp"
#include "../../header/Cards/Combinations/ThreeOfAKind.hpp"
#include "../../header/Cards/Combinations/TwoPair.hpp"

Combination* CombinationUtilities::findComboType(const vector<Card>& cards) {
    Combination* combo;
    pair<int, int> cardPair;

    if (ofSameColor(cards) && inSequence(cards)) {
        combo = new StraightFlush(cards);
    } else if (hasFourOfAKind(cards)) {
        combo = new FourOfAKind(cards);
    } else if (isFullHouse(cards)) {
        combo = new FullHouse(cards);
    } else if (ofSameColor(cards)) {
        combo = new Flush(cards);
    } else if (inSequence(cards)) {
        combo = new Straight(cards);
    } else if (hasThreeOfAKind(cards)) {
        combo = new ThreeOfAKind(cards);
    } else if ((cardPair = findPairIdx(cards)).first != -1) {
        combo = new Pair(cards);
        vector<Card> rest;
        rest.insert(rest.end(), cards.begin() + cardPair.second + 1, cards.end());
        if (findPairIdx(rest).first != -1)
            combo = new TwoPair(cards);
    } else {
        combo = new HighCard(cards);
    }

    return combo;
}

bool CombinationUtilities::ofSameColor(const vector<Card>& cards) {
    int color = cards[0].getColor();
    for (long unsigned int i = 1; i < cards.size(); i++) {
        if (cards[i].getColor() != color)
            return false;
    }
    return true;
}

bool CombinationUtilities::inSequence(const vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 1; i++) {
        if (cards[i].getRank() != cards[i + 1].getRank() - 1)
            return false;
    }
    return true;
}

bool CombinationUtilities::isFullHouse(const vector<Card>& cards) {
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

bool CombinationUtilities::hasFourOfAKind(const vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 3; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank() &&
            cards[i + 2].getRank() == cards[i + 3].getRank())
            return true;
    }
    return false;
}

bool CombinationUtilities::hasThreeOfAKind(const vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 2; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank())
            return true;
    }
    return false;
}

pair<int, int> CombinationUtilities::findPairIdx(const vector<Card>& cards) {
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