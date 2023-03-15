#include "../../../header/Cards/Combinations/StraightFlush.hpp"

#include <math.h>

#include <algorithm>

StraightFlush::StraightFlush(const vector<Card> tableCards, const vector<Card> handCards,
                             const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string StraightFlush::getComboTypeString() const {
    return "Straight Flush";
}

long double StraightFlush::getValue() const {
    /*
    Rules: Compare by value of highest
    Encoding:
    Like high card

    Format: h.hh -> max:1.4
    */

    return ComboMaxTimesTen::FourOfAKind / 10 + bestCombination[4].getValue();
}

Combination* StraightFlush::getStraightFlush(const vector<Card> tableCards,
                                             const vector<Card> handCards) {
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

        if (inSequence(cards) && ofSameColor(cards)) {
            Combination* straightFlush = new StraightFlush(currentTable, currentHand, cards);
            long double value = straightFlush->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = straightFlush;
                maxValue = value;
            } else {
                delete straightFlush;
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

        if (inSequence(cards) && ofSameColor(cards)) {
            Combination* straightFlush = new StraightFlush(currentTable, currentHand, cards);
            long double value = straightFlush->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = straightFlush;
                maxValue = value;
            } else {
                delete straightFlush;
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

            if (inSequence(cards) && ofSameColor(cards)) {
                Combination* straightFlush = new StraightFlush(currentTable, currentHand, cards);
                long double value = straightFlush->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = straightFlush;
                    maxValue = value;
                } else {
                    delete straightFlush;
                }
            }
        }
    }

    return maxCombo;
}