// DeckCard.hpp
#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <stack>
#include <vector>

class DeckCard : public InventoryHolder {

private:
   std::stack<Card> deck;

   void shuffle(Card (&cards)[]);

public:

   DeckCard();

   DeckCard(const vector<Card>&);
   // Returns the number of items in the inventory
   virtual int countItems() const;

   // Adds an item to the inventory
   virtual void addItem(Card);

   // Removes an item from the inventory
   virtual void clear();

   Card drawCard();
   //...
};

#endif