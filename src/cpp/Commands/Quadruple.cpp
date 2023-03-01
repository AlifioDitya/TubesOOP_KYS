// Quadruple.cpp
#include "../../header/Commands/Quadruple.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Quadruple::Quadruple() {
    this->command = CmdTypes::Quadruple;
}

// Execute method
bool Quadruple::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Quadruple) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the Quadruple ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Quadruple)) {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability untuk QUADRUPLE." << endl;
        return false;
    }
    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 4;
    gameState.setPointPool(newPoints);

    cout << gameState.getCurrentTurnPlayer().getName() << "melakukan QUADRUPLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl; 
    return true;
}