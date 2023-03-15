/**
 * @file Commands.hpp
 * @brief Header file for the Commands class
 *  
 */
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../../enums/CmdTypes.hpp"
#include "../GameEnvironment/CandyGameState.hpp"
#include "BaseCommand.hpp"

#include <string>

using std::string;

/**
 * @class Commands
 * @brief Class that defines the behaviour of in-game commands
 * @extends BaseCommand
 * 
 */
class Commands : public BaseCommand<CmdTypes, CandyGameState> {
public:
    /**
     * @brief Construct a new Commands object
     * 
     */
    Commands();

    /**
     * @brief Destroy the Commands object
     * 
     */
    virtual ~Commands();

    /**
     * @brief Assignment operator for commands object
     * 
     * @return Reference to a command to be assigned to
     */
    Commands& operator=(const Commands&);


    /**
     * @brief Executes command
     * 
     * @param gameState State of the game to be applied to
     */
    virtual void executeCommand(CandyGameState&) = 0;

    /**
     * @brief Converts the commands from string to commands type
     * 
     * @param abilityString String of ability
     * @return CangkulCmdTypes object
     */
    static CmdTypes parseCommand(string commandString);

    /**
     * @brief Converts commands object to string
     * 
     * @return string representation of a commands object
     */
    static string parseCommand(CmdTypes);
};

#endif