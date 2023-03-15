/**
 * @file Switch.hpp
 * @brief Header file for the Switch command class.
 * 
 */
#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "PlayerInvolvedAbility.hpp"

/**
 * @class Switch
 * @brief Class that defines the Switch command
 * @extends PlayerInvolvedAbility
 * 
 */
class Switch : public PlayerInvolvedAbility {
public:
    /**
     * @brief Construct a new Switch object
     * 
     */
    Switch();

    /**
     * @brief Executes Switch
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif