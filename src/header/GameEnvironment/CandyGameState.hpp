/**
*   @file CandyGameState.hpp
*   @brief Header file for CandyGameState class.
*   This file contains the declaration of CandyGameState class, which is a derived class of GameState class.
*   This class stores the state of the game, including player list, deck cards, table cards, and game points.
*   It also provides various methods to modify or access the game state.
**/

#ifndef CANDYGAMESTATE_HPP
#define CANDYGAMESTATE_HPP

#include "CandyPlayer.hpp"
#include "GameState.hpp"
#include "GameDeckCard.hpp"
#include "AbilityDeckCard.hpp"
#include <vector>

using std::vector;

/**
*   @class CandyGameState
*   @brief Class representing the game state for the Candy game.
*   @extends GameState
**/
class CandyGameState : public GameState<CandyPlayer> {
private:
    /**
    *   @brief Deck of ability cards.
    **/
    AbilityDeckCard abilities;

    /**
    *   @brief ID of a player that calls the reverse ability.
    **/
    int reversePlayerId;

    /**
    *   @brief Pool of point prize to be awarded.
    **/
    uint64_t pointPool;

public:
    /**
    *   @brief Default constructor for CandyGameState.
    **/
    CandyGameState();

    /**
    *  @brief Constructor for CandyGameState with specified parameters.
    *  @param playerList vector of CandyPlayer objects representing the players in the game.
    *  @param roundNum an integer representing the current round number.
    *  @param points an unsigned 64-bit integer representing the total points of the game.
    *  @param tableCard a TableCard object representing the current table card.
    *  @param deckCard a GameDeckCard object representing the game deck card.
    *  @param abilities an AbilityDeckCard object representing the abilities deck card.
    *  @param reversePlayerId an integer representing the player id that used the reverse ability in this round.
    **/
    CandyGameState(const vector <CandyPlayer>& playerList, int roundNum, uint64_t points, const TableCard& tableCard,
                   const GameDeckCard& deckCard, const AbilityDeckCard& abilities, int reversePlayerId);

    /**
    *   @brief Copy constructor for CandyGameState.
    *   
    *   @param other a constant reference to another CandyGameState object.
    **/
    CandyGameState(const CandyGameState&);

    /**
    *   @brief Destructor for CandyGameState.
    **/
    ~CandyGameState();

    /**
    *   @brief Getter for reversePlayerId
    *   @return an integer representing the player id that used the reverse ability in this round.
    **/
    int getReversePlayerId() const;

    /**
    *   @brief Getter for pointPool.
    *   @return an unsigned 64-bit integer representing the point pool in the current round.
    **/
    uint64_t getPointPool() const;

    /**
    *   @brief Getter for abilities.
    *   @return a reference to the AbilityDeckCard object..
    **/
    AbilityDeckCard& getAbilities();

    /**
    *   @brief Predicate to check if all players have used their ability in the current round.
    *   @return a boolean value, true if all players have used their ability, false otherwise.
    **/
    bool hasAllUsedAbility() const;

    /**
    *  @brief Setter for abilities.
    *  @param abilities an AbilityDeckCard object representing the new ability deck card.
    **/
    void setAbilities(const AbilityDeckCard&);

    /**
    *   @brief Method to move to the next player turn.
    **/
    void setNextTurn();

    /**
    *   @brief Setter for the reversePlayerId
    *   @param playerId an integer representing the player id that used the reverse ability in this round.
    **/
    void setReversePlayerId(int);

    /**
    *   @brief Setter for the pointPool
    *   @param points an unsigned 64-bit integer representing the point pool prize in this round.
    **/
    void setPointPool(uint64_t points);

    /**
    *   @brief Prints the leaderboard
    **/
    void printLeaderBoard() const;

    /**
    *   @brief Prints the turn of players for the next round
    **/
    void printNextRoundTurn() const;

    /**
    *   @brief Initial points for the game
    **/
    static const uint64_t initialPoint;

    /**
    *   @brief Points of the winner
    **/
    static const uint64_t winnerPoint;
};

#endif