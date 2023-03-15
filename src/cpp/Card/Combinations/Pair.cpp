#include "../../../header/Cards/Combinations/Pair.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

Pair::Pair(const vector<Card> tableCards, const vector<Card> handCards,
           const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string Pair::getComboTypeString() const {
    return "Pair";
}

long double Pair::getValue() const {
    /*
    Rules: Compare by value of high, then value for low

    Encoding:
    1. High -> max 1.39
    2. Low -> max 1.39

    Format: h.hhlll -> max:1.4
    */
    long double high = bestCombination[1].getValue();
    long double low = bestCombination[0].getValue() / 1e3;

    return ComboMaxTimesTen::HighCard / 10 + high + low;
}

Combination* Pair::getPair(const vector<Card> tableCards, const vector<Card> handCards) {
    Combination* maxCombo = NULL;
    long double maxValue = 0;

    for (int i = 0; i < 5; i++) {
        vector<Card> currentTable;
        currentTable.push_back(tableCards[i]);

        vector<Card> currentHand;
        currentHand.push_back(handCards[0]);

        vector<Card> cards(currentTable);
        cards.insert(cards.end(), currentHand.begin(), currentHand.end());
        sort(cards.begin(), cards.end());

        if (ofSameRank(cards)) {
            Combination* cardPair = new Pair(currentTable, currentHand, cards);
            long double value = cardPair->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = cardPair;
                maxValue = value;
            } else {
                delete cardPair;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        vector<Card> currentTable;
        currentTable.push_back(tableCards[i]);

        vector<Card> currentHand;
        currentHand.push_back(handCards[1]);

        vector<Card> cards(currentTable);
        cards.insert(cards.end(), currentHand.begin(), currentHand.end());
        sort(cards.begin(), cards.end());

        if (ofSameRank(cards)) {
            Combination* cardPair = new Pair(currentTable, currentHand, cards);
            long double value = cardPair->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = cardPair;
                maxValue = value;
            } else {
                delete cardPair;
            }
        }
    }

    vector<Card> currentTable;

    vector<Card> currentHand(handCards);

    vector<Card> cards(currentHand);
    sort(cards.begin(), cards.end());

    if (ofSameRank(cards)) {
        Combination* cardPair = new Pair(currentTable, currentHand, cards);
        long double value = cardPair->getValue();

        if (maxCombo == NULL || maxValue < value) {
            if (maxCombo != NULL)
                delete maxCombo;
            maxCombo = cardPair;
            maxValue = value;
        } else {
            delete cardPair;
        }
    }

    return maxCombo;
}