// Abilityless.cpp
#include "../../header/Commands/Abilityless.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
Abilityless::Abilityless() {
    this->command = CmdTypes::Abilityless;
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

        return;
    }

    cout << gameState.getCurrentTurnPlayer().getName() << " akan mematikan kartu ability lawan!" << endl;
    
    // Get list of players other than currently playing
    vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin() + gameState.getCurrentTurnIdx());

    // Select player to nerf
    cout << "Silakan pilih pemain lain yang kartunya ingin Anda tukar:" << endl;

    gameState.printPlayerList(otherPlayers);

    int selectIdx = 0;
    cin >> selectIdx;
    selectIdx--;

    // jika player yang dipilih sudah memakai ability
    if (otherPlayers[selectIdx].hasUsedAbility()) {
        cout << "Kartu ability " << otherPlayers[selectIdx].getName() << " telah dipakai sebelumnya. Yah sayang penggunaan kartu ini sia-sia :(" << endl;
    }

    else {
        int nerfedPlayerIdx = 0;
        for (int i = 0; i < gameState.getPlayerList().size(); i++) {
            if (gameState.getPlayerList()[i].getId() == otherPlayers[selectIdx].getId()) {
                gameState.getPlayerRefAt(i).setNerfed(true);
                cout << "Kartu ability " << gameState.getPlayerRefAt(i).getName() << " telah dimatikan." << endl;
                break;
            }
        }
    }

}