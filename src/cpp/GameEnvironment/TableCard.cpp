// TableCard.cpp
using namespace std;

#include "../../header/GameEnvironment/TableCard.hpp"


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

vector<Card> TableCard::getCards() {
    return cards;
}

void TableCard::setCards(const vector<Card>& cards) {
    this->cards = cards;
} 