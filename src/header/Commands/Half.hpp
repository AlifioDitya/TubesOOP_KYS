/**
 * @file Half.hpp
 * @brief Header file for the Half command class.
 * 
 */
#ifndef HALF_HPP
#define HALF_HPP

#include "Commands.hpp"

/**
 * @class Half
 * @brief Class that defines the Half command
 * @extends Commands
 * 
 */
class Half : public Commands {
public:
    /**
     * @brief Construct a new Half object
     * 
     */
    Half();

    /**
     * @brief Executes Half
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif