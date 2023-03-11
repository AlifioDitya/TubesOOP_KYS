// Commands.cpp
#include "../../header/Commands/Commands.hpp"
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
        {"ability", CmdTypes::Ability}
    };

    // // Check if the command string is a valid command
    // if (cmdMap.find(commandString) == cmdMap.end()) {
    //     throw "Input command tidak valid.\n";
    //     }
    return cmdMap[commandString];
    
}

string Commands::parseCommand(CmdTypes command) {

    // Map the command to its equivalent string
    map<CmdTypes, string> cmdMap = {
        {CmdTypes::Next, "next"},
        {CmdTypes::Double, "double"},
        {CmdTypes::Half, "half"},
        {CmdTypes::Ability, "ability"},
        
    };

    return cmdMap[command];
    
}