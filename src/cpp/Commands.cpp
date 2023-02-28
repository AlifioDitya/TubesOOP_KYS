#include "../header/Commands.hpp"
#include <iostream>

// Default ctor
Commands::Commands() {
    this->command = Next;
}

// Specified ctor
Commands::Commands(CmdType command) {
    this->command = command;
}

// cctor
Commands::Commands(const Commands& cmd) {
    this->command = cmd.command;
}

// Getter
CmdType Commands::getCommand() {
    return this->command;
}