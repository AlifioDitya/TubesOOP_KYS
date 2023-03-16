#include "../../header/EasterEgg/TFCardGameManager.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::numeric_limits;
using std::streamsize;

void TFCardGameManager::startGame() {
    IO selection;

    IO::newl();
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
        cout << endl;

        if (selection == 1) {
            cout << "Masukkan empat muka kartu terpisah oleh spasi." << endl;
            cout << endl;
            player.inputHand(4);
        } else if (selection == 2) {
            player.generateRandomHand(4);
            // Clear input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            running = false;
            break;
        }

        cout << "Kartu anda adalah:" << endl;
        player.printHand();
        cout << endl;

        solver.setCards(player.getHand());

        string blank;
        cout << "Klik enter untuk melihat solusi.";
        getline(cin, blank);
        cout << endl;

        solver.solve24();

        solver.printSolutions();

        // Option to re-run or terminate
        char rerun;
        do {
            cout << "Apakah anda ingin mencoba lagi? [y/n]\n\nPilihan : ";
            cin >> rerun;
            cout << endl;

            if (rerun == 'n') {
                running = false;
                break;
            }
        } while (rerun != 'y' && rerun != 'n');
        
        solver.clearSolutions();

    } while (running);

    cout << "*** Teleportasi kembali ke OOP ***" << endl;
}
