// GameState.cpp
#include "../../header/GameEnvironment/GameState.hpp"
#include "../../header/GameEnvironment/CandyPlayer.hpp"
#include <iostream>
#include "algorithm"

using std::cout;
using std::endl;
using std::find_if;

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
    deckCards = GameDeckCard();
}

// Specified ctor
template <class T>
GameState<T>::GameState(const vector<T>& playerList, int roundNum, int points, const TableCard& tableCard, const GameDeckCard& deckCard) {
    this->playerList = deque<T>(playerList.begin(), playerList.end());

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
void GameState<T>::setTableCards(const vector<Card>& cards) {
    tableCards.setCards(cards);
}

template <class T>
void GameState<T>::setDeckCards(const vector<Card>& cards) {
    deckCards.setCards(cards);
}

template<class T>
void GameState<T>::skipCurrentPlayer() {
    T player = playerList[0];
    playerList.pop_front();
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
        {
            skipCurrentPlayer();
        }
    }
}

template <class T>
void GameState<T>::setAllNotPlayed() {
    for (long unsigned int i = 0; i < getPlayerList().size(); i++) {
        T& player = getPlayerRefAt(i);

        player.setHasPlayed(false);
    }
}

// Getters
template <class T>
vector<T> GameState<T>::getPlayerList() const {
    return vector<T>(playerList.begin(), playerList.end());
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
GameDeckCard& GameState<T>::getDeckCards() {
    return deckCards;
}


template<class T>
bool GameState<T>::hasAllPlayed() const {

    for (auto player: playerList) {
        if (!player.hasPlayedThisRound()) return false;
    }
    
    return true;
}

template <class T>
int GameState<T>::getPlayerIdx(int id) const {
    for (long unsigned int i = 0; i < playerList.size(); i++) {

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
    for (long unsigned int i = 0; i < playerVec.size(); i++) {
        cout << i+1 << ". " << playerVec[i].getName() << endl;
    }
}

void TemporaryFunction ()
{
    GameState<CandyPlayer> temp1;
}