// Commands.hpp
#ifndef CANGKULCOMMAND_HPP
#define CANGKULCOMMAND_HPP


#include "../../enums/CangkulCmdTypes.hpp"
#include "../GameEnvironment/CangkulGameState.hpp"
#include "BaseCommand.hpp"

#include <string>

using std::string;

class CangkulCommand: public BaseCommand<CangkulCmdTypes, CangkulGameState> {
protected:

    virtual void validateCommand(CangkulGameState&) = 0;

public:
    // Default ctor
    CangkulCommand();

    // dtor
    virtual ~CangkulCommand();


    // ========== Other Methods ==========

    // Execute command
    virtual void executeCommand(CangkulGameState&) = 0;

    // ========== Static Methods ==========
    
    // convert command string to type
    static CangkulCmdTypes parseCommand(string commandString);

    // convert command type to string
    static string parseCommand(CangkulCmdTypes);
};

#endif