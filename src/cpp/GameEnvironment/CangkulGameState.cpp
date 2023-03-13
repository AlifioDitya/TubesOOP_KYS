#include "../../header/GameEnvironment/CangkulGameState.hpp"

// Default ctor
CangkulGameState::CangkulGameState() {

}

// Specified ctor
CangkulGameState::CangkulGameState(const vector<Player>& playerList, int roundNum, const TableCard& tableCard, const GameDeckCard& deckCard, 
        const vector<Player>& winningList)
    : GameState<Player>(playerList, roundNum, tableCard, deckCard)
{   
    this->winningList = deque<Player>(winningList.begin(), winningList.end());
}

// cctor
CangkulGameState::CangkulGameState(const CangkulGameState& other): GameState<Player>(other) {
    winningList = other.winningList;
}

// dtor
CangkulGameState::~CangkulGameState() {

}

// ========== Getters ==========

vector<Player> CangkulGameState::getWinningList() {
    return vector<Player>(winningList.begin(), winningList.end());
}

// ========== Predicates ==========


// ========== Setters ==========
void CangkulGameState::setWinningList(const vector<Player>& list) {
    this->winningList = deque<Player>(list.begin(), list.end());
}

 