// GameManager.cpp
#include "../../header/GameEnvironment/CandyGameManager.hpp"
#include "../../header/Cards/Card.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>
#include <fstream>


string fixFileExtension(string fileName, string extetion) {
    int idx = fileName.find('.');

    // hapus sufix string stlah titik, trus return tambahkan ".txt"

    return fileName;
}

vector<Card> readDeckConfig() {

    try {

        string fileName;

        cout << "File name : ";
        cin >> fileName;

        ifstream configFile(fileName);
    }

    catch(const exception& err) {
        cout << err.what() << endl;
    }
}

void CandyGameManager::inititateDeck() {
    // inisasi deck pada gamestate

    cout << "Pilihan konfigurasi deck card: " << endl;
    cout << "1. Acak" << endl;
    cout << "2. Konfigurasi File" << endl;

    IO choiceIO;
    cout << "Pilihan player: ";

    choiceIO.getChoice(1, 2);

    if (choiceIO == 1) {
        gameState.setDeckCards(DeckCard());
    }

    else {
        gameState.setDeckCards(readDeckConfig());
    }
}

vector<CandyPlayer> CandyGameManager::getInitialPlayerList(int playerNum) {

    // inisiasi setiap player beserta namanya

    vector<CandyPlayer> playerList;

    for (int i = 1; i <= playerNum; i++)
    {
        cout << "Masukkan nama pemain " << i << " : ";

        string playerName;
        
        cin >> playerName;

        playerList.push_back(CandyPlayer(i, vector<Card>(), 0, playerName, false));
    }

    return playerList;
}

void CandyGameManager::startRound() {

    // counter player yang sudah dapat giliran
    int count = 0;

    while (count < gameState.getPlayerList().size()) {
        
        // aksi pemain
        
        // giliran pemain selanjutnya
        gameState.getCurrentTurnPlayer().setHasPlayed(true);
        while(gameState.getCurrentTurnPlayer().hasPlayedThisRound()) gameState.setNextTurn();
        count++;
    }
}

void CandyGameManager::startSubGame() {
    // sub game jika belum ada pemenang

    // reset gamestate kecuali player dan turn

    gameState.setRound(0);
    gameState.setPointPool(CandyGameState::initialPoint);
    gameState.getTableCards().clear();

    // reset deck
    inititateDeck();


    // setiap player ambil 2 kartu dari deck
    for (int i = 0; i < gameState.getPlayerList().size(); i++) {
        CandyPlayer& player = gameState.getPlayerRefAt(i);

        player.setHand(gameState.getDeckCards().drawMany(2));
    }

    // main sampai 6 round
    while(gameState.getRound() < 6) {

        // round selanjutnya
        gameState.setRound(gameState.getRound() + 1);

        for (int i = 0; i < gameState.getPlayerList().size(); i++) {
            CandyPlayer& player = gameState.getPlayerRefAt(i);

            player.setHasPlayed(false);
        }

        startRound();

        // hitung pemenang round 
        //[disini]

        if (gameState.getRound() == 1) {
            // kasih ability ke setiap player
            //[disini]
        }

        // letak 1 kartu dari deck ke table
        gameState.getTableCards().addItem(gameState.getDeckCards().drawCard());
    }
}

void CandyGameManager::startGame() {
    // mulai game keseluruhan sampai ditemukan pemenang

    int winnerIdx = -1;
    cout << "Permainan baru dimulai!" << endl;

    // inisiasi gameState
    gameState = CandyGameState(getInitialPlayerList(7), 0, 0, CandyGameState::initialPoint, TableCard(), DeckCard());

    do {

        startSubGame();
        winnerIdx = gameState.getWinnerIndex();

    } while(winnerIdx == -1);

    cout << "Pemenangnya adalah " << gameState.getPlayerList()[winnerIdx].getName() << endl;

}
