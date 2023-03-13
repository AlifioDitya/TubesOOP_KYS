#include "../../header/GameEnvironment/CangkulGameState.hpp"

// Default ctor
CangkulGameState::CangkulGameState() {

}

// Specified ctor
CangkulGameState::CangkulGameState(const vector<Player>& playerList, int roundNum, const TableCard& tableCard, const GameDeckCard& deckCard)
    : GameState<Player>(playerList, roundNum, tableCard, deckCard)
{   
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

void CangkulGameState::setNextTurn() {
    GameState::setNextTurn();
}


// ========== Others ==========

void CangkulGameState::moveWinningList() {
    playerList = winningList;
    winningList.clear();
}