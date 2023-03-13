// Commands.hpp
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../../enums/CmdTypes.hpp"
#include "../GameEnvironment/CandyGameState.hpp"
#include "BaseCommand.hpp"

#include <string>

using std::string;

class Commands: public BaseCommand<CmdTypes, CandyGameState> {
    
public:
    // Default ctor
    Commands();

    // dtor
    virtual ~Commands();

    // ========== Operators ==========
 
    Commands& operator=(const Commands&);


    // ========== Other Methods ==========

    // Execute command
    virtual void executeCommand(CandyGameState&) = 0;

    // ========== Static Methods ==========
    
    // convert command string to type
    static CmdTypes parseCommand(string commandString);

    // convert command type to string
    static string parseCommand(CmdTypes);
};

#endif