#include "../../header/GameEnvironment/Player.hpp"
#include "../../header/GameEnvironment/InventoryHolder.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Default ctor
Player::Player(): Player(-1, vector<Card>(), "Username", false) {}

// Specified ctor
Player::Player(int id, const vector<Card>& hand, string name, bool hasPlayed) {
    this->playerID = id;
    this->hand = hand;
    this->name = name;
    this->hasPlayed = hasPlayed;
}

// dtor
Player::~Player() {
}

// cctor
Player::Player(const Player& other) {
    playerID = other.playerID;
    name = other.name;
    hand = other.hand;
    hasPlayed = other.hasPlayed;
}

// ========== Operator ==========

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        playerID = other.playerID;
        name = other.name;
        hand = other.hand;
        hasPlayed = other.hasPlayed;
    }

    return *this;
}

// ========== Getters ==========

// Return player id
int Player::getId() const {
    return playerID;
}

// Returns player name
string Player::getName() const {
    return name;
}

// Return player hand
vector<Card> Player::getHand() const {
    return hand;
}

// Returns the number of items in the inventory
int Player::countItems() const {
    return hand.size();
}

// ========== Setters/Other Methods ==========

// Set player hand on index
void Player::setHand(int idx, Card newCard) {
    this->hand[idx] = newCard;
} 

void Player::setHand(vector<Card> newHand) {
    this->hand = newHand;
}

void Player::setHasPlayed(bool hasPlayed) {
    this->hasPlayed = hasPlayed;
}

// Adds an item to the inventory
void Player::addItem(const Card& card) {
    hand.push_back(card);
}

// Removes an item from the inventory
void Player::clear() {
    hand.clear();
}

Card Player::PutCard(int idx) {
    Card temp = hand[idx];

    hand.erase(hand.begin() + idx);
    
    return temp;
}

void Player::printHand() {
    if (hand.size() == 2) {
        cout << "[" << getHand()[0] << ", " << getHand()[1] << "]" << endl;
    }
}
// ========== Predicates ==========

bool Player::hasPlayedThisRound() const {
    return hasPlayed;
}
// ...