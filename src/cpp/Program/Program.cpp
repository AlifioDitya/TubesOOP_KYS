#include "../../header/Program/Program.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Program::start() {
    IO selection;

    cout << "Knock knock..." << endl;

    do {
        IO::newl();
        cout << "Lagi mau main apa kali ini?" << endl;
        cout << "1. Candy Game" << endl;
        cout << "2. Cangkul" << endl;
        cout << "3. Exit" << endl;
        IO::newl();

        selection.getInput(1, 4);

        if (selection == 1) {

            do {

                candyGameManager.startGame();

                cout << "Lanjut?" << endl;
                cout << "\t1. Main lagi" << endl;
                cout << "\t2. Exit" << endl;
                selection.getInput(1, 2);

            } while (selection == 1);

        } else if (selection == 2) {

            cangkulGameManager.startGame();

        } else if (selection == 4) {

            tfCardGameManager.startGame();

        }
        
    } while (selection.getChoice() != 3);
}