/**
 * @file DeckCard.hpp
 * @brief Header file for the class DeckCard
 * 
 */
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

/**
 * @class DeckCard
 * @brief Class that holds the deck cards in a given card game.
 * @extends InventoryHolder
 * 
 * @tparam T type of the elements in the deck 
 */
template <class T>
class DeckCard : public InventoryHolder<T> {
   protected:
   /**
    * @brief Stack that holds the deck
    * 
    */
    stack<T> deck;

   public:

    /**
     * @brief Construct a new Deck of Cards
     * 
     */
    DeckCard() {

    }

    /**
     * @brief a Virtual function to be overriden for default configurations of the deck
     * 
     */
    virtual void defaultConfig() = 0;

    /**
     * @brief Copy constructs a new Deck Card object. Initializes stack with cards ordered as in config
     * and first-index card being at top
     * 
     * @param config Configuration for the deck order
     */
    DeckCard(const vector<T>& config) {
        for (int i = config.size() - 1; i >= 0; i--) {
            deck.push(config[i]);
        }
    }

    /**
     * @brief Counts the items in a deck
     * 
     * @return Integer value of the number of items in the inventory
     */
    int countItems() const {
        return deck.size();
    }

    /**
     * @brief Adds an item to the inventory
     * 
     * @param card Card to be added to the inventory
     */
    void addItem(const T& card) {
        deck.push(card);
    }

    /**
     * @brief Clear all of the cards in the inventory
     * 
     */
    void clear() {
        while (!deck.empty()) deck.pop();
    }

    /**
     * @brief Draws the top card of a deck
     * 
     * @return Element at the top of the deck
     */
    T drawCard() {
        if (deck.empty()) {
            throw InsufficientCards();
        }
        T topCard = deck.top();
        deck.pop();

        return topCard;
    }

    /**
     * @brief Draws multiple cards from the top of the stack
     * 
     * @param amount integer value of the amount of cards to be drawn
     * @return a vector of cards that are drawn.
     */
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

    /**
     * @brief Set the list of cards
     * 
     * @param cards Vector of cards to be set
     */
    void setCards(const vector<T>& cards) {
        deck = stack<T>(deque<T>(cards.rbegin(), cards.rend()));
    }
};

#endif