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

// Execute method
bool Double::executeCommand(CandyGameState& gameState) {
    if (this->command != CmdTypes::Double) {
        cout << "Command tidak tepat." << endl;
        return false;
    }
    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 2;
    gameState.setPointPool(newPoints);

    cout << gameState.getCurrentTurnPlayer().getName() << "melakukan DOUBLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl;
    return true;
}