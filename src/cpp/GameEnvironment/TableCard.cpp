// TableCard.cpp
#include "../../header/GameEnvironment/TableCard.hpp"
#include <iostream>

using std::cout;
using std::endl;

// Returns the number of items in the inventory
int TableCard::countItems() const {
    return cards.size();
}
// Adds an item to the inventory
void TableCard::addItem(const Card& card) {
    cards.push_back(card);
}

// Removes an item from the inventory
void TableCard::clear() {
    cards.clear();
}

// Show all cards at table that is relevant to current gamestate
vector<Card> TableCard::getCards() {
    return cards;
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