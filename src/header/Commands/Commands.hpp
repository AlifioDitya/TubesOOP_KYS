#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../enums/CmdType.hpp"

class Commands {
private:
    CmdType command;
public:
    // Default ctor
    Commands();

    // Specified ctor
    Commands(CmdType);

    // cctor
    Commands(const Commands&);

    // dtor
    virtual ~Commands();

    // operator
    Commands& operator=(const Commands&);

    // Getter
    virtual CmdType getCommandType() const = 0;

    // Method
    virtual void executeCommand() const = 0;
};

#endif