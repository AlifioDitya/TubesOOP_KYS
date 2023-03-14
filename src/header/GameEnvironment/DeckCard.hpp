// DeckCard.hpp
#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include <algorithm>
#include <deque>
#include <stack>
#include <vector>

#include "../../enums/AbilityTypes.hpp"
#include "../../enums/CardTypes.hpp"
#include "../../header/Exception/DeckCardException.hpp"
#include "InventoryHolder.hpp"

using std::deque;
using std::random_shuffle;
using std::stack;
using std::vector;

template <class T>
class DeckCard : public InventoryHolder<T> {
   protected:
    stack<T> deck;

   public:

    // Ctor
    DeckCard() {

    }

    virtual void defaultConfig() = 0;

    // User-defined Ctor
    // initialize stack with cards ordered as in config and first-index card being at top
    DeckCard(const vector<T>& config) {
        for (int i = config.size() - 1; i >= 0; i--) {
            deck.push(config[i]);
        }
    }

    // ========= Getters ==========

    // Returns the number of items in the inventory
    int countItems() const {
        return deck.size();
    }

    // ========= Setters/Other Methods ==========

    // Adds an item to the inventory
    void addItem(const T& card) {
        deck.push(card);
    }

    // clear all cards
    void clear() {
        while (!deck.empty()) deck.pop();
    }

    // Draw top card from deck stack
    T drawCard() {
        if (deck.empty()) {
            throw InsufficientCards();
        }
        T topCard = deck.top();
        deck.pop();

        return topCard;
    }

    // Draw many cards from top of stack
    vector<T> drawMany(int amount) {
        vector<Card> drawCards;

        if (this->countItems() < amount) {
            throw InsufficientCards();
        }

        for (int i = 0; i < amount; i++) {
            drawCards.push_back(deck.top());
            deck.pop();
        }

        return drawCards;
    }

    // setter for deck atribute
    void setCards(const vector<T>& cards) {
        deck = stack<T>(deque<T>(cards.rbegin(), cards.rend()));
    }
};

#endif