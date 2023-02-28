// DeckCard.cpp
#include "../header/DeckCard.hpp"

int DeckCard::countItems() const {
    return (this->deck).size();
}

void DeckCard::addItem() {
    deck.push_back(Card());
}

void DeckCard::removeItem() {
    if (!deck.empty()) {
        deck.pop_back();
    }
}