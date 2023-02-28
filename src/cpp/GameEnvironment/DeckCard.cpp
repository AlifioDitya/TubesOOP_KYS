// DeckCard.cpp
#include "../../header/GameEnvironment/DeckCard.hpp"
#include "../enums/CardTypes.hpp"
#include "algorithm"

using namespace std;

// initialize stack with cards with random order

DeckCard::DeckCard() {
    
    vector<Card> tempCards;

    for (int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= 13; i++)
        {
            tempCards.push_back(Card((Suit)i, (Rank)j));
        }
    }

    random_shuffle(tempCards.begin(), tempCards.end());

    for (Card card: tempCards) {
        deck.push(card);
    }
}

// initialize stack with cards ordered as in config and first-index card being at top
DeckCard::DeckCard(const vector<Card>& config) {
    
    for (int i = config.size()-1; i >= 0; i--) {
        deck.push(config[i]);
    }
}

// Returns the number of items in the inventory
int DeckCard::countItems() const {
    return deck.size();
}

// Adds an item to the inventory
void DeckCard::addItem(Card card) {
    deck.push(card);
}

void DeckCard::clear() {
    
    // stack is automatically destructed after out of scope
    deck = stack<Card>();
}

// Draw top card from deck stack
Card DeckCard::drawCard(){

    Card topCard = deck.top();
    deck.pop();

    return topCard;
}