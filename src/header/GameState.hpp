// GameState.hpp
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Player.hpp"
#include "DeckCard.hpp"
#include "TableCard.hpp"
#include <vector>

using std::vector;

class GameState {
private:
    vector<Player> PlayerList;
    int currentTurnIdx;
    TableCard tableCards;
    DeckCard deckCards;

public:
    // Default ctor
    GameState();

    // Specified ctor
    // GameState(PlayerList, int, TableCard, DeckCard);
};

#endif