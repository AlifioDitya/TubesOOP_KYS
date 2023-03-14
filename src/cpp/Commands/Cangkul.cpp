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

    for (auto card : gameState.getCurrentTurnPlayer().getHand())
    {
        if (gameState.getTableCards().getCards().back().getColor() == card.getColor())
        {
            throw UnnecessaryAction(command);
        }
    }
}

// ========== Methods ==========


// Execute method
void Cangkul::executeCommand(CangkulGameState& gameState) {

    validateCommand(gameState);

    cout << "Pemain melakukan cangkul!" << endl;
    cout << "Banyak kartu deck awal :" << gameState.getDeckCards().countItems() << endl;
    gameState.getCurrentTurnPlayer().addItem(gameState.getDeckCards().drawCard());
    cout << "Banyak kartu deck setelah cangkul :" << gameState.getDeckCards().countItems() << endl;
    
    cout << "Pemain mendapatkan kartu " << gameState.getCurrentTurnPlayer().getHand().back();
}