// GameState.cpp
#include "../../header/GameEnvironment/CandyGameState.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::find_if;

const uint64_t CandyGameState::initialPoint = 64;
const uint64_t CandyGameState::winnerPoint = 4294967296;

// Default ctor
CandyGameState::CandyGameState() {

}

// Specified ctor
CandyGameState::CandyGameState(const vector<CandyPlayer>& playerList, int roundNum, uint64_t points, 
        const TableCard& tableCard, const GameDeckCard& deckCard, const AbilityDeckCard& abilities, int reversePlayerId):      

    GameState<CandyPlayer>(playerList, roundNum, points, tableCard, deckCard) 
{
    // ABILITIES INITIATION

    this->reversePlayerId = reversePlayerId;
}

// Copy ctor
CandyGameState::CandyGameState(const CandyGameState& gs):GameState<CandyPlayer>(gs) {
    // ABILITIES COPY
    abilities = gs.abilities;
    reversePlayerId = gs.reversePlayerId;
}

// Destructor
CandyGameState::~CandyGameState() {
    // No dynamic allocation
}

// Predicates

bool playerHasUsedAbility(const CandyPlayer& player) {
    return player.hasUsedAbility();
}
bool CandyGameState::hasAllUsedAbility() const {

    for (auto i = playerList.begin() + 1; i != playerList.end(); i++) {
        if (!i -> hasUsedAbility()) return false;
    }

    return true;
}

void CandyGameState::setAbilities(const AbilityDeckCard& abilities) {
    this->abilities = abilities;
}
    
AbilityDeckCard& CandyGameState::getAbilities() {
    return abilities;
}

int CandyGameState::getReversePlayerId() const {
    return reversePlayerId;
}
void CandyGameState::setReversePlayerId(int reversePlayerId) {
    this->reversePlayerId = reversePlayerId;
}

void CandyGameState::setNextTurn() {

    GameState::setNextTurn();

    if (hasAllPlayed())
    {
        if (playerList.back().getId() != reversePlayerId) skipCurrentPlayer();

        // inisiasi round baru
        reversePlayerId = 0;
    }

}
