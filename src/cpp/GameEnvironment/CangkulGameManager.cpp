// CangkulGameManager.cpp
#include "../../header/GameEnvironment/CangkulGameManager.hpp"
#include "../../header/Exception/CangkulException.hpp"

#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::pair;

CangkulGameManager::CangkulGameManager() {

}

CangkulGameManager::~CangkulGameManager() {

}

void CangkulGameManager::startGame() {
    gameState = GameState<Player>(vector<Player>(), 0, TableCard(), GameDeckCard());
    startingPlayerId = 1;

    initializePlayerCount();

    cout << endl;
    initializePlayerList();

    while (winner.size() < playerCount - 1) {
        startRound();
    }

    for (int i = 0; i <= playerCount; i++) {
        if (!hasWon[i]) {
            winner.push_back(gameState.getPlayerList()[i]);
            break;
        }
    }

    cout << "Berikut pemenang dari permainan ini:" << endl;
    for (int i = 1; i <= playerCount; i++) {
        cout << i << ". " << winner[i - 1].getName() << endl;
    }
}

void CangkulGameManager::startRound() {    
    int currentPlayerId = startingPlayerId;    

    do {
        if (hasWon[currentPlayerId - 1]) {
            currentPlayerId = (currentPlayerId % playerCount) + 1;
            continue;
        }

        cout << "Berikut kartu yang kamu miliki: " << endl;
        for (int i = 1; i <= gameState.getPlayerList()[currentPlayerId - 1].getHand().size(); i++) {
            cout << i << ". " << gameState.getPlayerList()[currentPlayerId - 1].getHand()[i - 1] << endl;
        }

        int pilihan;
        cout << "Masukkan nomor kartu yang dipilih: ";
        cin >> pilihan;

        currentPlayerId = (currentPlayerId % playerCount) + 1;
    } while (currentPlayerId != startingPlayerId);

    // startingPlayerId = roundWinner;
}

void CangkulGameManager::initializePlayerCount() {
    while (true) {
        try {
            cout << "Masukkan jumlah pemain: ";
            cin >> playerCount;

            if (playerCount < 2) throw NotEnoughPlayerException();
            else if (playerCount > 4) throw TooManyPlayerException();
            break;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}

void CangkulGameManager::initializePlayerList() {
    vector<Player> players;
    for (int i = 1; i <= playerCount; i++) {
        string playerName;
        cout << "Masukkan pemain ke-" << i <<": ";
        cin >> playerName;

        players.push_back(Player(i, vector<Card>(), playerName, false));
        hasWon.push_back(false);
    }
    gameState.setPlayerList(players);

    for (int i = 0; i < playerCount; i++) {
        Player& player = gameState.getPlayerRefAt(i);
        player.setHand(gameState.getDeckCards().drawMany(7));
    }
}

int main() {
    CangkulGameManager game;
    game.startGame();
}