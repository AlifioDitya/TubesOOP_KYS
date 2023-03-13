// Quarter.cpp
#include "../../header/Commands/Quarter.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Quarter::Quarter() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Quarter;
}

// Execute method
void Quarter::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << "melakukan QUARTER! ";
    
    int oldPoint = gameState.getPointPool();
    int newPoint = oldPoint / 4;

    // Check if point has reached one
    if (oldPoint <= 1) {
        cout << "Sayangnya poin hadiah sudah bernilai " << oldPoint 
             << ". Poin tidak berubah.. Giliran dilanjut!" << endl;
    }

    // Quarter the point pool
    gameState.setPointPool(newPoint);

    cout << "Poin hadiah turun dari " << oldPoint << " menjadi " << newPoint << "!" << endl;

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);

    gameState.setNextTurn();

}