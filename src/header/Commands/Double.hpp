/**
 * @file Double.hpp
 * @brief Header file for the Double command class.
 * 
 */
#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "Commands.hpp"

/**
 * @class Double
 * @brief Class that defines the Double command
 * @extends Commands
 * 
 */
class Double : public Commands {
public:
    /**
     * @brief Construct a new Double object
     * 
     */
    Double();

    /**
     * @brief Executes Double
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif
