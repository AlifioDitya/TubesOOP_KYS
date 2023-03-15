// Half.cpp
#include "../../header/Commands/Half.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>

using std::cout;
using std::endl;

Half::Half() {
    this->command = CmdTypes::Half;
}

// ========== Methods ==========

void Half::executeCommand(CandyGameState& gameState) {
    cout << gameState.getCurrentTurnPlayer().getName() << " melakukan HALF! ";

    uint64_t oldPoint = gameState.getPointPool();
    uint64_t newPoint = oldPoint / 2;

    // Check if point has reached one
    if (oldPoint <= 1) {
        cout << " Sayangnya poin hadiah sudah bernilai " << oldPoint
             << ". Poin tidak berubah.. Giliran dilanjut!" << endl;
    } else {
        // Halve the point pool
        gameState.setPointPool(newPoint);

        cout << " Poin hadiah turun dari " << oldPoint << " menjadi " << newPoint << "!" << endl;
    }

    gameState.setNextTurn();
}