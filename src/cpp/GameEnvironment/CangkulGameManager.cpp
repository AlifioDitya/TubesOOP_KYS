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

void border() {
    cout << "==============================" << endl;
}

void newl() {
    cout << endl;
}

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

    newl();
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
            newl();

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
    while (gameState.getCurrentTurnPlayer().getId() != gameState.getStartingPlayerId()) {
        gameState.skipCurrentPlayer();
    }

    while (!gameState.hasAllPlayed()) {
        // aksi pemain
        Player& currentPlayer = gameState.getCurrentTurnPlayer();
        newl();
        border();

        cout << "Giliran pemain " << currentPlayer.getId() << " : " << currentPlayer.getName() << endl << endl;

        if (gameState.getTableCards().countItems() > 0) {
            cout << "Berikut kartu pada table : " << endl;
            gameState.getTableCards().showCards();
            cout<< endl;
        } else {
            cout << "Kamu menentukan warna kartu pada round ini!" << endl;
            newl();
        }

        cout << "Berikut kartu yang kamu miliki : " << endl;
        currentPlayer.printHand();
        newl();

        cout << "Pilihan perintah: " << endl;
        cout << "1. PUT" << endl;
        cout << "2. CANGKUL" << endl;
        cout << "3. SKIP" << endl;

        newl();

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
    
    newl();
    cout << "Satu putaran selesai!" << endl;
    newl();
    border();
    newl();
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
        newl();
        
        if (gameState.getRound() == 1) {
            gameState.setStartingPlayer(gameState.getCurrentTurnPlayer());
            gameState.getTableCards().addItem(gameState.getDeckCards().drawCard());
            cout << "Satu kartu diletakkan ke meja : " << gameState.getTableCards().getCards().back() << endl;
        }

        startRound();
    }

    gameState.moveToWinningList();

    newl();
    cout << "Game Selesai." << endl;
    cout << "Berikut pemenang game ini: " << endl;
    
    for (int i = 0; i < gameState.getWinningList().size(); i++) {
        cout << i + 1 << ". " << gameState.getWinningList()[i].getName() << endl;
    }

    newl();
    border();
    newl();
}

// ========== Methods ==========

void CangkulGameManager::startGame() {
    // Mulai game keseluruhan sampai ditemukan pemenang

    // Inisiasi gameState
    initializePlayerCount();
    gameState = CangkulGameState(getInitialPlayerList(playerCount), 0, TableCard(), GameDeckCard());
    
    bool stop = false;

    do {
        cout << "PERMAINAN BARU DIMULAI!" << endl;

        if (gameState.getWinningList().size() > 0) {
            cout << "Urutan pemain diambil dari hasil permainan sebelumnya!" << endl;
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
    gameState.moveToWinningList();

    newl();
    cout << "Game Diakhiri." << endl;
    newl();
    border();
    newl();
}

int main() {
    CangkulGameManager cgm;
    cgm.startGame();
}
