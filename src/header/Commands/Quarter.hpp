/**
 * @file Quarter.hpp
 * @brief Header file for the Quarter Ability class.
 * 
 */
#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

/**
 * @class Quarter
 * @brief Class that defines the Quarter Ability
 * @extends Ability
 * 
 */
class Quarter : public Ability {
public:
    /**
     * @brief Construct a new Quarter object
     * 
     */
    Quarter();

    /**
     * @brief Executes Quarter
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif