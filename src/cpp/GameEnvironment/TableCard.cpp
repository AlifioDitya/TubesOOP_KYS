// TableCard.cpp
#include "../../header/GameEnvironment/TableCard.hpp"
#include <iostream>

using std::cout;
using std::endl;

// ========== Getters ==========

int TableCard::countItems() const {
    return cards.size();
}

vector<Card> TableCard::getCards() {
    return cards;
}

// ========== Setters / Other Methods ==========

void TableCard::clear() {
    cards.clear();
}

void TableCard::addItem(const Card& card) {
    cards.push_back(card);
}

void TableCard::setCards(const vector<Card>& cards) {
    this->cards = cards;
}

void TableCard::showCards() {
    bool first = true;
    cout << "[";
    for (auto card : cards) {
        if (first) first = false;
        else cout << ", ";
        
        cout << card;
    }
    cout << "]" << endl;
}