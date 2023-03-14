// Switch.cpp
#include "../../header/Commands/Switch.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "algorithm"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::find_if;

Switch::Switch() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Switch;
}

// ========== Methods ==========

void Switch::executeCommand(CandyGameState& gameState) {
    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan SWITCH!" << endl;

    // Display current hand
    cout << "Kartumu sekarang adalah:" << endl;
    gameState.getCurrentTurnPlayer().printHand();

    // Get list of players other than currently playing
    vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin());

    // Select player to switch
    int selectIdx = selectPlayer(gameState, otherPlayers, "Silakan pilih pemain yang kartunya ingin Anda tukar:");

    // Switch hands
    int idx = gameState.getPlayerIdx(otherPlayers[selectIdx].getId());

    gameState.getCurrentTurnPlayer().switchCards(gameState.getPlayerRefAt(idx));

    cout << "Kedua kartu Anda telah ditukar dengan " << otherPlayers[selectIdx].getName() << "!" << endl;
    cout << "Kartumu sekarang adalah:" << endl;
    gameState.getCurrentTurnPlayer().printHand();

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);
    gameState.setNextTurn();
}