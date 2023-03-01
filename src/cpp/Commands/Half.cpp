// Half.cpp
#include "../../header/Commands/Half.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>

using std::cout;
using std::endl;

// ctor
Half::Half() {
    this->command = CmdTypes::Half;
}

// Execute method
bool Half::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Half) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    cout << "melakukan HALF! ";

    int oldPoint = gameState.getPointPool();
    int newPoint = oldPoint / 2;

    // Check if point has reached one
    if (oldPoint <= 1) {
        cout << "Sayangnya poin hadiah sudah bernilai " << oldPoint 
             << ". Poin tidak berubah.. Giliran dilanjut!" << endl;
    }

    // Halve the point pool
    gameState.setPointPool(newPoint);

    cout << "Poin hadiah turun dari " << oldPoint << " menjadi " << newPoint << "!" << endl;

    return true;
}