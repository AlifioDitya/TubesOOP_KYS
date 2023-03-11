// GameManager.cpp
#include "../../header/GameEnvironment/CandyGameManager.hpp"
#include "../../header/Cards/Card.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;

string fixFileExtension(string fileName) {
    // Fungsi memastikan fileName memiliki format .txt
    int idx = fileName.find('.');

    if (idx == -1) {
        fileName.append(".txt");
    } else if (fileName.length() - idx != 4 || fileName.substr(idx + 1, 3) != "txt") {
        fileName = fileName.substr(0, idx);
        fileName.append(".txt");
    }

    return fileName;
}

int stringToColorNum(string colorString) {
    if (colorString == "H") return 0;
    else if (colorString == "B") return 1;
    else if (colorString == "K") return 2;
    else if (colorString == "M") return 3;
    else return -1;
}

vector<Card> readDeckConfig() {
    vector<Card> v;

    while (true) {
        try {
            // Meminta Input Nama File
            string fileName;
            cout << "File name : ";
            cin >> fileName;

            // Membuat fileName pasti memiliki format .txt
            fileName = fixFileExtension(fileName);

            // Ini nanti fileName ditambah directory ke folder txt
            // fileName = "{ini Directory txt}/" + fileName;

            ifstream configFile(fileName);
            if (configFile) {
                int cardCount = 0;
                string temp;

                while (getline(configFile, temp)) {
                    int idx = temp.find(' '), len = temp.length();

                    if ((idx != 1) || !(len == 3 || len == 4)) {
                        throw InvalidFileInputFormatException();
                    }

                    int cardColor = stringToColorNum(temp.substr(0, idx));
                    int cardRank = stoi(temp.substr(idx + 1, len - 2));
                    if (cardColor == -1 || cardRank < 1 || cardRank > 13) throw InvalidFileInputFormatException();
                    v.push_back(Card(Color(cardColor), Rank(cardRank)));
                    cardCount++;
                }
                
                // Ini mungkin bisa juga throw kartu kurang exception
                if (cardCount != 52) throw InvalidFileInputFormatException();
                return v;
            } else {
                throw FileNotFoundException();
            }
        } catch(const exception& err) {
            cout << err.what() << endl;
            v.clear();
        }
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
