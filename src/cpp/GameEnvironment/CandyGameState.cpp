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

bool isWinner(const CandyPlayer& player) {
    return player.getPoint() >= CandyGameState::winnerPoint;
}
int CandyGameState::getWinnerIndex() const {
    auto itr = find_if(playerList.begin(), playerList.end(), isWinner);

    if (itr != playerList.end()) return itr - playerList.begin();

    return -1;
}