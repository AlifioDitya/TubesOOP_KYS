// Abilityless.cpp
#include "../../header/Commands/Abilityless.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
Abilityless::Abilityless() {
    this->command = CmdTypes::Abilityless;
}

// Execute method
bool Abilityless::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Abilityless) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the Abilityless ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Abilityless)) {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability untuk Abilityless." << endl;
        return false;
    }

    // Check if all players have used their abilities
    if (gameState.hasAllUsedAbility()) {
        cout << "Ets, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah penggunaan kartu kamu sia-sia :(" << endl;
        gameState.getCurrentTurnPlayer().setNerfed(true);
        return true;
    }

    cout << gameState.getCurrentTurnPlayer().getName() << " akan mematikan kartu ability lawan!" << endl;
    
    // Get list of players other than currently playing
    vector<Player> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin() + gameState.getCurrentTurnIdx());

    // Select player to nerf
    cout << "Silakan pilih pemain lain yang kartunya ingin Anda tukar:" << endl;

    gameState.printPlayerList(otherPlayers);

    int selectIdx = 0;
    cin >> selectIdx;
    selectIdx--;

    if (otherPlayers[selectIdx].hasUsedAbility()) {
        cout << "Kartu ability " << otherPlayers[selectIdx].getName() << " telah dipakai sebelumnya. Yah sayang penggunaan kartu ini sia-sia :(" << endl;
        return true;
    }

    int nerfedPlayerIdx = 0;
    for (int i = 0; i < gameState.getPlayerList().size(); i++) {
        if (gameState.getPlayerList()[i].getId() == otherPlayers[selectIdx].getId()) {
            gameState.getPlayerRefAt(i).setNerfed(true);
            cout << "Kartu ability " << gameState.getPlayerRefAt(i).getName() << " telah dimatikan." << endl;
            break;
        }
    }

    return true;
}