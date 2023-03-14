/**
 * @file SwapCard.hpp
 * @brief Header file for the SwapCard command class.
 * 
 */
#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "PlayerInvolvedAbility.hpp"

/**
 * @class SwapCard
 * @brief Class that defines the Swap Card command
 * @extends PlayerInvolvedAbility
 * 
 */
class SwapCard : public PlayerInvolvedAbility {
private:
    int selectCard(string playerName);

public:
    /**
     * @brief Construct a new Swap Card object
     * 
     */
    SwapCard();

    /**
     * @brief Executes Swap Card
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif