// Switch.cpp
#include "../../header/Commands/Switch.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
Switch::Switch() {
    this->command = CmdTypes::Switch;
    this->abilityType = AbilityTypes::Switch;
}

// Execute method
void Switch::executeCommand(CandyGameState& gameState) {
    
    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan SWITCH!" << endl;

    // Display current hand
    cout << "Kartumu sekarang adalah:" << endl;
    gameState.getCurrentTurnPlayer().printHand();

    // Get list of players other than currently playing
    vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin() + gameState.getCurrentTurnIdx());

    // Select player to switch
    cout << "Silakan pilih pemain yang ingin Anda tukar:" << endl;

    gameState.printPlayerList(otherPlayers);

    int selectIdx = 0;
    cin >> selectIdx;
    selectIdx--;

    // Switch hands
    for (int i = 0; i < gameState.getPlayerList().size(); i++) {
        if (gameState.getPlayerList()[i].getId() == otherPlayers[selectIdx].getId()) {
            gameState.getCurrentTurnPlayer().switchCards(gameState.getPlayerRefAt(i));
            break;
        }
    }

    cout << "Kedua kartu Anda telah ditukar dengan " << otherPlayers[selectIdx].getName() << "!" << endl;
    cout << "Kartumu sekarang adalah:" << endl;
    gameState.getCurrentTurnPlayer().printHand();

}