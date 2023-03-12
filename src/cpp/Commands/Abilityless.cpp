// Abilityless.cpp
#include "../../header/Commands/Abilityless.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
Abilityless::Abilityless() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Abilityless;
}


// Execute method
void Abilityless::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);

    // Check if the player has the Abilityless ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Abilityless)) {
        throw MissingAbility(AbilityTypes::Abilityless);
    }

    // Check if all players have used their abilities
    if (gameState.hasAllUsedAbility()) {
        cout << "Ets, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Penggunaan kartu kamu sia-sia :(" << endl;

        gameState.getCurrentTurnPlayer().setNerfed(true);
    }

    else {
        cout << gameState.getCurrentTurnPlayer().getName() << " akan mematikan kartu ability lawan!" << endl;
    
        // Get list of players other than currently playing
        vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
        otherPlayers.erase(otherPlayers.begin() + gameState.getCurrentTurnIdx());

        // Select player to nerf
        int selectIdx = selectPlayer(gameState, otherPlayers, "Silakan pilih pemain yang kartunya ingin Anda tukar:");

        // jika player yang dipilih sudah memakai ability
        if (otherPlayers[selectIdx].hasUsedAbility()) {
            cout << "Kartu ability " << otherPlayers[selectIdx].getName() << " telah dipakai sebelumnya. Yah sayang penggunaan kartu ini sia-sia :(" << endl;
        }

        else {
   
            int idx = gameState.getPlayerIdx(otherPlayers[selectIdx].getId());
             gameState.getPlayerRefAt(idx).setNerfed(true);
            cout << "Kartu ability " << gameState.getPlayerRefAt(idx).getName() << " telah dimatikan." << endl;
        }

    }

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);
    gameState.setNextTurn();

}