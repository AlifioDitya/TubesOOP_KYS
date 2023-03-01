// Commands.hpp
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "GameState.hpp"
#include "../../enums/CmdTypes.hpp"

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
};

#endif