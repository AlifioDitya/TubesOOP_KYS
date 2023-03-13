// TableCard.hpp
#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"
#include <vector>

using std::vector;

class TableCard : public InventoryHolder<Card> {
private:
    std::vector<Card> cards;
public:
    // Returns the number of items in the inventory
    virtual int countItems() const;

    // Adds an item to the inventory
    virtual void addItem(const Card&);

    // Removes an item from the inventory
    virtual void clear();

    // Show all cards at table that is relevant to current gamestate
    vector<Card> getCards();

    void setCards(const vector<Card>& cards);

    void showCards();
};

#endif
