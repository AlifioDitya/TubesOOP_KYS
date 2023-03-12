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
        const TableCard& tableCard, const DeckCard<Card>& deckCard, const DeckCard<AbilityTypes>& abilities, bool isReversed):      

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

void CandyGameState::setAbilities(const DeckCard<AbilityTypes>& abilities) {
    this->abilities = abilities;
}
    
DeckCard<AbilityTypes>& CandyGameState::getAbilities() {
    return abilities;
}

void CandyGameState::setNextTurn() {

    GameState::setNextTurn();

    if (hasAllPlayed()) skipCurrentPlayer();
    
}
