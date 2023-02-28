// TableCard.cpp
#include "../header/TableCard.hpp"

int TableCard::countItems() const {
    return cards.size();
}

void TableCard::addItem() {
    cards.push_back(Card());
}

void TableCard::removeItem() {
    cards.clear();
}