// Commands.cpp
#include "../../header/Commands/Commands.hpp"

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

// dtor
Commands::~Commands() {}

// operator=
Commands& Commands::operator=(const Commands& other) {
    if (this != &other) {
        command = other.command;
    }
    return *this;
}

// Getter
CmdType Commands::getCommandType() const {
    return this->command;
}