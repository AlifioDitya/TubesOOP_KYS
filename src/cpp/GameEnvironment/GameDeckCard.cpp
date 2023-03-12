#include "../../header/GameEnvironment/GameDeckCard.hpp"

#include <algorithm>
using std::random_shuffle;

GameDeckCard::GameDeckCard() {
    defaultConfig();
}

GameDeckCard::GameDeckCard(const vector<Card>& cards): DeckCard<Card>(cards) {
}

void GameDeckCard::defaultConfig() {
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