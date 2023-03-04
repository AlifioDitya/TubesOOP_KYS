// GameState.cpp
#include "../../header/GameEnvironment/CandyGameState.hpp"

#include <iostream>

using std::cout;
using std::endl;

// Default ctor
CandyGameState::CandyGameState() {

}

// Specified ctor
CandyGameState::CandyGameState(vector<CandyPlayer> playerList, int currentTurn, int roundNum, int points, TableCard tableCard, DeckCard deckCard):          
    GameState<CandyPlayer>(playerList, currentTurn, roundNum, points, tableCard, deckCard) 
{

}

// Copy ctor
CandyGameState::CandyGameState(const CandyGameState& gs):GameState<CandyPlayer>(gs) {
}

// Destructor
CandyGameState::~CandyGameState() {
    // No dynamic allocation
}

// Predicates
bool CandyGameState::hasAllUsedAbility() {
    for (CandyPlayer p: this->playerList) {
        if (!p.hasUsedAbility()) {
            return false;
        }
    }

    return true;
}
