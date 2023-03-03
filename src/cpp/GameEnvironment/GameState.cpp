// GameState.cpp
#include "../../header/GameEnvironment/GameState.hpp"

#include <iostream>

using std::cout;
using std::endl;

// Default ctor
template <class T>
GameState<T>::GameState() {
    // Initialize default values
    playerList = vector<Player>();
    currentTurnIdx = 0;
    round = 1;
    pointPool = 64;
    tableCards = TableCard();
    deckCards = DeckCard();
}

// Specified ctor
template <class T>
GameState<T>::GameState(vector<T> playerList, int currentTurn, int roundNum, int points, TableCard tblCard, DeckCard dckCard) {
    playerList = playerList;
    currentTurnIdx = currentTurn;
    round = roundNum;
    pointPool = points;
    tableCards = tblCard;
    deckCards = dckCard;
}

// Copy ctor
template <class T>
GameState<T>::GameState(const GameState<T>& gs) {
    playerList = gs.playerList;
    currentTurnIdx = gs.currentTurnIdx;
    round = gs.round;
    pointPool = gs.pointPool;
    tableCards = gs.tableCards;
    deckCards = gs.deckCards;
}

// Destructor
template <class T>
GameState<T>::~GameState() {
    // No dynamic allocation
}

// Setters
template <class T>
void GameState<T>::setPlayerList(vector<T> playerList) {
    this->playerList = playerList;
}

template <class T>
void GameState<T>::setCurrentTurnIdx(int currentTurn) {
    currentTurnIdx = currentTurn;
}

template <class T>
void GameState<T>::setRound(int roundNum) {
    round = roundNum;
}

template <class T>
void GameState<T>::setPointPool(int points) {
    pointPool = points;
}

template <class T>
void GameState<T>::setTableCards(TableCard tblCard) {
    tableCards = tblCard;
}

template <class T>
void GameState<T>::setDeckCards(DeckCard dckCard) {
    deckCards = dckCard;
}

// Getters
template <class T>
vector<T> GameState<T>::getPlayerList() const {
    return playerList;
}

template <class T>
T& GameState<T>::getCurrentTurnPlayer() {
    return playerList[currentTurnIdx];
}

template <class T>
T& GameState<T>::getPlayerRefAt(int idx) {
    return playerList[idx];
}

template <class T>
int GameState<T>::getCurrentTurnIdx() const {
    return currentTurnIdx;
}

template <class T>
int GameState<T>::getRound() const {
    return round;
}

template <class T>
int GameState<T>::getPointPool() const {
    return pointPool;
}

template <class T>
TableCard& GameState<T>::getTableCards() {
    return tableCards;
}

template <class T>
DeckCard& GameState<T>::getDeckCards() {
    return deckCards;
}

// Methods for printing player list
template <class T>
void GameState<T>::printPlayerList() const {
    for (int i = 0; i < playerList.size(); i++) {
        cout << i+1 << ". " << playerList[i].getName() << endl;
    }
}

template <class T>
void GameState<T>::printPlayerList(vector<T> playerVec) const {
    for (int i = 0; i < playerVec.size(); i++) {
        cout << i+1 << ". " << playerVec[i].getName() << endl;
    }
}