// Switch.cpp
#include "../../header/Commands/Switch.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Switch::Switch() {
    this->command = CmdTypes::Switch;
}

// Execute method
bool Switch::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Switch) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the Switch ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Switch)) {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability untuk Switch." << endl;
        return false;
    }

    return true;
}