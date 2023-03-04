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
Player::Player(int id, vector<Card> hand, int point, string name, bool hasPlayed) {
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


// Switch cards
void Player::switchCards(Player& other) {
    vector<Card> temp = this->getHand();
    this->setHand(other.getHand());
    other.setHand(temp);
}

void Player::switchCards(int idx1, int idx2, Player& other) {
    Card temp = this->getHand()[idx1];
    this->setHand(idx1, other.getHand()[idx2]);
    other.setHand(idx2, temp);
}

void Player::printHand() {
    if (hand.size() == 2) {
        cout << this->getHand()[0].getRank() << " " << this->getHand()[0].getColorString() << endl;
        cout << this->getHand()[1].getRank() << " " << this->getHand()[1].getColorString() << endl;
    }
}

// ...