// GameDeckCard.cpp
#include "../../header/GameEnvironment/GameDeckCard.hpp"
#include "../../header/GameEnvironment/DeckCard.hpp"
#include <algorithm>
#include <iostream>
using std::random_shuffle;

GameDeckCard::GameDeckCard() {
    defaultConfig();
}

GameDeckCard::GameDeckCard(const vector<Card>& cards) : DeckCard<Card>(cards) {}

// ========= Methods ==========

void GameDeckCard::defaultConfig() {
    vector<Card> tempCards;

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            tempCards.push_back(Card((Color) i, (Rank) j));
        }
    }

    srand(time(NULL));
    
    random_shuffle(tempCards.begin(), tempCards.end());

    temp = vector<Card> (tempCards.rbegin(), tempCards.rend()); // testing
    clear();
    // for (auto card: tempCards) std::cout << card << std::endl;
    for (Card card: tempCards) {
        deck.push(card);
    }
}