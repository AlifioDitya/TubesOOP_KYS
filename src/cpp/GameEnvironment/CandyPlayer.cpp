#include "../../header/GameEnvironment/CandyPlayer.hpp"
#include "../../header/GameEnvironment/Player.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Default ctor
CandyPlayer::CandyPlayer() {
    ability = AbilityTypes::None;
    point = 0;
    usedAbility = false;
    nerfed = false;
}

// Specified ctor
CandyPlayer::CandyPlayer(int id, const vector<Card>& hand, uint64_t point, string name, bool hasPlayed): Player(id, hand, name, hasPlayed) {

    this->ability = AbilityTypes::None;
    this->point = point;
    this->usedAbility = false;
    this->nerfed = false;
}

// cctor
CandyPlayer::CandyPlayer(const CandyPlayer& other): Player(other) {
    ability = other.ability;
    point = other.point;
    usedAbility = other.usedAbility;
    nerfed = other.nerfed;
}

// ========== Operators ==========

CandyPlayer& CandyPlayer::operator=(const CandyPlayer& other) {

    if (this != &other) {

        Player::operator=(other);
        ability = other.ability;
        point = other.point;
        usedAbility = other.usedAbility;
        nerfed = other.nerfed;
    }

    return *this;
}

bool CandyPlayer::operator<(const CandyPlayer& other) {
    return point < other.point;
}

bool CandyPlayer::operator>(const CandyPlayer& other) {
    return point > other.point;
}

// ========== Setters ==========

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

// ========== Predicates/Getters ==========

AbilityTypes CandyPlayer::getAbility() {
    return ability;
}

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

// Returns player point
uint64_t CandyPlayer::getPoint() const {
    return point;
}

uint64_t CandyPlayer::getValue() const {
    return getPoint();
}

// ========= Other Methods ==========


void CandyPlayer::addPoint(uint64_t addition) {
    point += addition;
}

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


// ...