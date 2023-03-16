// CandyGameState.cpp
#include "../../header/GameEnvironment/CandyGameState.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::find_if;

const uint64_t CandyGameState::initialPoint = 64;
const uint64_t CandyGameState::winnerPoint = 4294967296;

CandyGameState::CandyGameState() {

    reversePlayerId = 0;
    pointPool = initialPoint;
}

CandyGameState::CandyGameState(const vector <CandyPlayer>& playerList, int roundNum, uint64_t points,
                               const TableCard& tableCard, const GameDeckCard& deckCard,
                               const AbilityDeckCard& abilities, int reversePlayerId) :

        GameState<CandyPlayer>(playerList, roundNum, tableCard, deckCard) {
    // ABILITIES INITIATION
    this->abilities = abilities;
    this->reversePlayerId = reversePlayerId;
    this->pointPool = points;
}

CandyGameState::CandyGameState(const CandyGameState& gs) : GameState<CandyPlayer>(gs) {
    // ABILITIES COPY
    abilities = gs.abilities;
    reversePlayerId = gs.reversePlayerId;
    pointPool = gs.pointPool;
}

CandyGameState::~CandyGameState() {
    // No dynamic allocation
}

// ========== Getters ==========

AbilityDeckCard& CandyGameState::getAbilities() {
    return abilities;
}

int CandyGameState::getReversePlayerId() const {
    return reversePlayerId;
}

uint64_t CandyGameState::getPointPool() const {
    return pointPool;
}


// ========== Predicates ==========


bool CandyGameState::hasAllUsedAbility() const {

    for (auto i = playerList.begin() + 1; i != playerList.end(); i++) {
        if (!i->hasUsedAbility()) return false;
    }

    return true;
}

// ========== Setters ==========

void CandyGameState::setAbilities(const AbilityDeckCard& abilities) {
    this->abilities = abilities;
}

void CandyGameState::setNextTurn() {

    GameState::setNextTurn();

    if (hasAllPlayed()) {
        if (playerList.back().getId() != reversePlayerId) skipCurrentPlayer();

        // inisiasi round baru
        reversePlayerId = 0;
    }

}

void CandyGameState::setReversePlayerId(int reversePlayerId) {
    this->reversePlayerId = reversePlayerId;
}

void CandyGameState::setPointPool(uint64_t points) {
    pointPool = points;
};

void CandyGameState::setAllNoAbility() {
    for (long unsigned int i = 0; i < playerList.size(); i++) {
        playerList[i].setAbility(AbilityTypes::None);
        playerList[i].setAbilityUsed(false);
        playerList[i].setNerfed(false);
    }
}

// ========== Other Methods ==========

void CandyGameState::printLeaderBoard() const {
    vector <CandyPlayer> list = getPlayerList();

    sort(list.begin(), list.end());

    cout << "Leaderboard :" << endl;
    for (int i = list.size() - 1; i >= 0; i--) {
        cout << "\t" << list.size() - i << ". " << list[i].getName() << ": " << list[i].getPoint() << endl;
    }

}

void CandyGameState::printNextRoundTurn() const {
    auto i = playerList.begin() + 1;
    long unsigned int counter = 0;

    while (counter < playerList.size()) {
        cout << "<" << i->getName() << "> ";

        int idx = i - playerList.begin();
        i = playerList.begin() + ((idx + 1) % playerList.size());
        counter++;
    }

    cout << endl;
}