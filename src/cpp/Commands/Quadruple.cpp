// Quadruple.cpp
#include "../../header/Commands/Quadruple.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Quadruple::Quadruple() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Quadruple;
}

// Execute method
void Quadruple::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);
    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 4;
    gameState.setPointPool(newPoints);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan QUADRUPLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl; 

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);

    gameState.setNextTurn();
}