/**
 * @file Put.hpp
 * @brief Header file for the Put command class.
 * 
 */
#ifndef PUT_HPP
#define PUT_HPP

#include "CangkulCommand.hpp"

/**
 * @class Put
 * @brief Class that defines the Put command
 * @extends CangkulCommand
 * 
 */
class Put : public CangkulCommand {
private:
    /**
     * @brief Validate command by throwing exception if necessary
     * 
     * @param gameState State of the game to be validated on
     */
    void validateCommand(CangkulGameState&);

public:
    /**
     * @brief Construct a new Put object
     * 
     */
    Put();

    /**
     * @brief Executes Put
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CangkulGameState& gameState);
};

#endif