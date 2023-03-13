// GameManager.hpp
#ifndef CANGKULGAMEMANAGER_HPP
#define CANGKULGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CangkulGameState.hpp"

#include <map>

using std::map;

class CangkulGameManager: public GameManager {
private:
    int playerCount;
    bool isClockwise;
    CangkulGameState gameState;

    // ========== Private Methods ==========

    // return initial player list with input name
    vector<Player> getInitialPlayerList(int playerNum) const;
   
    // get command input from user
    // Commands* getPlayerCommand();

    // initiate deck card (random or file input)

    void initializePlayerCount();
    void initializePlayerList();

    void startRound();
public:
    CangkulGameManager();
    ~CangkulGameManager();
    void startGame();
};

#endif