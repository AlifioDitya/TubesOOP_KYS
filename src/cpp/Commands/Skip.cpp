// Skip.cpp
#include "../../header/Commands/Skip.hpp"
#include "../../enums/CangkulCmdTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Skip::Skip() {
    this->command = CangkulCmdTypes::Skip;
}

void Skip::validateCommand(CangkulGameState& gameState) {

    if (gameState.getTableCards().countItems() == 0) {
        throw UnnecessaryAction(command);
    }

    if (gameState.getDeckCards().countItems() > 0) {
        throw ForbiddenSkip();
    }
}

// ========== Methods ==========

// Execute method
void Skip::executeCommand(CangkulGameState& gameState) {

    cout << "Giliran pemain dilewatkan!" << endl;
    gameState.setNextTurn();
}