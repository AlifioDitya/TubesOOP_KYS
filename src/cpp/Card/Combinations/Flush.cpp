#include "../../../header/Cards/Combinations/Flush.hpp"

#include <math.h>

#include <algorithm>

using std::sort;

Flush::Flush(const vector<Card> tableCards, const vector<Card> handCards,
             const vector<Card> bestCombination)
    : Combination(tableCards, handCards, bestCombination) {
}

string Flush::getComboTypeString() const {
    return "Flush";
}

long double Flush::getValue() const {
    /*
    Rules: Compare by rank, if all ranks the same, compare by color
    Encoding:
    1. Rank in Base13 -> max: 371.293 (13^5) (rank - 1)
    2. Color -> max: 3

    Format: r.rrrrrc -> max:3.71
    */

    long double rankEncoding = 0;
    for (int i = 0; i < 5; i++) {
        rankEncoding += pow(13, i) * (bestCombination[i].getRank() - 1);
    }
    rankEncoding /= 1e5;

    long double colorEncoding = bestCombination[0].getColor() / 1e6;

    return ComboMaxTimesTen::Straight / 10 + rankEncoding + colorEncoding;
}

Combination* Flush::getFlush(const vector<Card> tableCards, const vector<Card> handCards) {
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

        if (ofSameColor(cards)) {
            Combination* flush = new Flush(currentTable, currentHand, cards);
            long double value = flush->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = flush;
                maxValue = value;
            } else {
                delete flush;
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

        if (ofSameColor(cards)) {
            Combination* flush = new Flush(currentTable, currentHand, cards);
            long double value = flush->getValue();

            if (maxCombo == NULL || maxValue < value) {
                if (maxCombo != NULL)
                    delete maxCombo;
                maxCombo = flush;
                maxValue = value;
            } else {
                delete flush;
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

            if (ofSameColor(cards)) {
                Combination* flush = new Flush(currentTable, currentHand, cards);
                long double value = flush->getValue();

                if (maxCombo == NULL || maxValue < value) {
                    if (maxCombo != NULL)
                        delete maxCombo;
                    maxCombo = flush;
                    maxValue = value;
                } else {
                    delete flush;
                }
            }
        }
    }

    return maxCombo;
}