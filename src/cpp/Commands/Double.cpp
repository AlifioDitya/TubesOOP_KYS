// Double.cpp
#include "../../header/Commands/Double.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

 
Double::Double() {
    this->command = CmdTypes::Double;
}

// ========== Methods ==========

 
void Double::executeCommand(CandyGameState& gameState) {
    uint64_t oldPoints = gameState.getPointPool();
    uint64_t newPoints = oldPoints * (uint64_t)2;
    gameState.setPointPool(newPoints);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan DOUBLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl;
    gameState.setNextTurn();
}