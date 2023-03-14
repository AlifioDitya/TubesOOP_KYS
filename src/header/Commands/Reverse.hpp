/**
 * @file Reverse.hpp
 * @brief Header file for the Reverse Ability class.
 * 
 */
#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "Ability.hpp"

/**
 * @class Reverse
 * @brief Class that defines the Reverse Ability
 * @extends Ability
 * 
 */
class Reverse : public Ability {
public:
    /**
     * @brief Construct a new Reverse object
     * 
     */
    Reverse();

    /**
     * @brief Executes Reverse
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif
