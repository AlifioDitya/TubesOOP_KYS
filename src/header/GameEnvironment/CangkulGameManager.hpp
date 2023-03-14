// GameManager.hpp
#ifndef CANGKULGAMEMANAGER_HPP
#define CANGKULGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CangkulGameState.hpp"
#include "../Commands/CangkulCommand.hpp"

#include <map>

using std::map;

class CangkulGameManager: public GameManager {
private:
    int playerCount;
    CangkulGameState gameState;
    map<CangkulCmdTypes, CangkulCommand*> actions;

    // ========== Private Methods ==========

    // get input of player count from user and set the atribute
    void initializePlayerCount();

    // return initial player list with input name
    vector<Player> getInitialPlayerList(int playerNum) const;
   
    // get command input from user
    CangkulCommand* getPlayerCommand();

    void startRound();
    void startSubGame();
public:

    // Ctor
    CangkulGameManager();
    // Dtor
    ~CangkulGameManager();

    // ========== Methods ==========
    
    // Start whole game
    void startGame();

    // ========== Static Atribute ==========
    static int initialDraw;
};

#endif