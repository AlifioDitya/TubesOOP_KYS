// Commands.cpp
#include "../../header/Commands/CangkulCommand.hpp"
#include "../../header/Exception/IOException.hpp"
#include <algorithm>
#include <map>

using std::string;
using std::map;
using std::transform;
using std::tolower;

 
CangkulCommand::CangkulCommand() {

}


CangkulCommand::~CangkulCommand() {}

// ========== Static Methods ==========

CangkulCmdTypes CangkulCommand::parseCommand(string commandString) {
    // Convert the command string to lowercase for case-insensitive comparison
    transform(commandString.begin(), commandString.end(), commandString.begin(), [](unsigned char c){ return tolower(c); });

    // Map the command string to its equivalent CmdTypes
    map<string, CangkulCmdTypes> cmdMap = {
        {"put", CangkulCmdTypes::Put},
        {"cangkul", CangkulCmdTypes::Cangkul},
        {"skip", CangkulCmdTypes::Skip},
    };

    // Check if the command string is a valid command
    if (cmdMap.find(commandString) == cmdMap.end()) {
        throw InvalidCommandString();
    }
    return cmdMap[commandString];
    
}

string CangkulCommand::parseCommand(CangkulCmdTypes command) {

    // Map the command to its equivalent string
    map<CangkulCmdTypes, string> cmdMap = {
        {CangkulCmdTypes::Put, "PUT"},
        {CangkulCmdTypes::Cangkul, "CANGKUL"},
        {CangkulCmdTypes::Skip, "SKIP"},
        
    };

    return cmdMap[command];
    
}