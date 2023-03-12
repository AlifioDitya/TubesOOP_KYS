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
CandyPlayer::CandyPlayer(int id, const vector<Card>& hand, int point, string name, bool hasPlayed): Player(id, hand, point, name, hasPlayed) {
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

AbilityTypes CandyPlayer::getAbility() {
    return ability;
}

// Set ability used
void CandyPlayer::setAbilityUsed(bool usedAbility) {
    this->usedAbility = usedAbility;

}

// Set abilityless
void CandyPlayer::setNerfed(bool nerf) {
    this->nerfed = nerf;
}

// Set ability
void CandyPlayer::setAbility(AbilityTypes ability) {
    this->ability = ability;
}

// ========== Predicates ==========
// Check if player has ability
bool CandyPlayer::hasAbility(AbilityTypes target) const {
    return ability == target;
}

// Check if player has used an ability
bool CandyPlayer::hasUsedAbility() const {
    return usedAbility;
}

// Check if the player has been applied Abilityless by other player
bool CandyPlayer::isNerfed() const {
    return nerfed;
}

// ========= Others ==========
// Switching cards with other player

void CandyPlayer::switchCards(CandyPlayer& other) {
    vector<Card> temp = this->getHand();
    this->setHand(other.getHand());
    other.setHand(temp);
}

void CandyPlayer::switchCards(int idx1, int idx2, CandyPlayer& other) {
    Card temp = this->getHand()[idx1];
    this->setHand(idx1, other.getHand()[idx2]);
    other.setHand(idx2, temp);
}


double CandyPlayer::getValue() const {
    return getPoint();
}

// ...