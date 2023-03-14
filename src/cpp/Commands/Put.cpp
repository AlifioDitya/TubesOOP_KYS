// Next.cpp
#include "../../header/Commands/Put.hpp"
#include "../../enums/CangkulCmdTypes.hpp"
#include "../../header/Exception/CommandException.hpp"
#include "../../header/Program/IO.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Put::Put() {
    this->command = CangkulCmdTypes::Put;
}

void Put::validateCommand(CangkulGameState& gameState) {

}

// ========== Methods ==========

// Execute method
void Put::executeCommand(CangkulGameState& gameState) {
    
    validateCommand(gameState);

    cout << "Pilih kartu yang ingin diletakkan :" << endl;
    
    vector<Card> hand = gameState.getCurrentTurnPlayer().getHand();
    for (unsigned long int i = 0; i < hand.size(); i++) {
        cout << i + 1 << ". " << hand[i] << endl;
    }

    IO choiceIO;
    choiceIO.getInput(1, hand.size());

    if (gameState.getTableCards().countItems() > 0 && gameState.getTableCards().getCards().back().getColor() != hand[choiceIO.getChoice() - 1].getColor()) {
        throw UnmatchedColor();
    }

    cout << "Kartu berhasil diletakkan! Giliran pemain dilanjutkan." << endl;
    gameState.getTableCards().addItem(gameState.getCurrentTurnPlayer().PutCard(choiceIO.getChoice() - 1));
    bool isCurrentPlayerWinner = gameState.updateRoundWinner();

    if (gameState.getCurrentTurnPlayer().countItems() == 0) {
        cout << endl << gameState.getCurrentTurnPlayer().getName() << " berhasil menghabiskan kartunya" << endl << endl; 
        gameState.moveToWinningList();
        if (isCurrentPlayerWinner) gameState.setStartingPlayer(gameState.getCurrentTurnPlayer());

    } 
    
    else {

        if (isCurrentPlayerWinner) gameState.setStartingPlayer(gameState.getCurrentTurnPlayer());
        
        gameState.setNextTurn();
    }
}