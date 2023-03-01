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
    virtual ~Commands();

    // operator
    Commands& operator=(const Commands&);

    // Getter
    CmdTypes getCommandType() const;

    // Method
    virtual void executeCommand(GameState&) const = 0;
};

#endif