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
    playerList = deque<T>();

    // player giliran saat ini selalu indeks 0
    // currentTurnIdx = 0;
    
    round = 1;
    pointPool = 64;
    tableCards = TableCard();
    deckCards = DeckCard();
}

// Specified ctor
template <class T>
GameState<T>::GameState(const vector<T>& playerList, int roundNum, int points, const TableCard& tableCard, const DeckCard<Card>& deckCard) {
    this->playerList = vector<T>(playerList.begin(), playerList.end());

    // player giliran saat ini selalu indeks 0
    // currentTurnIdx = currentTurn;
    this->round = roundNum;
    this->pointPool = points;
    this->tableCards = tableCard;
    this->deckCards = deckCard;
}

// Copy ctor
template <class T>
GameState<T>::GameState(const GameState<T>& gameState) {
    playerList = gameState.playerList;
    round = gameState.round;
    pointPool = gameState.pointPool;
    tableCards = gameState.tableCards;
    deckCards = gameState.deckCards;
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

// template <class T>
// void GameState<T>::setCurrentTurnIdx(int currentTurn) {
//     currentTurnIdx = currentTurn;
// }

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

template<class T>
void GameState<T>::skipCurrentPlayer() {
    T player = playerList[0];
    playerList.popFront();
    playerList.push_back(player);
}

template <class T>
void GameState<T>::setNextTurn() {

    T& currentPlayer = getCurrentTurnPlayer();
    currentPlayer.setHasPlayed(true);

    if (hasAllPlayed()) {
        skipCurrentPlayer();
    }

    else {
        while(playerList[0].hasPlayedThisRound())
        [
            skipCurrentPlayer();
        ]
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
    return vector<T>(playerList.begin(), playerList.end())
}

template <class T>
T& GameState<T>::getCurrentTurnPlayer() {
    return playerList.front();
}

template <class T>
T& GameState<T>::getPlayerRefAt(int idx) {
    return playerList[idx];
}

// template <class T>
// int GameState<T>::getCurrentTurnIdx() const {
//     return currentTurnIdx;
// }

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

template <class T>
bool hasPlayerNotPlayed(const T& player) {
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