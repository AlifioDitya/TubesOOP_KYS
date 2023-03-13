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

// ========== Methods ==========

// Execute method
void Next::executeCommand(CandyGameState& gameState) {

    // int nextPlayerIdx = (gameState.getCurrentTurnIdx() + 1) % gameState.getPlayerList().size();
    // gameState.setCurrentTurnIdx(nextPlayerIdx);
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;

    gameState.setNextTurn();
}