/**
 * @file Abilityless.hpp
 * @brief Header file for the Abilityless command class.
 * 
 */
#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "PlayerInvolvedAbility.hpp"

/**
 * @class Abilityless
 * @brief Class that defines the Abilityless command
 * @extends PlayerInvolvedAbility
 * 
 */
class Abilityless : public PlayerInvolvedAbility {
public:
    /**
     * @brief Construct a new Abilityless object
     * 
     */
    Abilityless();

    /**
     * @brief Executes abilityless
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif