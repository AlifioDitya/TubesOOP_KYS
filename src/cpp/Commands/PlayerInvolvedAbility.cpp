// PlayerInvolvedAbility.cpp
#include "../../header/Commands/PlayerInvolvedAbility.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include "../../header/GameEnvironment/GameState.hpp"
#include <iostream>

using std::endl;
using std::cout;

// ========== Protected Methods ==========

int
PlayerInvolvedAbility::selectPlayer(CandyGameState& gameState, const vector <CandyPlayer>& playerList, string label) {
    if (playerList.empty()) {
        throw EmptyChoice();
    }

    cout << label << endl;
    gameState.printPlayerList(playerList);

    vector<int> ids;
    IO choiceIO;

    choiceIO.getInput(1, playerList.size());

    return choiceIO.getChoice() - 1;
}