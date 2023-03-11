// GameManager.cpp
#include "../../header/GameEnvironment/CandyGameManager.hpp"
#include "../../header/Cards/Card.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>
#include <fstream>

vector<CandyPlayer> getInitialPlayerList(int playerNum) {
    vector<CandyPlayer> playerList;
    for (int i = 1; i <= playerNum; i++)
    {
        playerList.push_back(CandyPlayer(i, vector<Card>(), 0, "", false));
    }

    return playerList;
}



void CandyGameManager::initateGame() {
    gameState = CandyGameState(getInitialPlayerList(7), 0, 0, 64, TableCard(), DeckCard());
}

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

void CandyGameManager::inititateNewRound() {
    gameState.setRound(gameState.getRound() + 1);
    gameState.setPointPool(gameState.getPointPool() + 1);
}

void CandyGameManager::startGame() {
    

}