/**
 * @file GameManager.hpp
 * @brief Header file for the GameManager class that manages the game to be played.
 * 
 */
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "GameState.hpp"

/**
 * @class GameManager
 * @brief Class that manages the game to be played.
 * 
 */
class GameManager {
    protected:
    
    /**
     * @brief Virtual method to be implemented by sub-classes to start a sub-game.
     * 
     */
    virtual void startSubGame() = 0;

    /**
     * @brief Virtual method to be implemented by sub-classes to start a round of a game.
     * 
     */
    virtual void startRound() = 0;
    public:

    /**
     * @brief Initiates the start of a game.
     * 
     */
    virtual void startGame() = 0;

};

#endif