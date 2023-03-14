/**
*   @file CangkulGameManager.hpp
*   @brief Header file for the CangkulGameManager class.
*   This file contains the declaration of the CangkulGameManager class, which is a derived class of the GameManager class.
*   It manages the game state and handles player commands for the game Cangkul.
**/
#ifndef CANGKULGAMEMANAGER_HPP
#define CANGKULGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CangkulGameState.hpp"
#include "../Commands/CangkulCommand.hpp"

#include <map>

using std::map;

/**
*   @class CangkulGameManager
*   @brief A class for managing the game state and player commands for the game Cangkul.
*   The CangkulGameManager class is a derived class of the GameManager class. It manages the game state and handles player
*   commands for the game Cangkul. It has private methods for initializing the player count, getting the initial player list,
*   getting player commands, and starting rounds and subgames. It has a public method for starting the whole game.
*   @extends GameManager
**/
class CangkulGameManager: public GameManager {
private:
    int playerCount; // In-game player count
    CangkulGameState gameState; // Game state for the cangkul game
    map<CangkulCmdTypes, CangkulCommand*> actions; // List of actions in a cangkul game

    /**
    *   @brief Get input of player count from user and set the attribute.
    **/
    void initializePlayerCount();

    /**
    *   @brief Return initial player list with input name.
    *   @param playerNum The number of players in the game.
    *   @return A vector of players with input names.
    **/
    vector<Player> getInitialPlayerList(int playerNum) const;
   
    /**
    *   @brief Get command input from user.
    *   @return A pointer to a CangkulCommand object.
    **/
    CangkulCommand* getPlayerCommand();

    /**
     * @brief Start a round of a cangkul game
     * 
     */
    void startRound();

    /**
     * @brief Start a sub-game of a cangkul game
     * 
     */
    void startSubGame();
public:

    /**
     * @brief Construct a new Cangkul Game Manager object
     * 
     */
    CangkulGameManager();
    
    /**
     * @brief Destroy a Cangkul Game
     * 
     */
    ~CangkulGameManager();

    /**
     * @brief Start a new cangkul game
     * 
     */
    void startGame();

    /**
     * @brief an integer value denoting the number of initial draws.
     * 
     */
    static int initialDraw;
};

#endif