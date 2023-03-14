// Quarter.cpp
#include "../../header/Commands/Quarter.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.hpp"
#include <math.h>
#include <iostream>

using std::cout;
using std::endl;
using std::max;

 
Quarter::Quarter() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Quarter;
}

// ========== Methods ==========

 
void Quarter::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan QUARTER!";
    
    uint64_t oldPoint = gameState.getPointPool();
    uint64_t newPoint = oldPoint / 4;

    // Check if point has reached one
    if (oldPoint <= 1) {
        cout << " Sayangnya poin hadiah sudah bernilai " << oldPoint 
             << ". Poin tidak berubah.. Giliran dilanjut!" << endl;
    }

    else {
    // Quarter the point pool

    if (newPoint <= 0) newPoint = 1;
    gameState.setPointPool(newPoint);

    cout << " Poin hadiah turun dari " << oldPoint << " menjadi " << gameState.getPointPool() << "!" << endl;
    }

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);

    gameState.setNextTurn();

}