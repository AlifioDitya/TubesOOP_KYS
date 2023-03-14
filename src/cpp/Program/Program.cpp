#include "../../header/Program/Program.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Program::start() {
    cout << "Knock knock..." << endl << endl;

    cout << "Lagi mau main apa kali ini?" << endl;
    cout << "1. Candy Game" << endl;
    cout << "2. Cangkul" << endl;
    cout << endl;
    cout << "Pilihanmu: ";

    IO selection;
    selection.getInput(1, 2);
    
    if (selection == 1) {
        candyGameManager.startGame();
    } else {
        cangkulGameManager.startGame();
    }
    
}