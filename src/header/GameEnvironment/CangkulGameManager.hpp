// GameManager.hpp
#ifndef CANGKULGAMEMANAGER_HPP
#define CANGKULGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "GameState.hpp"

#include <map>

using std::map;

class CangkulGameManager: public GameManager {
private:
    int playerCount;
    int startingPlayerId;
    bool isClockwise;
    GameState<Player> gameState;
    vector<bool> hasWon;
    vector<Player> winner;

    void initializePlayerCount();
    void initializePlayerList();

    void startRound();
public:
    CangkulGameManager();
    ~CangkulGameManager();
    void startGame();
};

#endif