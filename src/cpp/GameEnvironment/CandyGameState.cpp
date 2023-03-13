// GameState.cpp
#include "../../header/GameEnvironment/CandyGameState.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::find_if;

const long long CandyGameState::initialPoint = 64;
const long long CandyGameState::winnerPoint = 4294967296;

// Default ctor
CandyGameState::CandyGameState() {

}

// Specified ctor
CandyGameState::CandyGameState(const vector<CandyPlayer>& playerList, int roundNum, int points, 
        const TableCard& tableCard, const GameDeckCard& deckCard, const AbilityDeckCard& abilities, bool isReversed):      

    GameState<CandyPlayer>(playerList, roundNum, points, tableCard, deckCard) 
{
    // ABILITIES INITIATION

    this->isReversed = isReversed;
}

// Copy ctor
CandyGameState::CandyGameState(const CandyGameState& gs):GameState<CandyPlayer>(gs) {
    // ABILITIES COPY
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

    for (CandyPlayer p: this->playerList) {
        if (!p.hasUsedAbility()) {
            return false;
        }
    }

    return true;
}

void CandyGameState::setAbilities(const AbilityDeckCard& abilities) {
    this->abilities = abilities;
}
    
AbilityDeckCard& CandyGameState::getAbilities() {
    return abilities;
}

bool CandyGameState::getIsReversed() const {
    return isReversed;
}
void CandyGameState::setIsReversed(bool isReverse) {
    this->isReversed = isReverse;
}

void CandyGameState::setNextTurn() {

    GameState::setNextTurn();

    if (hasAllPlayed()) skipCurrentPlayer();

}
