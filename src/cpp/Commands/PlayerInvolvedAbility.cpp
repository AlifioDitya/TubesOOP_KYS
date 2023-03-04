// Abilityless.cpp
#include "../../header/Commands/PlayerInvolvedAbility.hpp"
#include "../../header/Exception/IOException.h"

int PlayerInvolvedAbility::getInput(int lowerBound, int upperBound) {
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
int PlayerInvolvedAbility::selectPlayer(CandyGameState& gameState, const vector<CandyPlayer>& playerList, string label) {

    if (playerList.empty()) {
        throw EmptyChoice();
    }

    cout << label << endl;
    gameState.printPlayerList(playerList);
    
    vector<int> ids;

    cout << "Pilihan player: ";

    return getInput(1, playerList.size()) - 1;
}