// GameState.cpp
#include "../../header/GameEnvironment/GameState.hpp"

#include <iostream>

using std::cout;
using std::endl;

// Default ctor
GameState::GameState() {
    // Initialize default values
    playerList = vector<Player>();
    currentTurnIdx = 0;
    round = 1;
    pointPool = 64;
    tableCards = TableCard();
    deckCards = DeckCard();
}

// Specified ctor
GameState::GameState(vector<Player> playerList, int currentTurn, int roundNum, int points, TableCard tblCard, DeckCard dckCard) {
    playerList = playerList;
    currentTurnIdx = currentTurn;
    round = roundNum;
    pointPool = points;
    tableCards = tblCard;
    deckCards = dckCard;
}

// Copy ctor
GameState::GameState(const GameState& gs) {
    playerList = gs.playerList;
    currentTurnIdx = gs.currentTurnIdx;
    round = gs.round;
    pointPool = gs.pointPool;
    tableCards = gs.tableCards;
    deckCards = gs.deckCards;
}

// Destructor
GameState::~GameState() {
    // No dynamic allocation
}

// Setters
void GameState::setPlayerList(vector<Player> playerList) {
    this->playerList = playerList;
}

void GameState::setCurrentTurnIdx(int currentTurn) {
    currentTurnIdx = currentTurn;
}

void GameState::setRound(int roundNum) {
    round = roundNum;
}

void GameState::setPointPool(int points) {
    pointPool = points;
}

void GameState::setTableCards(TableCard tblCard) {
    tableCards = tblCard;
}

void GameState::setDeckCards(DeckCard dckCard) {
    deckCards = dckCard;
}

// Getters
vector<Player> GameState::getPlayerList() {
    return playerList;
}

Player& GameState::getCurrentTurnPlayer() {
    return playerList[currentTurnIdx];
}

Player& GameState::getPlayerRefAt(int idx) {
    return playerList[idx];
}

int GameState::getCurrentTurnIdx() {
    return currentTurnIdx;
}

int GameState::getRound() {
    return round;
}

int GameState::getPointPool() {
    return pointPool;
}

TableCard& GameState::getTableCards() {
    return tableCards;
}

DeckCard& GameState::getDeckCards() {
    return deckCards;
}

// Methods for printing player list
void GameState::printPlayerList() {
    for (int i = 0; i < playerList.size(); i++) {
        cout << i+1 << ". " << playerList[i].getName() << endl;
    }
}

void GameState::printPlayerList(vector<Player> playerVec) {
    for (int i = 0; i < playerVec.size(); i++) {
        cout << i+1 << ". " << playerVec[i].getName() << endl;
    }
}