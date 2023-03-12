// GameState.cpp
#include "../../header/GameEnvironment/GameState.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::find;

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
GameState<T>::GameState(vector<T> playerList, int currentTurn, int roundNum, int points, TableCard tableCard, DeckCard<Card> deckCard) {
    playerList = playerList;
    currentTurnIdx = currentTurn;
    round = roundNum;
    pointPool = points;
    tableCards = tableCard;
    deckCards = deckCard;
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
void GameState<T>::setPlayerList(const vector<T>& playerList) {
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
void GameState<T>::setTableCards(const TableCard& tblCard) {
    tableCards = tblCard;
}

template <class T>
void GameState<T>::setDeckCards(const DeckCard<Card>& dckCard) {
    deckCards = dckCard;
}

template <class T>
void GameState<T>::setNextTurn() {

    Player& currentPlayer = getCurrentTurnPlayer();
    currentPlayer.setHasPlayed(true);

    if (hasAllPlayed()) {

        currentTurnIdx = (currentTurnIdx + 1) % playerList.size();     

    }

    else {
        while(currentPlayer.hasPlayedThisRound()) currentTurnIdx = (currentTurnIdx + 1) % playerList.size();
    }
}

template <class T>
void GameState<T>::setAllNotPlayed() {
    for (int i = 0; i < getPlayerList().size(); i++) {
        CandyPlayer& player = getPlayerRefAt(i);

        player.setHasPlayed(false);
    }
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
DeckCard<Card>& GameState<T>::getDeckCards() {
    return deckCards;
}

bool hasPlayerNotPlayed(const Player& player) {
    return player.hasPlayedThisRound();
}

template<class T>
bool GameState<T>::hasAllPlayed() const {
    return find(playerList.begin(), playerList.end(), hasPlayerNotPlayed) == playerList.end();
}

template <class T>
int GameState<T>::getPlayerIdx(int id) const {
    for (int i = 0; i < playerList.size(); i++) {

        if (playerList[i].getId() == id) {
            return i;
        }
    }

    return -1;
}

// Methods for printing player list
template <class T>
void GameState<T>::printPlayerList() const {
    for (int i = 0; i < playerList.size(); i++) {
        cout << i+1 << ". " << playerList[i].getName() << endl;
    }
}

template <class T>
void GameState<T>::printPlayerList(const vector<T>& playerVec) const {
    for (int i = 0; i < playerVec.size(); i++) {
        cout << i+1 << ". " << playerVec[i].getName() << endl;
    }
}