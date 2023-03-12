// DeckCard.cpp
#include "../../header/GameEnvironment/DeckCard.hpp"
#include "../../enums/CardTypes.hpp"
#include "../../header/Exception/DeckCardException.hpp"
#include "../../enums/AbilityTypes.hpp"
#include <algorithm>
#include <deque>

using std::stack;
using std::random_shuffle;
using std::deque;

// initialize stack with cards with random order
template<class T>
DeckCard<T>::DeckCard() {
    
    vector<Card> tempCards;

    for (int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= 13; i++)
        {
            tempCards.push_back(Card((Color)i, (Rank)j));
        }
    }

    random_shuffle(tempCards.begin(), tempCards.end());

    for (Card card: tempCards) {
        deck.push(card);
    }
}

template<>
DeckCard<AbilityTypes>::DeckCard() {
    // INISIASI 

    deque<AbilityTypes> temp {Reroll, Quadruple, Quarter, Reverse, SwapCard, Switch, Abilityless};
    random_shuffle(temp.begin(), temp.end());
    deck = stack<AbilityTypes>(temp);

}

// initialize stack with cards ordered as in config and first-index card being at top
template<class T>
DeckCard<T>::DeckCard(const vector<T>& config) {
    
    for (int i = config.size()-1; i >= 0; i--) {
        deck.push(config[i]);
    }
}

// Returns the number of items in the inventory
template<class T>
int DeckCard<T>::countItems() const {
    return deck.size();
}

// Adds an item to the inventory
template<class T>
void DeckCard<T>::addItem(T card) {
    deck.push(card);
}

template<class T>
void DeckCard<T>::clear() {
    
    // stack is automatically destructed after out of scope
    deck = stack<Card>();
}

// Draw top card from deck stack
template<class T>
T DeckCard<T>::drawCard(){

    if (deck.empty()) {
        throw InsufficientCards();
    }
    Card topCard = deck.top();
    deck.pop();

    return topCard;
}

template<class T>
vector<T> DeckCard<T>::drawMany(int amount) {

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
