// CangkulGameState.cpp
#include "../../header/GameEnvironment/CangkulGameState.hpp"

CangkulGameState::CangkulGameState() {
    startingPlayerId = 0;
}

CangkulGameState::CangkulGameState(const vector <Player>& playerList, int roundNum, const TableCard& tableCard,
                                   const GameDeckCard& deckCard)
        : GameState<Player>(playerList, roundNum, tableCard, deckCard) {
    if (playerList.empty()) startingPlayerId = 0;
    else startingPlayerId = playerList.front().getId();
}

CangkulGameState::CangkulGameState(const CangkulGameState& other) : GameState<Player>(other) {
    startingPlayerId = other.startingPlayerId;
    roundWinner = other.roundWinner;
    winningList = other.winningList;
}

CangkulGameState::~CangkulGameState() {}

// ========== Getters ==========

vector<Player> CangkulGameState::getWinningList() {
    return vector<Player>(winningList.begin(), winningList.end());
}

int CangkulGameState::getStartingPlayerId() {
    return startingPlayerId;
}

Player CangkulGameState::getRoundWinner() {
    return roundWinner;
}

// ========== Predicates ==========

// ========== Setters ==========

void CangkulGameState::setWinningList(const vector<Player>& list) {
    this->winningList = deque<Player>(list.begin(), list.end());
}

void CangkulGameState::setNextTurn() {
    GameState::setNextTurn();
}

void CangkulGameState::setStartingPlayer(Player startingPlayer) {
    startingPlayerId = startingPlayer.getId();
}

bool CangkulGameState::updateRoundWinner() {
    long unsigned int idxMax = 0;
    for (long unsigned int i = 1; i < tableCards.getCards().size(); i++) {
        if (tableCards.getCards()[i] > tableCards.getCards()[idxMax]) idxMax = i;
    }

    if (idxMax == tableCards.getCards().size() - 1) {
        roundWinner = getCurrentTurnPlayer();
        return true;
    } else {
        return false;
    }
}

// ========== Others ==========

void CangkulGameState::moveWinningList() {
    playerList = winningList;
    winningList.clear();
}

void CangkulGameState::moveToWinningList() {
    Player currentPlayer = playerList.front();
    playerList.pop_front();
    winningList.push_back(currentPlayer);
}