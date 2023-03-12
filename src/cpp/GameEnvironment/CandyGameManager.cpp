// GameManager.cpp
#include "../../header/GameEnvironment/CandyGameManager.hpp"
#include "../../header/Cards/Card.hpp"
#include "../../header/Exception/IOException.hpp"
#include "../../header/Program/IO.hpp"
#include "../../header/Commands/Abilityless.hpp"
#include "../../header/Commands/Double.hpp"
#include "../../header/Commands/Half.hpp"
#include "../../header/Commands/Next.hpp"
#include "../../header/Commands/Quadruple.hpp"
#include "../../header/Commands/Quarter.hpp"
#include "../../header/Commands/Reroll.hpp"
#include "../../header/Commands/Reverse.hpp"
#include "../../header/Commands/SwapCard.hpp"
#include "../../header/Commands/Switch.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::ifstream;
using std::max_element;

CandyGameManager::CandyGameManager() {
    actions = vector<Commands*>{
        new class Double(), 
        new class Half(), 
        new class Next(), 
    };

    abilities = map<AbilityTypes, class Ability*> {
        {AbilityTypes::Abilityless, new class Abilityless()},
        {AbilityTypes::Quadruple, new class Quadruple()},
        {AbilityTypes::Quadruple, new class Quadruple()},
        {AbilityTypes::Quarter, new class Quarter()},
        {AbilityTypes::Reroll, new class Reroll()},
        {AbilityTypes::Reverse, new class Reverse()},
        {AbilityTypes::SwapCard, new class SwapCard()},
        {AbilityTypes::Switch, new class Switch()},
    };
}

CandyGameManager::~CandyGameManager() {
    for (Commands* action: actions) {
        delete action;
    }

    for (auto abilityPair: abilities) {
        delete abilityPair.second;
    }
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

                    if ((idx != 1) || !(len == 4 || len == 5)) {
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

    gameState.setAbilities(AbilityDeckCard());

    cout << "Pilihan konfigurasi deck card: " << endl;
    cout << "1. Acak" << endl;
    cout << "2. Konfigurasi File" << endl;

    IO choiceIO;
    cout << "Pilihan player: ";

    choiceIO.getInput(1, 2);

    if (choiceIO == 1) {
        gameState.getDeckCards().defaultConfig();
    }

    else {
        gameState.setDeckCards(readDeckConfig());
    }
}

vector<CandyPlayer> CandyGameManager::getInitialPlayerList(int playerNum) const {

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


Commands* CandyGameManager::getPlayerCommand() {

    // menerima input aksi pemain saat ini
    IO choiceIO;
    CandyPlayer currentPlayer = gameState.getCurrentTurnPlayer();

    cout << "Pilihanmu (Contoh: DOUBLE) : ";

    string commandString;

    cin >> commandString;

    Commands* command = nullptr;

    do {

        try {
            CmdTypes commandType = Commands::parseCommand(commandString);

            if (commandType == CmdTypes::Ability)
            {
                command = abilities[Ability::parseAbility(commandString)];
            }

            else
            {
                command = actions[commandType];
            }
        }

        catch(const exception& err) {
            cout << err.what() << endl;
        }

    } while(!command);

    return command;
}

void CandyGameManager::startRound() {

    gameState.setAllNotPlayed();

    while (!gameState.hasAllPlayed()) {
        
        // aksi pemain
        CandyPlayer& currentPlayer = gameState.getCurrentTurnPlayer();
        cout << "Giliran pemain " << currentPlayer.getId() << ". " << currentPlayer.getName() << endl;
        cout << "Pilihan perintah: " << endl;
        cout << "1. DOUBLE" << endl;
        cout << "2. HALF" << endl;
        cout << "3. NEXT" << endl;
        cout << "4. ABILITYLESS" << endl;
        cout << "5. QUADRUPLE" << endl;
        cout << "6. QUARTER" << endl;
        cout << "7. RE-ROLL" << endl;
        cout << "8. REVERSE" << endl;
        cout << "9. SWAPCARD" << endl;
        cout << "10. SWITCH" << endl; 

        try {
            Commands* command = getPlayerCommand();
            
            command->executeCommand(gameState);
        }

        catch (const exception& err) {
            cout << err.what() << " Silahkan lakukan perintah lain." << endl;
        }
    }
}

void CandyGameManager::startSubGame() {
    // sub game jika belum ada pemenang

    // reset gamestate kecuali player dan turn

    gameState.setRound(0);
    gameState.setPointPool(CandyGameState::initialPoint);
    gameState.getTableCards().clear();
    gameState.setIsReversed(false);

    // reset deck
    inititateDeck();


    // setiap player ambil 2 kartu dari deck
    for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
        CandyPlayer& player = gameState.getPlayerRefAt(i);

        player.setHand(gameState.getDeckCards().drawMany(2));
    }

    // main sampai 6 round
    while(gameState.getRound() < 6) {

        // round selanjutnya
        gameState.setRound(gameState.getRound() + 1);

        startRound();


        if (gameState.getRound() == 1) {
            // kasih ability ke setiap player
            
            for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
                CandyPlayer& player = gameState.getPlayerRefAt(i);

                player.setAbility(gameState.getAbilities().drawCard());
            }
        }

        // letak 1 kartu dari deck ke table
        gameState.getTableCards().addItem(gameState.getDeckCards().drawCard());
    }

    // hitung pemenang subgame berdasarkan combo
    // [DISINI]
    // CandyPlayer& winner = ...;

    // winner.addPoint(gameState.getPointPool());
}

void CandyGameManager::startGame() {
    // mulai game keseluruhan sampai ditemukan pemenang

    CandyPlayer leadingPlayer;
    cout << "Permainan baru dimulai!" << endl;

    // inisiasi gameState
    gameState = CandyGameState(getInitialPlayerList(7), 0, CandyGameState::initialPoint, TableCard(), GameDeckCard(), AbilityDeckCard(), false);

    do {

        startSubGame();
        vector<CandyPlayer> playerList = gameState.getPlayerList();
        CandyPlayer leaderPlayer = getMax(playerList);

    } while(leadingPlayer.getPoint() >= CandyGameState::winnerPoint);

    cout << "Pemenangnya adalah " << leadingPlayer.getName() << endl;
}

template<class T>
bool compareGeneric(T a, T b) {
    return a.getValue() < b.getValue();
}

template<class T>
T CandyGameManager::getMax(vector<T>& list) {
    // asumsi list.size() > 0

    T maxElmt = list[0];

    for (auto i = list.begin() + 1; i != list.end(); i++)
    {
        if (i->getValue() > maxElmt.getValue()) maxElmt = *i;
    }
    
    return maxElmt;
}