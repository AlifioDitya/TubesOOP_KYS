// Double.cpp
#include "../../header/Commands/Double.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Double::Double() {
    this->command = CmdTypes::Double;
}

// Execute method
void Double::executeCommand(CandyGameState& gameState) {

    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 2;
    gameState.setPointPool(newPoints);

    cout << gameState.getCurrentTurnPlayer().getName() << "melakukan DOUBLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl;
}