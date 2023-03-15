#include "../../../header/Cards/Combinations/FullHouse.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

FullHouse::FullHouse(const vector<Card> tableCards, const vector<Card> handCards,
                     const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string FullHouse::getComboTypeString() const {
    return "Full House";
}

long double FullHouse::getValue() const {
    /*
    Rules: Compare by rank of triplet, then rank of pair,
           then color of triplet,then color of pair

    Encoding:
    1. Triplet Rank -> max 1.2 (rank - 1)
    2. Pair Rank -> max 1.2 (rank - 1)
    3. Triplet Color -> max 6.3 (color - 1)
    3. Pair Color -> max 1.5 (4^2)

    Format: t.tppttpp -> max:1.3
    */
    vector<Card> triplet;
    vector<Card> pair;

    if (bestCombination[2].getRank() == bestCombination[1].getRank()) {
        pair.insert(pair.end(), bestCombination.begin() + 3, bestCombination.end());
        triplet.insert(triplet.end(), bestCombination.begin(), bestCombination.begin() + 3);
    } else {
        pair.insert(pair.end(), bestCombination.begin(), bestCombination.begin() + 2);
        triplet.insert(triplet.end(), bestCombination.begin() + 2, bestCombination.end());
    }

    long double tr_encoding = (triplet[0].getRank() - 1) / 10;
    long double pr_encoding = (pair[0].getRank() - 1) / 1000;

    long double tc_encoding = 0;
    for (int i = 0; i < 3; i++) {
        tc_encoding += pow(4, i) * triplet[i].getColor();
    }
    tc_encoding /= 1e5;

    long double pc_encoding = 0;
    for (int i = 0; i < 2; i++) {
        pc_encoding += pow(4, i) * pair[i].getColor();
    }
    pc_encoding /= 1e7;

    return FLUSH_MAX + tr_encoding + pr_encoding + tc_encoding + pc_encoding;
}

Combination* FullHouse::getFullHouse(const vector<Card> tableCards, const vector<Card> handCards) {
    Combination* maxCombo = NULL;
    long double maxValue = 0;

    for (int i = 0; i < 5; i++) {
        vector<Card> currentTable(tableCards);
        currentTable.erase(currentTable.begin() + i);

        vector<Card> currentHand(handCards);
        currentHand.erase(currentHand.begin() + 1);

        vector<Card> cards(currentTable);
        cards.insert(cards.end(), currentHand.begin(), currentHand.end());
        sort(cards.begin(), cards.end());

        if (isFullHouse(cards)) {
            Combination* fullHouse = new FullHouse(currentTable, currentHand, cards);
            long double value = fullHouse->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = fullHouse;
                maxValue = value;
            } else {
                delete fullHouse;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        vector<Card> currentTable(tableCards);
        currentTable.erase(currentTable.begin() + i);

        vector<Card> currentHand(handCards);
        currentHand.erase(currentHand.begin());

        vector<Card> cards(currentTable);
        cards.insert(cards.end(), currentHand.begin(), currentHand.end());
        sort(cards.begin(), cards.end());

        if (isFullHouse(cards)) {
            Combination* fullHouse = new FullHouse(currentTable, currentHand, cards);
            long double value = fullHouse->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = fullHouse;
                maxValue = value;
            } else {
                delete fullHouse;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            vector<Card> currentTable(tableCards);
            currentTable.erase(currentTable.begin() + j);
            currentTable.erase(currentTable.begin() + i);

            vector<Card> currentHand(handCards);

            vector<Card> cards(currentTable);
            cards.insert(cards.end(), currentHand.begin(), currentHand.end());
            sort(cards.begin(), cards.end());

            if (isFullHouse(cards)) {
                Combination* fullHouse = new FullHouse(currentTable, currentHand, cards);
                long double value = fullHouse->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = fullHouse;
                    maxValue = value;
                } else {
                    delete fullHouse;
                }
            }
        }
    }

    return maxCombo;
}