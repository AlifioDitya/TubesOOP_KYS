// Reverse.cpp
#include "../../header/Commands/Reverse.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::swap;

// ctor
Reverse::Reverse() {
    this->command = CmdTypes::Reverse;
    this->abilityType = AbilityTypes::Reverse;
}

// Execute method
void Reverse::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);

    vector<CandyPlayer> playerList = gameState.getPlayerList();
    int currentPlayerIdx = gameState.getCurrentTurnIdx();

    // Reverse player order before current player
    for (int i = 0; i < currentPlayerIdx / 2; i++) {
        swap(playerList[i], playerList[currentPlayerIdx - i - 1]);
    }

    // Reverse player order after current player
    if (currentPlayerIdx != playerList.size() - 1) {
        for (int j = currentPlayerIdx + 1; j < currentPlayerIdx + 1 + (playerList.size() - currentPlayerIdx) / 2; j++) {
            swap(playerList[j], playerList[playerList.size() - j - 1]);
        }
    }

    // Move current player to front
    for (int k = currentPlayerIdx; k > 0; k--) {
        swap(playerList[k], playerList[k-1]);
    }

    // Player that executes reverse will get another turn
    gameState.setCurrentTurnIdx(0);

    // Print out player order
    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan reverse!" << endl
         << "Urutan eksekusi giliran ini: " << endl;
    gameState.printPlayerList();
    cout << endl;
    cout << "Urutan eksekusi giliran selanjutnya: " << endl;

    gameState.printPlayerList(playerList);

    // Set the player list in reverse order
    gameState.setPlayerList(playerList);

}