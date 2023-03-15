#include "../../header/Cards/Combination.hpp"

#include <algorithm>
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::sort;

Combination::Combination(const vector<Card> tableCards, const vector<Card> handCards,
                         const vector<Card> bestCombination)
    : CardInterface(),
      tableCards(tableCards),
      handCards(handCards),
      bestCombination(bestCombination) {
}

Combination::~Combination() {
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

bool Combination::ofSameColor(vector<Card>& cards) {
    int color = cards[0].getColor();
    for (long unsigned int i = 1; i < cards.size(); i++) {
        if (cards[i].getColor() != color)
            return false;
    }
    return true;
}

bool Combination::ofSameRank(vector<Card>& cards) {
    int color = cards[0].getRank();
    for (long unsigned int i = 1; i < cards.size(); i++) {
        if (cards[i].getRank() != color)
            return false;
    }
    return true;
}

bool Combination::inSequence(vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 1; i++) {
        if (cards[i].getRank() != cards[i + 1].getRank() - 1)
            return false;
    }
    return true;
}

bool Combination::isFullHouse(vector<Card>& cards) {
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

bool Combination::hasFourOfAKind(vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 3; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank() &&
            cards[i + 2].getRank() == cards[i + 3].getRank())
            return true;
    }
    return false;
}

bool Combination::hasThreeOfAKind(vector<Card>& cards) {
    for (long unsigned int i = 0; i < cards.size() - 2; i++) {
        if (cards[i].getRank() == cards[i + 1].getRank() &&
            cards[i + 1].getRank() == cards[i + 2].getRank())
            return true;
    }
    return false;
}

bool Combination::isTwoPair(vector<Card>& cards) {
    return cards[0] == cards[1] && cards[1] != cards[2] && cards[2] == cards[3];
}

pair<int, int> Combination::findPairIdx(vector<Card>& cards) {
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

/*
Straight flush:
1. Urutkan rank tertinggi
2. Urutkan warna

Four of a kind:
1. Urutkan rank dari quad

Full House:
1. Urutkan rank dari triplet
2. Urutkan rank dari pair
3. Urutkan warna dari triplet
4. Urutkan warna dari pair

Flush:
1. Urutkan rank kartu tinggi ke rendah
2. Urutkan warna dari flush

Straight:
1. Urutkan rank kartu tertinggi
2. Urutkan warna kartu dari rank tinggi ke rendah

Three of a Kind:
1. Urutkan rank dari triplet
2. Urutkan warna triplet
3. Urutkan value kicker

Two Pair:
1. Urutkan berdasarkan rank pair tinggi
2. Urutkan warna pair tinggi
3. Urutkan rank pair rendah
4. Urutkan warna pair rendah
5. Urutkan value kicker

Pair:
1. Urutkan berdasarkan rank pair
2. Urutkan berdasarkan warna dari pair
3. Urutkan value dari kicker

High Card:
1. Bandingkan berdasarkan value  dari tinggi ke rendah
*/