/**
 * @file CangkulCommand.hpp
 * @brief Header file for the CangkulCommand class.
 * 
 */
#ifndef CANGKULCOMMAND_HPP
#define CANGKULCOMMAND_HPP


#include "../../enums/CangkulCmdTypes.hpp"
#include "../GameEnvironment/CangkulGameState.hpp"
#include "BaseCommand.hpp"

#include <string>

using std::string;

/**
 * @class CangkulCommand
 * @brief Class that defines the commands in a cangkul game
 * @extends BaseCommand
 * 
 */
class CangkulCommand : public BaseCommand<CangkulCmdTypes, CangkulGameState> {
protected:
    /**
     * @brief Validate command by throwing exception if necessary
     * 
     * @param gameState State of the game to be validated on
     */
    virtual void validateCommand(CangkulGameState&) = 0;

public:
    /**
     * @brief Construct a new Cangkul Command object
     * 
     */
    CangkulCommand();

    /**
     * @brief Destroy the Cangkul Command object
     * 
     */
    virtual ~CangkulCommand();


    /**
     * @brief Executes command
     * 
     * @param gameState State of the game to be applied to
     */
    virtual void executeCommand(CangkulGameState&) = 0;

    /**
     * @brief Converts the commands from string to commands type
     * 
     * @param abilityString String of ability
     * @return CangkulCmdTypes object
     */
    static CangkulCmdTypes parseCommand(string commandString);

    /**
     * @brief Converts commands object to string
     * 
     * @return string representation of a commands object
     */
    static string parseCommand(CangkulCmdTypes);
};

#endif