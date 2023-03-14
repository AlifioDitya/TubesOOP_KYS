/**
 * @file Quadruple.hpp
 * @brief Header file for the Quadruple Ability class.
 * 
 */
#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

/**
 * @class Quadruple
 * @brief Class that defines the Quadruple Ability
 * @extends Ability
 * 
 */
class Quadruple : public Ability {
public:
    /**
     * @brief Construct a new Quadruple object
     * 
     */
    Quadruple();

    /**
     * @brief Executes Quadruple
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif
