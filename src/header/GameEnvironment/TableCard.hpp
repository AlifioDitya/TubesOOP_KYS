// TableCard.hpp
#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"

class TableCard : public InventoryHolder {
private:
    std::vector<Card> cards;

public:
    virtual int countItems() const;

    // Add a new card to the table
    virtual void addItem();

    // Remove all cards from the table
    virtual void removeItem();

    // ...

#endif
};