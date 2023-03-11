#include "../../header/GameEnvironment/Player.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Default ctor
Player::Player(): Player(-1, vector<Card>(), 0, "Username", false) {

}

// Specified ctor
Player::Player(int id, vector<Card> hand, long long point, string name, bool hasPlayed) {
    this->playerID = playerID;
    this->hand = hand;
    this->point = point;
    this->name = name;
    this->hasPlayed = hasPlayed;
}

// cctor
Player::Player(const Player& other) {
    playerID = other.playerID;
    point = other.point;
    name = other.name;
    hand = other.hand;
    hasPlayed = other.hasPlayed;
}

// operator
Player& Player::operator=(const Player& other) {
    if (this != &other) {

        playerID = other.playerID;
        point = other.point;
        name = other.name;
        hand = other.hand;
        hasPlayed = other.hasPlayed;
    }

    return *this;
}

// Return player id
int Player::getId() const {
    return playerID;
}

// Return player hand
vector<Card> Player::getHand() const {
    return hand;
}

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

void Player::addPoint(long long addition) {
    point += addition;
}

// Returns the number of items in the inventory
int Player::countItems() const {
    return hand.size();
}

// Returns player name
string Player::getName() const {
    return name;
}

// Adds an item to the inventory
void Player::addItem(Card card) {
    hand.push_back(card);
}

// Removes an item from the inventory
void Player::clear() {
    hand.clear();
}

bool Player::hasPlayedThisRound() {
    return hasPlayed;
}


void Player::printHand() {
    if (hand.size() == 2) {
        cout << this->getHand()[0].getRank() << " " << this->getHand()[0].getColorString() << endl;
        cout << this->getHand()[1].getRank() << " " << this->getHand()[1].getColorString() << endl;
    }
}

// ...