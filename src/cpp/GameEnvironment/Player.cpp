#include "../../header/GameEnvironment/Player.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

// Default ctor
Player::Player(): playerID(-1), hand(vector<Card>()), point(0), name("Username"), hasPlayed(false) {

}

// Specified ctor
Player::Player(int id, vector<Card> hand, int point, string name, bool hasPlayed): playerID(id), hand(hand), point(point), name(name), hasPlayed(hasPlayed) {

}

// cctor
Player::Player(const Player& other): playerID(other.playerID), point(other.point), name(other.name), hasPlayed(other.hasPlayed) {
    copy(other.hand.begin(), other.hand.end(), back_inserter(hand)); 
}

// operator
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        // copy player ID
        this->playerID = other.playerID;

        // copy hand
        this->hand.clear();
        for (const Card& card : other.hand) {
            this->hand.push_back(card);
        }

        // copy point
        this->point = other.point;
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

// ...