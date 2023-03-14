/**
 * @file CangkulGameState.hpp
 * @brief Header file for the cangkul game state
 * This file contains the declaration of CangkulGameState class which is a derived class from the GameState class.
 * It holds the game state of a cangkul game.
 */
#ifndef CANGKULGAMESTATE_HPP
#define CANGKULGAMESTATE_HPP

#include "Player.hpp"
#include "GameState.hpp"
#include "GameDeckCard.hpp"

#include <vector>
#include <deque>

using std::vector;
using std::deque;

/**
 * @class CangkulGameState
 * @brief Class that holds the state of a cangkul game
 * @extends GameState
 * 
 */
class CangkulGameState: public GameState<Player> {
private:
    /**
     * @brief List of winners
     * 
     */
    deque<Player> winningList;

    /**
     * @brief Id of the starting player
     * 
     */
    int startingPlayerId;

    /**
     * @brief Player that wins a round of a cangkul game
     * 
     */
    Player roundWinner;

public:
    /**
     * @brief Construct a new Cangkul Game State
     * 
     */
    CangkulGameState();

    /**
     * @brief Copy construct a new Cangkul Game State
     * 
     * @param playerList a list of players in a cangkul game
     * @param roundNum the current round number
     * @param tableCard the list of cards in a table
     * @param deckCard the deck cards in game
     */
    CangkulGameState(const vector<Player>& playerList, int roundNum, const TableCard& tableCard, const GameDeckCard& deckCard);

    /**
     * @brief Copy constructs a new Cangkul Game State
     * 
     */
    CangkulGameState(const CangkulGameState&);

    /**
     * @brief Destroy a Cangkul Game State
     * 
     */
    ~CangkulGameState();

    /**
     * @brief Get the Winning List of players
     * 
     * @return a vector of players that wins the round
     */
    vector<Player> getWinningList();

    /**
     * @brief Get the Starting Player Id
     * 
     * @return an integer value of the Id of a player that starts the game
     */
    int getStartingPlayerId();

    /**
     * @brief Get the Round Winner
     * 
     * @return a Player object that wins the round
     */
    Player getRoundWinner();

    /**
     * @brief Set the Winning List of Players
     * 
     */
    void setWinningList(const vector<Player>&);

    /**
     * @brief Sets the the next turn
     * 
     */
    void setNextTurn();

    /**
     * @brief Sets the starting player
     * 
     */
    void setStartingPlayer(Player);

    /**
     * @brief Sets the temporary round winner
     * @return true if the current player is the current winner.
     * @return false otherwise
     */
    bool updateRoundWinner();

    /**
     * @brief Move a player in the winning list to a player list
     * 
     */
    void moveWinningList();

    /**
     * @brief Move the current player to the winning list
     * 
     */
    void moveToWinningList();

};

#endif