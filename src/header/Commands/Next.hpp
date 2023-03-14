/**
 * @file Next.hpp
 * @brief Header file for the Next command class.
 * 
 */
#ifndef NEXT_HPP
#define NEXT_HPP

#include "Commands.hpp"

/**
 * @class Next
 * @brief Class that defines the Next command
 * @extends Commands
 * 
 */
class Next : public Commands {
public:
    /**
     * @brief Construct a new Next object
     * 
     */
    Next();

    /**
     * @brief Executes Next
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CandyGameState& gameState);
};

#endif
