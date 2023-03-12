// Abilityless.cpp
#include "../../header/Commands/PlayerInvolvedAbility.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"

// return player index that is chosen
int PlayerInvolvedAbility::selectPlayer(CandyGameState& gameState, const vector<CandyPlayer>& playerList, string label) {

    if (playerList.empty()) {
        throw EmptyChoice();
    }

    cout << label << endl;
    gameState.printPlayerList(playerList);
    
    vector<int> ids;
    IO choiceIO;
    cout << "Pilihan player: ";

    choiceIO.getInput(1, playerList.size());

    return choiceIO.getChoice() - 1;
    
}