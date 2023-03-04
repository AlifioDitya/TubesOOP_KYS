// Quadruple.cpp
#include "../../header/Commands/Quadruple.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.h"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Quadruple::Quadruple() {
    this->command = CmdTypes::Quadruple;
    this->abilityType = AbilityTypes::Quadruple;
}

// Execute method
void Quadruple::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);
    
    // Check if the player has the Quadruple ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Quadruple)) {
        throw MissingAbility(AbilityTypes::Quadruple);
    }
    
    int oldPoints = gameState.getPointPool();
    int newPoints = oldPoints * 4;
    gameState.setPointPool(newPoints);

    cout << gameState.getCurrentTurnPlayer().getName() << "melakukan QUADRUPLE! Poin hadiah naik dari " << oldPoints << " menjadi " << newPoints << "!" << endl; 

}