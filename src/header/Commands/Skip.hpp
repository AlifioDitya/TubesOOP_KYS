/**
 * @file Skip.hpp
 * @brief Header file for the Skip command class.
 * 
 */
#ifndef SKIP_HPP
#define SKIP_HPP

#include "CangkulCommand.hpp"

/**
 * @class Put
 * @brief Class that defines the Put command
 * @extends CangkulCommand
 * 
 */
class Skip : public CangkulCommand {

private:
    /**
     * @brief Validate command by throwing exception if necessary
     * 
     * @param gameState State of the game to be validated on
     */
    void validateCommand(CangkulGameState&);

public:
    /**
     * @brief Construct a new Skip object
     * 
     */
    Skip();

    /**
     * @brief Executes Skip
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CangkulGameState& gameState);
};

#endif