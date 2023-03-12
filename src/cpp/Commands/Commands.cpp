// Commands.cpp
#include "../../header/Commands/Commands.hpp"
#include "../../header/Exception/IOException.hpp"
#include <algorithm>
#include <map>

using std::string;
using std::map;
using std::transform;
using std::tolower;

// ctor
Commands::Commands() {

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
CmdTypes Commands::getCommandType() const {
    return this->command;
}

CmdTypes Commands::parseCommand(string commandString) {
    // Convert the command string to lowercase for case-insensitive comparison
    transform(commandString.begin(), commandString.end(), commandString.begin(), [](unsigned char c){ return tolower(c); });

    // Map the command string to its equivalent CmdTypes
    map<string, CmdTypes> cmdMap = {
        {"next", CmdTypes::Next},
        {"double", CmdTypes::Double},
        {"half", CmdTypes::Half},
        {"abilityless", CmdTypes::Ability},
        {"quadruple", CmdTypes::Ability},
        {"quarter", CmdTypes::Ability},
        {"re-roll", CmdTypes::Ability},
        {"reverse", CmdTypes::Ability},
        {"swapcard", CmdTypes::Ability},
        {"switch", CmdTypes::Ability}
    };

    // Check if the command string is a valid command
    if (cmdMap.find(commandString) == cmdMap.end()) {
        throw InvalidCommandString();
    }
    return cmdMap[commandString];
    
}

string Commands::parseCommand(CmdTypes command) {

    // Map the command to its equivalent string
    map<CmdTypes, string> cmdMap = {
        {CmdTypes::Next, "NEXT"},
        {CmdTypes::Double, "DOUBLE"},
        {CmdTypes::Half, "HALF"},
        {CmdTypes::Ability, "ABILITY"},
        
    };

    return cmdMap[command];
    
}