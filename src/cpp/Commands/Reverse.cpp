
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

    // Reverse player order after current player
    reverse(playerList.begin() + 1, playerList.end());

    // Set the player list in reverse order
    gameState.setPlayerList(playerList);

    // Print out player order
    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan reverse!" << endl
         << "(sisa) Urutan eksekusi giliran ini: " << endl;
    gameState.printRemainingTurn();
    cout << endl;

    cout << "Urutan eksekusi giliran selanjutnya: " << endl;

    gameState.printNextRoundTurn();

    cout << endl;

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);
    gameState.setReversePlayerId(gameState.getCurrentTurnPlayer().getId());

    // Player that executes reverse will get another turn

}