#include "../../header/GameEnvironment/CandyPlayer.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Default ctor
CandyPlayer::CandyPlayer() {
    usedAbility = false;
    nerfed = false;
}

// Specified ctor
CandyPlayer::CandyPlayer(int id, vector<Card> hand, int point, string name, bool hasPlayed): Player(id, hand, point, name, hasPlayed) {
    usedAbility = false;
    nerfed = false;
}

// cctor
CandyPlayer::CandyPlayer(const CandyPlayer& other): Player(other) {

    usedAbility = other.usedAbility;
    nerfed = other.nerfed;
}

// operator
CandyPlayer& CandyPlayer::operator=(const CandyPlayer& other) {

    if (this != &other) {

        Player::operator=(other);
        usedAbility = other.usedAbility;
        nerfed = other.nerfed;
    }

    return *this;
}


// Set abilityless
bool CandyPlayer::setNerfed(bool nerf) {
    this->nerfed = nerf;
}

// Predicates
bool CandyPlayer::hasUsedAbility() {
    return usedAbility;
}


// ...