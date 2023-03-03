// SwapCard.cpp
#include "../../header/Commands/SwapCard.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/IOException.h"
#include "algorithm"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
SwapCard::SwapCard() {
    this->command = CmdTypes::SwapCard;
    this->abilityType = AbilityTypes::SwapCard;
}

// return integer choice from input
int getInput(int lowerBound, int upperBound) {
    int choice = NULL;

    while (choice == NULL) {
        try {
            cin >> choice;

            if (choice < lowerBound || choice > upperBound) {
                throw InvalidChoice();
            
            }
        }

        catch(exception& err) {
            cout << err.what() << endl;
            choice = NULL;
        }
    }

    return choice;
}

// return player index that is chosen
int selectPlayer(CandyGameState& gameState, const vector<CandyPlayer>& playerList, string label) {

    if (playerList.empty()) {
        throw EmptyChoice();
    }

    cout << label << endl;
    gameState.printPlayerList(playerList);
    
    vector<int> ids;

    cout << "Pilihan player: ";

    return getInput(1, playerList.size()) - 1;
}

int selectCard(string playerName) {

    cout << "Silakan pilih kartu kanan/kiri dari " << playerName << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;

    return getInput(1, 2) - 1;
}

// Execute method
void SwapCard::executeCommand(CandyGameState& gameState) {
    
    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan SWAPCARD." << endl;

    // Get list of players other than currently playing
    vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin() + gameState.getCurrentTurnIdx());

    // Select Player 1

    int selectIdx1 = selectPlayer(gameState, otherPlayers, "Silakan pilih pemain yang kartunya ingin Anda tukar:");
    Player selectedPlayer1 = otherPlayers[selectIdx1];

    otherPlayers.erase(otherPlayers.begin() + selectIdx1);

    // Select Player 2
    int selectIdx2 = selectPlayer(gameState, otherPlayers, "Silakan pilih pemain lain yang kartunya ingin Anda tukar:");
    Player selectedPlayer2 = otherPlayers[selectIdx2];

    // Select card to take from player 1
    selectIdx1 = selectCard(selectedPlayer1.getName());

    cout << endl;

    // Select card to take from player 2
    selectIdx2 = selectCard(selectedPlayer2.getName());

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

    gameState.getPlayerRefAt(playerIdx1).switchCards(selectIdx1, selectIdx2, gameState.getPlayerRefAt(playerIdx2));

}