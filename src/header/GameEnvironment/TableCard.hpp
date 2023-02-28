// TableCard.hpp
#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>

class TableCard : public InventoryHolder {

private:
    std::vector<Card> cards;

public:

    // Returns the number of items in the inventory
    virtual int countItems() const;

    // Adds an item to the inventory
    virtual void addItem(Card);

    // Removes an item from the inventory
    virtual void clear();

    // Show all cards at table that is relevant to current gamestate
    std::vector<Card> getCards();

    // ...

#endif
};