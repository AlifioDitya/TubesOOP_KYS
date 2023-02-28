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

    // operator
    Commands& operator=(const Commands&);

    // Getter
    CmdType getCommand();
};

#endif