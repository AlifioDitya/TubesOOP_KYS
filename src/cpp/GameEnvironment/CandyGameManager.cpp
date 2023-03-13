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
#include "../../header/Cards/Combination.hpp"
#include "../../header/GameEnvironment/GameState.hpp"
#include "../../header/GameEnvironment/CandyGameState.hpp"

#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::ifstream;
using std::max_element;
using std::endl;
using std::map;

void border() {
    cout << "==============================" << endl;
}

void newl() {
    cout << endl;
}

CandyGameManager::CandyGameManager() {
    actions = map<CmdTypes, Commands*> {
        {CmdTypes::Double, new class Double()},
        {CmdTypes::Half, new class Half()}, 
        {CmdTypes::Next, new class Next()}, 
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
    for (auto action: actions) {
        delete action.second;
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
    // Inisiasi deck pada gameState
    gameState.setAbilities(AbilityDeckCard());

    cout << "Pilihan konfigurasi deck card: " << endl;
    cout << "1. Acak" << endl;
    cout << "2. Konfigurasi File" << endl;
    newl();

    IO choiceIO;
    cout << "Pilihan : ";

    choiceIO.getInput(1, 2);

    if (choiceIO == 1) {
        gameState.getDeckCards().defaultConfig();
    
    } else {
        gameState.setDeckCards(readDeckConfig());
    }

}

vector<CandyPlayer> CandyGameManager::getInitialPlayerList(int playerNum) const {
    // Inisiasi setiap player beserta namanya
    vector<CandyPlayer> playerList;

    for (int i = 1; i <= playerNum; i++) {
        string playerName;

        // cout << "Masukkan nama pemain " << i << " : ";
        // cin >> playerName;

        // playerList.push_back(CandyPlayer(i, vector<Card>(), 0, playerName, false));

        playerList.push_back(CandyPlayer(i, vector<Card>(), 0, "temp" + std::to_string(i), false)); // testing
    }

    return playerList;
}


Commands* CandyGameManager::getPlayerCommand() {
    // Menerima input aksi pemain saat ini
    IO choiceIO;
    CandyPlayer currentPlayer = gameState.getCurrentTurnPlayer();
    string commandString;
    Commands* command = nullptr;

    do {
        try {
            cout << "Pilihanmu (Contoh: DOUBLE) : ";
            cin >> commandString;
            newl();

            CmdTypes commandType = Commands::parseCommand(commandString);

            if (commandType == CmdTypes::Ability) {
                command = abilities[Ability::parseAbility(commandString)];
            } else {
                command = actions[commandType];
            }
        } catch(const exception& err) {
            cout << err.what() << endl;
        }
    } while (!command);

    return command;
}

void CandyGameManager::startRound() {
    gameState.setAllNotPlayed();

    while (!gameState.hasAllPlayed()) {
        // aksi pemain
        CandyPlayer& currentPlayer = gameState.getCurrentTurnPlayer();
        newl();
        border();

        cout << "Giliran pemain " << currentPlayer.getId() << " : " << currentPlayer.getName() << endl << endl;

        cout << "Berikut kartu pada table : " << endl;
        gameState.getTableCards().showCards();
        cout<< endl;

        cout << "Berikut kartu yang kamu miliki : " << endl;
        currentPlayer.printHand();
        newl();

        if (currentPlayer.getAbility() != AbilityTypes::None && !currentPlayer.hasUsedAbility()) {
            cout << "Ability yang sedang dimiliki: " << Ability::parseAbility(currentPlayer.getAbility()) << endl << endl;
        }

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
        newl();

        bool stop = false;

        while (!stop)
        {
            try {
            Commands* command = getPlayerCommand();
            command->executeCommand(gameState);
            stop = true;
            } catch (const exception& err) {
                cout << err.what() << " Silahkan lakukan perintah lain." << endl;
            }
        }

    }
    
    newl();
    cout << "Satu putaran selesai!" << endl;
    border();
    newl();
    newl();
}

void CandyGameManager::startSubGame() {
    // Sub Game jika belum ada pemenang
    // Reset gamestate kecuali player dan turn
    // gameState.setRound(5); // testing
    // gameState.setPointPool(CandyGameState::winnerPoint); // testing
    gameState.setRound(0);
    gameState.setPointPool(CandyGameState::initialPoint);
    gameState.getTableCards().clear();

    // Reset deck
    inititateDeck();

    // Setiap player ambil 2 kartu dari deck
    for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
        CandyPlayer& player = gameState.getPlayerRefAt(i);
        player.setHand(gameState.getDeckCards().drawMany(2));
    }

    // Main sampai 6 round
    while(gameState.getRound() < 6) {
        // Round selanjutnya
        gameState.setRound(gameState.getRound() + 1);

        // testing
        if (gameState.getRound() == 1) {
            // Memberikan ability ke setiap player

            cout << "Ability akan dibagikan ke setiap pemain!" << endl;
            newl();

            for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
                CandyPlayer& player = gameState.getPlayerRefAt(i);
                player.setAbility(gameState.getAbilities().drawCard());
            }
        }
        
        startRound();

        
        // if (gameState.getRound() == 1) {
        //     // Memberikan ability ke setiap player

        //     cout << "Ability akan dibagikan ke setiap pemain!" << endl;
        //     newl();

        //     for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
        //         CandyPlayer& player = gameState.getPlayerRefAt(i);
        //         player.setAbility(gameState.getAbilities().drawCard());
        //     }
        // }

        // Meletakkan 1 kartu dari deck ke table
        gameState.getTableCards().addItem(gameState.getDeckCards().drawCard());

        cout << "Satu kartu diletakkan ke meja : " << gameState.getTableCards().getCards().back() << endl;
        newl(); 
    }

    class ComboCompare {
        public:
        bool operator() (const Combination& a, const Combination& b) const {
            return a.getValue() < b.getValue();
        }
    };

    map<Combination, CandyPlayer, ComboCompare> combosMap;
    vector<Combination> combos;
    // Hitung pemenang Sub Game berdasarkan combo
    for (auto player: gameState.getPlayerList()) {
        Combination combo(gameState.getTableCards().getCards(), player.getHand());
        combosMap[combo] = player;
        combos.push_back(combo);
    }

    CandyPlayer& winner = gameState.getPlayerRefAt(gameState.getPlayerIdx(combosMap[getMax(combos)].getId()));
    winner.addPoint(gameState.getPointPool());

}

void CandyGameManager::startGame() {
    // Mulai game keseluruhan sampai ditemukan pemenang

    CandyPlayer leadingPlayer;

    newl();
    cout << "PERMAINAN DIMULAI!" << endl;
    newl();

    // Inisiasi gameState
    gameState = CandyGameState(getInitialPlayerList(7), 0, CandyGameState::initialPoint, TableCard(), GameDeckCard(), AbilityDeckCard(), false);
    
    int counter = 0;

    do {
        if (counter > 0) {
            newl();
            border();
            gameState.printLeaderBoard();
            cout << "Pemenang belum ditemukan!" << endl;
            cout << "Permainan akan dilanjutkan" << endl;
            border();
            newl();
        }

        startSubGame();
        vector<CandyPlayer> playerList = gameState.getPlayerList();
        leadingPlayer = getMax(playerList);

        counter++;

    } while(leadingPlayer.getPoint() >= CandyGameState::winnerPoint);

    newl();
    border();
    cout << "Permainan Berakhir.";
    gameState.printLeaderBoard();
    cout << "Permainan dimenangkan oleh " << leadingPlayer.getName() << endl;
    border();
    newl();
}
