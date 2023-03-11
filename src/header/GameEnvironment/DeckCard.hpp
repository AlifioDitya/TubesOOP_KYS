// DeckCard.hpp
#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "InventoryHolder.hpp"
#include <stack>
#include <vector>

using std::vector;
using std::stack;

template <class T>
class DeckCard : public InventoryHolder {

private:
   stack<T> deck;

public:

   DeckCard();

   DeckCard(const vector<T>&);
   
   // Returns the number of items in the inventory
   int countItems() const;

   // Adds an item to the inventory
   void addItem(T);

   // Removes an item from the inventory
   void clear();

   // draw top card
   T drawCard();

   // draw many cards
   vector<T> drawMany(int);
   //...
};

#include "../../cpp/GameEnvironment/DeckCard.cpp"

#endif