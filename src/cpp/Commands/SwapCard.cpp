// SwapCard.cpp
#include "../../header/Commands/SwapCard.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Program/IO.hpp"
#include "algorithm"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// ctor
SwapCard::SwapCard() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::SwapCard;
}

int SwapCard::selectCard(string playerName) {

    cout << "Silakan pilih kartu kanan/kiri dari " << playerName << endl;
    cout << "1. Kanan" << endl;
    cout << "2. Kiri" << endl;
    
    IO inputIO;
    inputIO.getInput(1, 2);
    return inputIO.getChoice() - 1;
}

// Execute method
void SwapCard::executeCommand(CandyGameState& gameState) {
    
    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan SWAPCARD." << endl;

    // Get list of players other than currently playing
    vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin());

    // Select Player 1

    int selectIdx1 = selectPlayer(gameState, otherPlayers, "Silakan pilih pemain yang kartunya ingin Anda tukar:");
    CandyPlayer selectedPlayer1 = otherPlayers[selectIdx1];

    otherPlayers.erase(otherPlayers.begin() + selectIdx1);

    // Select Player 2
    int selectIdx2 = selectPlayer(gameState, otherPlayers, "Silakan pilih pemain lain yang kartunya ingin Anda tukar:");
    CandyPlayer selectedPlayer2 = otherPlayers[selectIdx2];

    // Select card to take from player 1
    selectIdx1 = selectCard(selectedPlayer1.getName());

    cout << endl;

    // Select card to take from player 2
    selectIdx2 = selectCard(selectedPlayer2.getName());

    // Swap the cards

    int idx1 = gameState.getPlayerIdx(otherPlayers[selectIdx1].getId());
    int idx2 = gameState.getPlayerIdx(otherPlayers[selectIdx2].getId());


    gameState.getPlayerRefAt(idx1).switchCards(selectIdx1, selectIdx2, gameState.getPlayerRefAt(idx2));

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);
    gameState.setNextTurn();

}