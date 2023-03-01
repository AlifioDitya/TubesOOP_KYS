// Quarter.cpp
#include "../../header/Commands/Quarter.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Quarter::Quarter() {
    this->command = CmdTypes::Quarter;
}

// Execute method
bool Quarter::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Quarter) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the Quarter ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Quarter)) {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability untuk Quarter." << endl;
        return false;
    }

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

    return true;
}