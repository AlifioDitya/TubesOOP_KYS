// Double.cpp
#include "../../header/Commands/Double.hpp"
#include "../../enums/CmdTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Double::Double() {
    this->command = CmdTypes::Double;
}

// dtor
Double::~Double() {
    // Do nothing
}

// Execute method
bool Double::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Double) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the Double ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Double)) {
        cout << "Maaf, kamu tidak memiliki ability untuk Double." << endl;
        return false;
    }
    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 2;
    gameState.setPointPool(newPoints);

    cout << "melakukan DOUBLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl;
    return true;
}