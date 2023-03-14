#include "../../../header/Cards/Combinations/ThreeOfAKind.hpp"

#include <math.h>

#include <algorithm>

#include "../../../header/Cards/CombinationUtilities.hpp"

ThreeOfAKind::ThreeOfAKind(const vector<Card> tableCards, const vector<Card> handCards,
                           const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string ThreeOfAKind::getComboTypeString() const {
    return "Three of a Kind";
}

long double ThreeOfAKind::getValue() const {
    /*
    Rules: Compare by rank of triplet, then color of triplet

    Encoding:
    1. Triplet Rank -> max 1.2 (rank - 1)
    2. Triplet Color -> max 6.3 (color - 1)

    Format: r.rcc -> max:1.3
    */
    long double rank_encoding = (bestCombination[0].getRank() - 1) / 10;

    long double color_encoding = 0;
    for (int i = 0; i < 3; i++) {
        color_encoding += pow(4, i) * bestCombination[i].getColor();
    }
    color_encoding /= 1e3;

    return CombinationUtilities::ComboMaxTimesTen::Flush / 10 + rank_encoding + color_encoding;
}

Combination* ThreeOfAKind::getThreeOfAKind(const vector<Card> tableCards,
                                           const vector<Card> handCards) {
    Combination* maxCombo = NULL;
    long double maxValue = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            Card currentTable_arr[] = {tableCards[i], tableCards[j]};
            vector<Card> currentTable(currentTable_arr, currentTable_arr + 2);

            vector<Card> currentHand;
            currentHand.push_back(handCards[0]);

            vector<Card> cards(currentTable);
            cards.insert(cards.end(), currentHand.begin(), currentHand.end());
            sort(cards.begin(), cards.end());

            if (CombinationUtilities::ofSameRank(cards)) {
                Combination* toak = new ThreeOfAKind(currentTable, currentHand, cards);
                long double value = toak->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = toak;
                    maxValue = value;
                } else {
                    delete toak;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            Card currentTable_arr[] = {tableCards[i], tableCards[j]};
            vector<Card> currentTable(currentTable_arr, currentTable_arr + 2);

            vector<Card> currentHand;
            currentHand.push_back(handCards[1]);

            vector<Card> cards(currentTable);
            cards.insert(cards.end(), currentHand.begin(), currentHand.end());
            sort(cards.begin(), cards.end());

            if (CombinationUtilities::ofSameRank(cards)) {
                Combination* toak = new ThreeOfAKind(currentTable, currentHand, cards);
                long double value = toak->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = toak;
                    maxValue = value;
                } else {
                    delete toak;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        Card currentTable_arr[] = {tableCards[i]};
        vector<Card> currentTable(currentTable_arr, currentTable_arr + 1);

        vector<Card> currentHand(handCards);

        vector<Card> cards(currentTable);
        cards.insert(cards.end(), currentHand.begin(), currentHand.end());
        sort(cards.begin(), cards.end());

        if (CombinationUtilities::ofSameRank(cards)) {
            Combination* toak = new ThreeOfAKind(currentTable, currentHand, cards);
            long double value = toak->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = toak;
                maxValue = value;
            } else {
                delete toak;
            }
        }
    }

    return maxCombo;
}