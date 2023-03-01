// SwapCard.cpp
#include "../../header/Commands/SwapCard.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
SwapCard::SwapCard() {
    this->command = CmdTypes::SwapCard;
}

// Execute method
bool SwapCard::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::SwapCard) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has the SwapCard ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::SwapCard)) {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability untuk SWAPCARD." << endl;
        return false;
    }

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan SWAPCARD." << endl;

    // Get list of players other than currently playing
    vector<Player> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin() + gameState.getCurrentTurnIdx());

    // Select Player 1
    cout << "Silakan pilih pemain yang kartunya ingin Anda tukar:" << endl;

    gameState.printPlayerList(otherPlayers);

    int selectIdx1 = 0;
    cin >> selectIdx1;
    selectIdx1--;

    Player selectedPlayer1 = otherPlayers[selectIdx1];
    otherPlayers.erase(otherPlayers.begin() + selectIdx1);

    // Select Player 2
    cout << "Silakan pilih pemain lain yang kartunya ingin Anda tukar:" << endl;

    gameState.printPlayerList(otherPlayers);

    int selectIdx2 = 0;
    cin >> selectIdx2;
    selectIdx2--;

    Player selectedPlayer2 = otherPlayers[selectIdx2];

    // Select card to take from player 1
    cout << "Silakan pilih kartu kanan/kiri dari " << selectedPlayer1.getName() << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;

    cin >> selectIdx1;
    selectIdx1--;

    cout << endl;

    // Select card to take from player 2
    cout << "Silakan pilih kartu kanan/kiri dari " << selectedPlayer2.getName() << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;

    cin >> selectIdx2;
    selectIdx2--;

    // Swap the cards
    int playerIdx1 = 0;
    int playerIdx2 = 0;
    for (int i = 0; i < gameState.getPlayerList().size(); i++) {
        if (gameState.getPlayerList()[i].getId() == selectedPlayer1.getId()) {
            playerIdx1 = i;
        } else if (gameState.getPlayerList()[i].getId() == selectedPlayer2.getId()) {
            playerIdx2 = i;
        }
    }

    Card playerCard1 = gameState.getPlayerList()[playerIdx1].getHand()[selectIdx1];
    Card playerCard2 = gameState.getPlayerList()[playerIdx2].getHand()[selectIdx2];
    
    gameState.getPlayerRefAt(playerIdx1).setHand(selectIdx1, playerCard2);
    gameState.getPlayerRefAt(playerIdx2).setHand(selectIdx2, playerCard1);

    return true;
}