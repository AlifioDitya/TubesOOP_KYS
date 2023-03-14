// CangkulGameManager.cpp
#include "../../header/GameEnvironment/CangkulGameManager.hpp"
#include "../../header/Program/IO.hpp"
#include "../../header/Commands/Put.hpp"
#include "../../header/Commands/Cangkul.hpp"
#include "../../header/Commands/Skip.hpp"

#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::pair;

int CangkulGameManager::initialDraw = 7;

CangkulGameManager::CangkulGameManager() {
    actions = map<CangkulCmdTypes, CangkulCommand*> {
        {CangkulCmdTypes::Put, new class Put()},
        {CangkulCmdTypes::Cangkul, new class Cangkul()}, 
        {CangkulCmdTypes::Skip, new class Skip()}, 
    };

}

CangkulGameManager::~CangkulGameManager() {
    for (auto action: actions) {
        delete action.second;
    }
}

// ========== Private Methods ==========

void CangkulGameManager::initializePlayerCount() {

    IO choiceIO;

    IO::newl();
    cout << "Pilihan Jumlah Pemain :" << endl;
    cout << "1. Dua Pemain" << endl;
    cout << "2. Tiga Pemain" << endl;
    cout << "3. Empat Pemain" << endl;

    choiceIO.getInput(1, 3);

    playerCount = choiceIO.getChoice() + 1;
}

CangkulCommand* CangkulGameManager::getPlayerCommand() {
    // Menerima input aksi pemain saat ini
    IO choiceIO;
    Player currentPlayer = gameState.getCurrentTurnPlayer();
    string commandString;
    CangkulCommand* command = nullptr;

    do {
        try {
            cout << "Pilihanmu (Contoh: PUT) : ";
            cin >> commandString;
            IO::newl();

            CangkulCmdTypes commandType = CangkulCommand::parseCommand(commandString);

            command = actions[commandType];

        } catch(const exception& err) {
            cout << err.what() << endl;
        }
    } while (!command);

    return command;
}

vector<Player> CangkulGameManager::getInitialPlayerList(int playerNum) const {
    // Inisiasi setiap player beserta namanya
    vector<Player> playerList;

    for (int i = 1; i <= playerNum; i++) {
        string playerName;

        cout << "Masukkan nama pemain " << i << " : ";
        cin >> playerName;

        playerList.push_back(Player(i, vector<Card>(), playerName, false));

        // playerList.push_back(Player(i, vector<Card>(), "temp" + std::to_string(i), false)); // testing
    }

    return playerList;
}

void CangkulGameManager::startRound() {
    gameState.setAllNotPlayed();

    if (gameState.getStartingPlayerId() != 0) {

        while (gameState.getCurrentTurnPlayer().getId() != gameState.getStartingPlayerId()) {
            gameState.skipCurrentPlayer();
        }
    }

    while (!gameState.hasAllPlayed() && gameState.getPlayerList().size() > 1) {
        // aksi pemain
        Player& currentPlayer = gameState.getCurrentTurnPlayer();
        IO::newl();
        IO::border();

        cout << "Giliran pemain " << currentPlayer.getId() << " : " << currentPlayer.getName() << endl << endl;

        if (gameState.getTableCards().countItems() > 0) {
            cout << "Berikut kartu pada table : " << endl;
            gameState.getTableCards().showCards();
            cout<< endl;

        } else {
            cout << "Kamu menentukan warna kartu pada round ini!" << endl;
            IO::newl();
        }

        cout << "Berikut kartu yang kamu miliki : " << endl;
        currentPlayer.printHand();
        IO::newl();

        cout << "Pilihan perintah: " << endl;
        cout << "1. PUT" << endl;
        cout << "2. CANGKUL" << endl;
        cout << "3. SKIP" << endl;

        IO::newl();

        bool stop = false;

        while (!stop) {
            try {
            CangkulCommand* cangkulCommand = getPlayerCommand();
            cangkulCommand->executeCommand(gameState);
            stop = true;
            } catch (const exception& err) {
                cout << err.what() << " Silahkan lakukan perintah lain." << endl;
            }
        }
    }
    
    IO::newl();
    if (gameState.hasAllPlayed()) {
        cout << "Satu putaran selesai!" << endl;
        cout << gameState.getPlayerRefAt(gameState.getPlayerIdx(gameState.getStartingPlayerId())).getName() << " memiliki nilai kartu tertinggi pada round ini!" << endl;
    }
    IO::newl();
    IO::border();
    IO::newl();
}

void CangkulGameManager::startSubGame() {
    // Sub Game jika belum ada pemenang
    // Reset gamestate kecuali player dan turn
    gameState.setRound(0);
    
    // Reset deck
    gameState.getDeckCards().defaultConfig();

    // Setiap player ambil 7 kartu dari deck
    for (long unsigned int i = 0; i < gameState.getPlayerList().size(); i++) {
        Player& player = gameState.getPlayerRefAt(i);
        player.setHand(gameState.getDeckCards().drawMany(CangkulGameManager::initialDraw));
    }

    // Main sampai sisa 1 orang terakhir
    while(!(gameState.getPlayerList().size() == 1)) {
        // Round selanjutnya
        gameState.getTableCards().clear();
        gameState.setRound(gameState.getRound() + 1);


        cout << "ROUND " << gameState.getRound() << endl;
        IO::newl();
        
        if (gameState.getRound() == 1) {
            gameState.setStartingPlayer(gameState.getCurrentTurnPlayer());
            gameState.getTableCards().addItem(gameState.getDeckCards().drawCard());
            cout << "Satu kartu diletakkan ke meja : " << gameState.getTableCards().getCards().back() << endl;
        }

        startRound();
    }

    gameState.moveToWinningList();

    IO::newl();
    cout << "Game Selesai." << endl;
    cout << "Berikut pemenang game ini: " << endl;
    
    for (long unsigned int i = 0; i < gameState.getWinningList().size(); i++) {
        cout << i + 1 << ". " << gameState.getWinningList()[i].getName() << endl;
    }

    IO::newl();
    IO::border();
    IO::newl();
}

// ========== Methods ==========

void CangkulGameManager::startGame() {
    // Mulai game keseluruhan sampai ditemukan pemenang

    IO::border();
    cout << "INISIASI PERMAINAN CANGKUL" << endl;
    IO::newl();

    // Inisiasi gameState
    initializePlayerCount();

    IO::newl();

    gameState = CangkulGameState(getInitialPlayerList(playerCount), 0, TableCard(), GameDeckCard());
    
    bool stop = false;

    do {
        IO::newl();
        cout << "PERMAINAN BARU DIMULAI!" << endl;
        IO::newl();

        if (gameState.getWinningList().size() > 0) {
            cout << "Urutan pemain diambil dari hasil permainan sebelumnya!" << endl;
            IO::newl();
            gameState.moveWinningList();
        }

        startSubGame();

        cout << "Lanjut" << endl;
        cout << "1. Main lagi" << endl;
        cout << "2. Exit" << endl;

        IO choiceIO;
        choiceIO.getInput(1, 2);

        if (choiceIO.getChoice() == 2) stop = true;
    } while(!stop);
    
    IO::newl();
    cout << "Game Diakhiri." << endl;
    IO::border();
    IO::newl();
}

// int main() {
//     CangkulGameManager cgm;
//     cgm.startGame();
// }
