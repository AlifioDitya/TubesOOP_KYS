// CandyGameManager.cpp
#include "../../header/GameEnvironment/CandyGameManager.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>

#include "../../header/Cards/Card.hpp"
#include "../../header/Cards/Combination.hpp"
#include "../../header/Cards/CombinationUtilities.hpp"
#include "../../header/Cards/Combinations/Flush.hpp"
#include "../../header/Cards/Combinations/FourOfAKind.hpp"
#include "../../header/Cards/Combinations/FullHouse.hpp"
#include "../../header/Cards/Combinations/HighCard.hpp"
#include "../../header/Cards/Combinations/Pair.hpp"
#include "../../header/Cards/Combinations/Straight.hpp"
#include "../../header/Cards/Combinations/StraightFlush.hpp"
#include "../../header/Cards/Combinations/ThreeOfAKind.hpp"
#include "../../header/Cards/Combinations/TwoPair.hpp"
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
#include "../../header/Exception/IOException.hpp"
#include "../../header/GameEnvironment/CandyGameState.hpp"
#include "../../header/GameEnvironment/GameState.hpp"
#include "../../header/Program/IO.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::max_element;

CandyGameManager::CandyGameManager() {
    actions = map<CmdTypes, Commands*>{
        {CmdTypes::Double, new class Double()},
        {CmdTypes::Half, new class Half()},
        {CmdTypes::Next, new class Next()},
    };

    abilities = map<AbilityTypes, class Ability*>{
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
    for (auto action : actions) {
        delete action.second;
    }

    for (auto abilityPair : abilities) {
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
    if (colorString == "H")
        return 0;
    else if (colorString == "B")
        return 1;
    else if (colorString == "K")
        return 2;
    else if (colorString == "M")
        return 3;
    else
        return -1;
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
            fileName = "../txt/" + fileName;

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
                    if (cardColor == -1 || cardRank < 1 || cardRank > 13)
                        throw InvalidFileInputFormatException();
                    v.push_back(Card(Color(cardColor), Rank(cardRank)));
                    cardCount++;
                }

                // Ini mungkin bisa juga throw kartu kurang exception
                if (cardCount != 52)
                    throw InvalidFileInputFormatException();
                return v;
            } else {
                throw FileNotFoundException();
            }

        } catch (const exception& err) {
            cout << err.what() << endl;
            v.clear();
        }
    }
}

int CandyGameManager::initialDraw = 2;

// ========== Private Methods ==========

vector<CandyPlayer> CandyGameManager::getInitialPlayerList(int playerNum) const {
    // Inisiasi setiap player beserta namanya
    vector<CandyPlayer> playerList;

    for (int i = 1; i <= playerNum; i++) {
        string playerName;

        // cout << "Masukkan nama pemain " << i << " : ";
        // cin >> playerName;

        // playerList.push_back(CandyPlayer(i, vector<Card>(), 0, playerName, false));

        playerList.push_back(
            CandyPlayer(i, vector<Card>(), 0, "temp" + std::to_string(i), false));  // testing
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
            IO::newl();

            CmdTypes commandType = Commands::parseCommand(commandString);

            if (commandType == CmdTypes::Ability) {
                command = abilities[Ability::parseAbility(commandString)];
            } else {
                command = actions[commandType];
            }
        } catch (const exception& err) {
            cout << err.what() << endl;
        }
    } while (!command);

    return command;
}

void CandyGameManager::initiateDeck() {
    // Inisiasi deck pada gameState
    gameState.setAbilities(AbilityDeckCard());

    cout << "Pilihan konfigurasi deck card: " << endl;
    cout << "1. Acak" << endl;
    cout << "2. Konfigurasi File" << endl;
    IO::newl();

    IO choiceIO;

    choiceIO.getInput(1, 2);

    if (choiceIO == 1) {
        gameState.getDeckCards().defaultConfig();
    } else {
        gameState.setDeckCards(readDeckConfig());
    }
}

void CandyGameManager::startRound() {
    gameState.setAllNotPlayed();

    while (!gameState.hasAllPlayed()) {
        // aksi pemain
        CandyPlayer& currentPlayer = gameState.getCurrentTurnPlayer();
        IO::newl();
        IO::border();

        cout << "Giliran pemain " << currentPlayer.getId() << " : " << currentPlayer.getName()
             << endl
             << endl;

        cout << "Berikut kartu pada table : " << endl;
        gameState.getTableCards().showCards();
        cout << endl;

        cout << "Berikut kartu yang kamu miliki : " << endl;
        currentPlayer.printHand();
        IO::newl();

        if (currentPlayer.getAbility() != AbilityTypes::None && !currentPlayer.hasUsedAbility()) {
            cout << "Ability yang sedang dimiliki: "
                 << Ability::parseAbility(currentPlayer.getAbility()) << endl
                 << endl;
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
        IO::newl();

        bool stop = false;

        while (!stop) {
            try {
                Commands* command = getPlayerCommand();
                command->executeCommand(gameState);
                stop = true;
            } catch (const exception& err) {
                cout << err.what() << " Silahkan lakukan perintah lain." << endl;
            }
        }
    }

    IO::newl();
    cout << "Satu putaran selesai!" << endl;
    IO::border();
    IO::newl();
    IO::newl();
}

// TODO: Test if this is removed
template <>
Combination* CandyGameManager::getMax(vector<Combination*>& list) {
    // asumsi list.size() > 0

    Combination* maxElmt = list[0];

    for (auto i = list.begin() + 1; i != list.end(); i++) {
        if ((*i)->getValue() > maxElmt->getValue())
            maxElmt = *i;
    }

    return maxElmt;
}

Combination* CandyGameManager::findComboType(const vector<Card> tableCards,
                                             const vector<Card> handCards) {
    Combination* combo;
    pair<int, int> cardPair;

    if ((combo = StraightFlush::getStraightFlush(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = FourOfAKind::getFourOfAKind(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = FullHouse::getFullHouse(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = Flush::getFlush(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = Straight::getStraight(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = ThreeOfAKind::getThreeOfAKind(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = TwoPair::getTwoPair(tableCards, handCards)) != NULL) {
        return combo;
    } else if ((combo = Pair::getPair(tableCards, handCards)) != NULL) {
        return combo;
    } else {
        combo = HighCard::getHighCard(tableCards, handCards);
        return combo;
    }
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
    initiateDeck();

    // Setiap player ambil 2 kartu dari deck
    for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
        CandyPlayer& player = gameState.getPlayerRefAt(i);
        player.setHand(gameState.getDeckCards().drawMany(CandyGameManager::initialDraw));
    }

    // Main sampai 6 round
    while (gameState.getRound() < 6) {
        // Round selanjutnya
        gameState.setRound(gameState.getRound() + 1);

        // testing
        if (gameState.getRound() == 1) {
            // Memberikan ability ke setiap player

            cout << "Ability akan dibagikan ke setiap pemain!" << endl;
            IO::newl();

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

        if (gameState.getRound() < 6) {
            gameState.getTableCards().addItem(gameState.getDeckCards().drawCard());
        }

        cout << "Satu kartu diletakkan ke meja : " << gameState.getTableCards().getCards().back()
             << endl;
        IO::newl();
    }

    class ComboCompare {
       public:
        bool operator()(const Combination* a, const Combination* b) const {
            return a->getValue() < b->getValue();
        }
    };

    map<Combination*, CandyPlayer, ComboCompare> combosMap;
    vector<Combination*> combos;
    // Hitung pemenang Sub Game berdasarkan combo
    for (auto player : gameState.getPlayerList()) {
        Combination* combo = findComboType(gameState.getTableCards().getCards(), player.getHand());
        combosMap[combo] = player;
        combos.push_back(combo);
    }

    CandyPlayer& winner =
        gameState.getPlayerRefAt(gameState.getPlayerIdx(combosMap[getMax(combos)].getId()));
    winner.addPoint(gameState.getPointPool());

    for (Combination* combo : combos) {
        delete combo;
    }
}

// ========== Methods ==========

void CandyGameManager::startGame() {
    // Mulai game keseluruhan sampai ditemukan pemenang

    CandyPlayer leadingPlayer;

    IO::newl();
    cout << "PERMAINAN DIMULAI!" << endl;
    IO::newl();

    // Inisiasi gameState
    gameState = CandyGameState(getInitialPlayerList(7), 0, CandyGameState::initialPoint,
                               TableCard(), GameDeckCard(), AbilityDeckCard(), false);

    int counter = 0;

    do {
        if (counter > 0) {
            IO::newl();
            IO::border();
            gameState.printLeaderBoard();
            cout << "Pemenang belum ditemukan!" << endl;
            cout << "Permainan akan dilanjutkan" << endl;
            IO::border();
            IO::newl();
        }

        startSubGame();
        vector<CandyPlayer> playerList = gameState.getPlayerList();
        leadingPlayer = getMax(playerList);

        counter++;
    } while (leadingPlayer.getPoint() < CandyGameState::winnerPoint);

    IO::newl();
    IO::border();
    cout << "Permainan Berakhir.";
    gameState.printLeaderBoard();
    cout << "Permainan dimenangkan oleh " << leadingPlayer.getName() << "." << endl;
    IO::border();
    IO::newl();
}