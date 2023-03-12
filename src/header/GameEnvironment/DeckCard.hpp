// DeckCard.hpp
#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "InventoryHolder.hpp"
#include <stack>
#include <vector>

using std::vector;
using std::stack;

template <class T>
class DeckCard : public InventoryHolder<T> {

protected:
   stack<T> deck;

public:

   DeckCard();

   DeckCard(const vector<T>&);

   // default card configuration
   virtual void defaultConfig() = 0;
   
   // Returns the number of items in the inventory
   int countItems() const;

   // Adds an item to the inventory
   void addItem(const T&);

   // Removes an item from the inventory
   void clear();

   // draw top card
   T drawCard();

   // draw many cards
   vector<T> drawMany(int);

   // set cards
   void setCards(const vector<T>& cards)

   //...
};

#include "../../cpp/GameEnvironment/DeckCard.cpp"

#endif