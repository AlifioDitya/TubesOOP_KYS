// Commands.hpp
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../../enums/CmdTypes.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

#include <string>

using std::string;

class Commands {
protected:
    CmdTypes command;
    
public:
    // Default ctor
    Commands();

    // dtor
    virtual ~Commands();

    // ========== Operators ==========
 
    Commands& operator=(const Commands&);

    // ========== Getters ==========
    
    // getter for command type
    CmdTypes getCommandType() const;

    // ========== Static Methods ==========

    // Execute command
    virtual void executeCommand(CandyGameState&) = 0;

    // convert command string to type
    static CmdTypes parseCommand(string commandString);

    // convert command type to string
    static string parseCommand(CmdTypes);
};

#endif