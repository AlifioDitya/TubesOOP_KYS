// Commands.hpp
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "GameState.hpp"
#include "../../enums/CmdTypes.hpp"
#include <string>

using std::string;

class Commands {
protected:
    CmdTypes command;
public:
    // Default ctor
    Commands();

    // Specified ctor
    Commands(CmdTypes);

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
    virtual bool executeCommand(GameState&) const = 0;

    // Static method to parse string to command type
    static CmdTypes parseCommand(string);
};

#endif