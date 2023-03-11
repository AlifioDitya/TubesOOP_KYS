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