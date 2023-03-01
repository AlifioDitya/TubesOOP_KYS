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

// dtor
Quadruple::~Quadruple() {
    // Do nothing
}

// Execute method
bool Quadruple::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Quadruple) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the Quadruple ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Quadruple)) {
        cout << "Maaf, kamu tidak memiliki ability untuk Quadruple." << endl;
        return false;
    }
    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 4;
    gameState.setPointPool(newPoints);

    cout << "melakukan Quadruple! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl; 
    return true;
}