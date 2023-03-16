#include "../../../header/Cards/Combinations/Straight.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

Straight::Straight(const vector<Card>& combinationCards) : Combination(combinationCards) {
}

string Straight::getComboTypeString() const {
    return "Straight";
}

long double Straight::getValue() const {
    /*
    Rules: Compare by rank of highest, then compare by each color
    Encoding:
    1. Rank -> max: 1.2
    2. Color -> max: 1.023

    Format: r.rcccc-> max:1.3
    */

    long double rankEncoding = (long double)(combinationCards[4].getRank() - 1) / 10;

    long double colorEncoding = 0;
    for (int i = 0; i < 5; i++) {
        colorEncoding += pow(4, i) * combinationCards[i].getColor();
    }
    colorEncoding /= 1e5;

    return THREEOFAKIND_MAX + rankEncoding + colorEncoding;
}

Combination* Straight::getStraight(const vector<Card>& tableCards, const vector<Card>& handCards) {
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

        if (inSequence(cards)) {
            Combination* straight = new Straight(cards);
            long double value = straight->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = straight;
                maxValue = value;
            } else {
                delete straight;
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

        if (inSequence(cards)) {
            Combination* straight = new Straight(cards);
            long double value = straight->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = straight;
                maxValue = value;
            } else {
                delete straight;
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

            if (inSequence(cards)) {
                Combination* straight = new Straight(cards);
                long double value = straight->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = straight;
                    maxValue = value;
                } else {
                    delete straight;
                }
            }
        }
    }

    return maxCombo;
}