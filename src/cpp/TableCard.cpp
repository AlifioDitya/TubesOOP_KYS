// TableCard.cpp
#include "../header/GameEnvironment/TableCard.hpp"


// Returns the number of items in the inventory
int TableCard::countItems() const {
    return cards.size();
}
// Adds an item to the inventory
void TableCard::addItem(Card card) {
    cards.push_back(card);
}

// Removes an item from the inventory
void TableCard::clear() {
    cards.clear();
}

vector<Card> TableCard::getCards() {
    return cards;
}