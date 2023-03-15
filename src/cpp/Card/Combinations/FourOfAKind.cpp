#include "../../../header/Cards/Combinations/FourOfAKind.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

FourOfAKind::FourOfAKind(const vector<Card> tableCards, const vector<Card> handCards,
                         const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string FourOfAKind::getComboTypeString() const {
    return "Four of a Kind";
}

long double FourOfAKind::getValue() const {
    /*
    Rules: Compare by rank of Quad
    Encoding:
    1. Rank -> max 1.2 (rank - 1)

    Format: r.r -> max:1.3
    */

    return ComboMaxTimesTen::FullHouse / 10 + (bestCombination[0].getRank() - 1) / 10;
}

Combination* FourOfAKind::getFourOfAKind(const vector<Card> tableCards,
                                         const vector<Card> handCards) {
    Combination* maxCombo = NULL;
    long double maxValue = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            vector<Card> currentTable(tableCards);
            currentTable.erase(currentTable.begin() + j);
            currentTable.erase(currentTable.begin() + i);

            vector<Card> currentHand(handCards);
            currentHand.erase(currentHand.begin() + 1);

            vector<Card> cards(currentTable);
            cards.insert(cards.end(), currentHand.begin(), currentHand.end());
            sort(cards.begin(), cards.end());

            if (ofSameRank(cards)) {
                Combination* foak = new FourOfAKind(currentTable, currentHand, cards);
                long double value = foak->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = foak;
                    maxValue = value;
                } else {
                    delete foak;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            vector<Card> currentTable(tableCards);
            currentTable.erase(currentTable.begin() + j);
            currentTable.erase(currentTable.begin() + i);

            vector<Card> currentHand(handCards);
            currentHand.erase(currentHand.begin());

            vector<Card> cards(currentTable);
            cards.insert(cards.end(), currentHand.begin(), currentHand.end());
            sort(cards.begin(), cards.end());

            if (ofSameRank(cards)) {
                Combination* foak = new FourOfAKind(currentTable, currentHand, cards);
                long double value = foak->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = foak;
                    maxValue = value;
                } else {
                    delete foak;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            Card currentTable_arr[] = {tableCards[i], tableCards[j]};
            vector<Card> currentTable(currentTable_arr, currentTable_arr + 2);

            vector<Card> currentHand(handCards);

            vector<Card> cards(currentTable);
            cards.insert(cards.end(), currentHand.begin(), currentHand.end());
            sort(cards.begin(), cards.end());

            if (ofSameRank(cards)) {
                Combination* foak = new FourOfAKind(currentTable, currentHand, cards);
                long double value = foak->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = foak;
                    maxValue = value;
                } else {
                    delete foak;
                }
            }
        }
    }

    return maxCombo;
}