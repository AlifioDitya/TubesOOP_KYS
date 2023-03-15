#include "../../header/EasterEgg/TFCardGameManager.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::getline;
using std::cin;

void TFCardGameManager::startGame() {
    IO selection;

    cout << "Anda nyasar ke STIMA land..." << endl;
    cout << endl;

    cout << "Selamat datang di 24 card solver!" << endl;

    bool running = true;

    do {
        IO::newl();
        cout << "Pilih metode pembangkitan kartu:" << endl;
        cout << "1. Input manual" << endl;
        cout << "2. Random" << endl;
        cout << "3. Exit" << endl;
        IO::newl();

        selection.getInput(1,3);

        if (selection == 2) {
            player.generateRandomHand();
        } else {
            running = false;
            break;
        }

        cout << "Kartu anda adalah:" << endl;
        player.printHand();
        cout << endl;

        solver.setCards(player.getHand());

        string blank;
        cout << "Klik enter untuk melihat solusi." << endl;
        getline(cin, blank);

        solver.solve24();

        solver.printSolutions();

        // Option to re-run or terminate
        char rerun;
        do {
            cout << "Apakah anda ingin mencoba lagi? [y/n]\n\Pilihan : ";
            cin >> rerun;
            cout << endl;

            if (rerun == 'n') {
                running = false;
                break;
            }
        } while (rerun != 'y' && rerun != 'n');
        
    } while (running);
    
    IO::newl();
}
