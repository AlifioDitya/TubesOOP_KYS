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
    // initialize stack with cards with random order
    DeckCard() {

    }

    // initialize stack with cards ordered as in config and first-index card being at top
    DeckCard(const vector<T>& config) {
        for (int i = config.size() - 1; i >= 0; i--) {
            deck.push(config[i]);
        }
    }

    // Returns the number of items in the inventory
    int countItems() const {
        return deck.size();
    }

    // Adds an item to the inventory
    void addItem(const T& card) {
        deck.push(card);
    }

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

    void setCards(const vector<T>& cards) {
        deck = stack<T>(deque<T>(cards.begin(), cards.end()));
    }
};

#endif