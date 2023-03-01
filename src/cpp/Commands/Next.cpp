// Next.cpp
#include "../../header/Commands/Next.hpp"
#include "../../enums/CmdTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Next::Next() {
    this->command = CmdTypes::Next;
}

// dtor
Next::~Next() {
    // Do nothing
}

// Execute method
void Next::executeCommand(GameState& gameState) {
    if (this->command == CmdTypes::Next) {
        int nextPlayerIdx = (gameState.getCurrentTurnIdx() + 1) % gameState.getPlayerList().size();
        gameState.setCurrentTurnIdx(nextPlayerIdx);
    } else {
        cout << "Invalid command" << endl;
    }
}