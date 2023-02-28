#include "../header/GameEnvironment/GameState.hpp"

// Default ctor
GameState::GameState() {
    // Initialize default values
    PlayerList = vector<Player>();
    currentTurnIdx = 0;
    round = 1;
    points = 0;
    tableCards = TableCard();
    deckCards = DeckCard();
}

// Specified ctor
GameState::GameState(vector<Player> playerList, int currentTurn, int roundNum, int pointVal, TableCard tblCard, DeckCard dckCard) {
    PlayerList = playerList;
    currentTurnIdx = currentTurn;
    round = roundNum;
    points = pointVal;
    tableCards = tblCard;
    deckCards = dckCard;
}

// Copy ctor
GameState::GameState(const GameState& gs) {
    PlayerList = gs.PlayerList;
    currentTurnIdx = gs.currentTurnIdx;
    round = gs.round;
    points = gs.points;
    tableCards = gs.tableCards;
    deckCards = gs.deckCards;
}

// Destructor
GameState::~GameState() {
    // No dynamic allocation
}

// Setters
void GameState::setPlayerList(vector<Player> playerList) {
    PlayerList = playerList;
}

void GameState::setCurrentTurn(int currentTurn) {
    currentTurnIdx = currentTurn;
}

void GameState::setRound(int roundNum) {
    round = roundNum;
}

void GameState::setPoints(int pointVal) {
    points = pointVal;
}

void GameState::setTableCards(TableCard tblCard) {
    tableCards = tblCard;
}

void GameState::setDeckCards(DeckCard dckCard) {
    deckCards = dckCard;
}
