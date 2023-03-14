// Skip.cpp
#include "../../header/Commands/Cangkul.hpp"
#include "../../enums/CangkulCmdTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Cangkul::Cangkul() {
    this->command = CangkulCmdTypes::Cangkul;
}

void Cangkul::validateCommand(CangkulGameState& gameState) {
    if (gameState.getTableCards().countItems() == 0) {
        throw UnnecessaryAction(command);
    }
}

// ========== Methods ==========


// Execute method
void Cangkul::executeCommand(CangkulGameState& gameState) {
    cout << "Pemain melakukan cangkul!" << endl;

    gameState.getCurrentTurnPlayer().addItem(gameState.getDeckCards().drawCard());
    
    cout << "Pemain mendapatkan kartu " << gameState.getCurrentTurnPlayer().getHand().back();
}