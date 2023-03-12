// Commands.hpp
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../GameEnvironment/GameState.hpp"
#include "../../enums/CmdTypes.hpp"
#include <string>
#include "../GameEnvironment/CandyGameState.hpp"

using std::string;

class Commands {
protected:
    CmdTypes command;
    
public:
    // Default ctor
    Commands();

    // cctor
    Commands(const Commands&);

    // dtor
    ~Commands();

    // operator
    Commands& operator=(const Commands&);

    // Getter
    CmdTypes getCommandType() const;

    // Method
    // Returns true if command succeeds
    virtual void executeCommand(CandyGameState&) = 0;

    // Static method to parse string to command type
    static CmdTypes parseCommand(string);
    static string parseCommand(CmdTypes);
};

#endif