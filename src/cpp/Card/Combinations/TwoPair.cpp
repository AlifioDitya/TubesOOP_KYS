#include "../../../header/Cards/Combinations/TwoPair.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

TwoPair::TwoPair(const vector<Card> tableCards, const vector<Card> handCards,
                 const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string TwoPair::getComboTypeString() const {
    return "Two Pair";
}

long double TwoPair::getValue() const {
    /*
    Rules: Compare by rank of high pair, then rank of low pair,
           then color of high pair,then color of low pair

    Encoding:
    1. High Rank -> max 1.2 (rank - 1)
    2. Low Rank -> max 1.2 (rank - 1)
    3. High Color -> max 1.5 (color - 1)
    3. Low Color -> max 1.5 (4^2)

    Format: h.hllhhll -> max:1.3
    */
    vector<Card> high(bestCombination.begin() + 2, bestCombination.end());
    vector<Card> low(bestCombination.begin(), bestCombination.begin() + 2);

    long double hr_encoding = (high[0].getRank() - 1) / 10;
    long double lr_encoding = (low[0].getRank() - 1) / 1000;

    long double hc_encoding = 0;
    for (int i = 0; i < 3; i++) {
        hc_encoding += pow(4, i) * high[i].getColor();
    }
    hc_encoding /= 1e5;

    long double lc_encoding = 0;
    for (int i = 0; i < 2; i++) {
        lc_encoding += pow(4, i) * low[i].getColor();
    }
    lc_encoding /= 1e7;

    return ComboMaxTimesTen::Flush / 10 + hr_encoding + lr_encoding + hc_encoding + lc_encoding;
}

Combination* TwoPair::getTwoPair(const vector<Card> tableCards, const vector<Card> handCards) {
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

            if (isTwoPair(cards)) {
                Combination* twoPair = new TwoPair(currentTable, currentHand, cards);
                long double value = twoPair->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = twoPair;
                    maxValue = value;
                } else {
                    delete twoPair;
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

            if (isTwoPair(cards)) {
                Combination* twoPair = new TwoPair(currentTable, currentHand, cards);
                long double value = twoPair->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = twoPair;
                    maxValue = value;
                } else {
                    delete twoPair;
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

            if (isTwoPair(cards)) {
                Combination* twoPair = new TwoPair(currentTable, currentHand, cards);
                long double value = twoPair->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = twoPair;
                    maxValue = value;
                } else {
                    delete twoPair;
                }
            }
        }
    }

    return maxCombo;
}