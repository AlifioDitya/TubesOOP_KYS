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

// double Combination::calculateWeightedValue(vector<Card> cards, ComboTypes type) {
//     sort(cards.begin(), cards.end());

//     if (type == ComboTypes::StraightFlush)
//         return ComboMaxTimesTen::FourOfAKind / 10 + cards[4].getValue();
//     if (type == ComboTypes::FourOfAKind)
//         return ComboMaxTimesTen::FullHouse / 10 + cards[2].getRank() / 10;
//     if (type == ComboTypes::FullHouse)
//         return ComboMaxTimesTen::Flush / 10 + cards[2].getRank() / 10;
//     if (type == ComboTypes::Flush) {
//         int encoded = (1 << cards[0].getRank()) | (1 << cards[1].getRank()) |
//                       (1 << cards[2].getRank()) | (1 << cards[3].getRank()) |
//                       (1 << cards[4].getRank());
//         double flushValue = (double)encoded / 10000 + cards[0].getColor() * 0.00003;
//         return ComboMaxTimesTen::Straight / 10 + flushValue;
//     }
//     if (type == ComboTypes::Straight)
//         return ComboMaxTimesTen::ThreeOfAKind / 10 + cards[4].getValue();
//     if (type == ComboTypes::ThreeOfAKind)
//         return ComboMaxTimesTen::TwoPair / 10 + cards[2].getRank();
//     if (type == ComboTypes::TwoPair) {
//         Card high = cards[3].getRank() == cards[4].getRank() ? cards[4] : cards[3];
//         return ComboMaxTimesTen::Pair / 10 + high.getValue();
//     }
//     if (type == ComboTypes::Pair)
//         return ComboMaxTimesTen::HighCard / 10 + cards[findPairIdx(cards).second].getValue();
//     return cards[4].getValue();
// }

vector<Card> Combination::getTableCards() const {
    return tableCards;
};
vector<Card> Combination::getHandCards() const {
    return handCards;
}

vector<Card> Combination::getBestCombination() const {
    return bestCombination;
}
// ComboTypes Combination::getComboType() const {
//     return comboType;
// }

string Combination::getComboTypeString() const {
    // map<ComboTypes, string> comboMap = {
    //     {ComboTypes::HighCard, "High Card"},
    //     {ComboTypes::Pair, "Pair"},
    //     {ComboTypes::TwoPair, "Two Pair"},
    //     {ComboTypes::ThreeOfAKind, "Three of a Kind"},
    //     {ComboTypes::Straight, "Straight"},
    //     {ComboTypes::Flush, "Flush"},
    //     {ComboTypes::FullHouse, "Full House"},
    //     {ComboTypes::FourOfAKind, "Four of a Kind"},
    //     {ComboTypes::StraightFlush, "Straight Flush"},
    // };

    return "belom";
    // return comboMap[comboType];
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