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

SwapCard::SwapCard() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::SwapCard;
}

int SwapCard::selectCard(string playerName) {

    cout << "Silakan pilih kartu kanan/kiri dari " << playerName << " :" << endl;
    cout << "1. Kiri" << endl;
    cout << "2. Kanan" << endl;

    IO inputIO;
    inputIO.getInput(1, 2);
    return inputIO.getChoice() - 1;
}

// ========== Methods ==========

void SwapCard::executeCommand(CandyGameState& gameState) {
    validateAbility(gameState);

    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan SWAPCARD." << endl;

    // Get list of players other than currently playing
    vector<CandyPlayer> otherPlayers = gameState.getPlayerList();
    otherPlayers.erase(otherPlayers.begin());

    // Select Player 1

    int selectPlayerIdx1 = selectPlayer(gameState, otherPlayers,
                                        "Silakan pilih pemain yang kartunya ingin Anda tukar:");
    CandyPlayer selectedPlayer1 = otherPlayers[selectPlayerIdx1];

    otherPlayers.erase(otherPlayers.begin() + selectPlayerIdx1);

    // Select Player 2
    int selectPlayerIdx2 = selectPlayer(gameState, otherPlayers,
                                        "Silakan pilih pemain lain yang kartunya ingin Anda tukar:");
    CandyPlayer selectedPlayer2 = otherPlayers[selectPlayerIdx2];

    // Player indexes

    int playerIdx1 = gameState.getPlayerIdx(selectedPlayer1.getId());
    int playerIdx2 = gameState.getPlayerIdx(selectedPlayer2.getId());

    // Select card to take from player 1
    int selectCardIdx1 = selectCard(selectedPlayer1.getName());

    cout << endl;

    // Select card to take from player 2
    int selectCardIdx2 = selectCard(selectedPlayer2.getName());

    // swap
    gameState.getPlayerRefAt(playerIdx1).switchCards(selectCardIdx1, selectCardIdx2,
                                                     gameState.getPlayerRefAt(playerIdx2));

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);
    gameState.setNextTurn();
}