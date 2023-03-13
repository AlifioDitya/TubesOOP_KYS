

// GameDeckCard.hpp
#ifndef GAMEDECKCARD_HPP
#define GAMEDECKCARD_HPP

#include "DeckCard.hpp"
#include "../Cards/Card.hpp"

class GameDeckCard:public DeckCard<Card> {
    private:
    
    public:

    // Ctor
    GameDeckCard();

    // User-defined Ctor
    GameDeckCard(const vector<Card>&);

    // ========= Methods ==========
    // inititate cards with random configuration
    void defaultConfig();

};

#endif