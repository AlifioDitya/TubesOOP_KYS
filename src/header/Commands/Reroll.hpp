/**
 * @file Reroll.hpp
 * @brief Header file for the Reroll Ability class.
 * 
 */
#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

/**
 * @class Reroll
 * @brief Class that defines the Reroll Ability
 * @extends Ability
 * 
 */
class Reroll : public Ability {
public:
    /**
     * @brief Construct a new Reroll object
     * 
     */
    Reroll();

    /**
     * @brief Executes Reroll
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif