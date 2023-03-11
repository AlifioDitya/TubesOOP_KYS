// Reverse.cpp
#include "../../header/Commands/Reverse.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::reverse;
using std::swap;
using std::rotate;

// ctor
Reverse::Reverse() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Reverse;
}

// Execute method
void Reverse::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);

    vector<CandyPlayer> playerList = gameState.getPlayerList();
    int currentPlayerIdx = gameState.getCurrentTurnIdx();

    // Reverse player order before current player
    if (currentPlayerIdx > 0) reverse(playerList.begin(), playerList.begin() + currentPlayerIdx);

    // Reverse player order after current player
    if (currentPlayerIdx < playerList.size() - 1) reverse(playerList.begin() + currentPlayerIdx + 1, playerList.end());

    // Move current player to front
    if (currentPlayerIdx > 0) rotate(playerList.begin(), playerList.begin() + currentPlayerIdx, playerList.begin() + currentPlayerIdx + 1);

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

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);

}