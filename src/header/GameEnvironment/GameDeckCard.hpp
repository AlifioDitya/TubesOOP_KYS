

// GameDeckCard.hpp
#ifndef GAMEDECKCARD_HPP
#define GAMEDECKCARD_HPP

#include "DeckCard.hpp"

class GameDeckCard:public DeckCard<Card> {
    private:
    
    public:

    GameDeckCard();
    GameDeckCard(const vector<Card>&);
    void defaultConfig();

};

#endif