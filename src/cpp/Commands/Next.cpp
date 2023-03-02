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

// Execute method
bool Next::executeCommand(CandyGameState& gameState) {
    if (this->command != CmdTypes::Next) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    int nextPlayerIdx = (gameState.getCurrentTurnIdx() + 1) % gameState.getPlayerList().size();
    gameState.setCurrentTurnIdx(nextPlayerIdx);
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
    return true;
}