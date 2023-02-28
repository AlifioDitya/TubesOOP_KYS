// DeckCard.hpp
#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "InventoryHolder.hpp"
#include "Card.hpp"

class DeckCard : public InventoryHolder {
private:
    std::vector<Card> deck;

public:
    virtual int countItems() const;

    // Add a new card to the deck
    virtual void addItem();

    // Remove the top card from the deck
    virtual void removeItem();

    // ...
};

#endif