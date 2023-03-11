#include "../../header/Cards/Combination.hpp"

// TODO: Chagne to generic then create utils.cpp and move toVector there
template <class T>
vector<T> toVector(const T* array, size_t size) {
    vector<T> v(array, array + size);
    return v;
}

Combination::Combination(const vector<Card> cards): CardInterface(0){ // NILAI CTOR CARDINTERFACE MASIH ASAL
    this->allCards = cards;
    this->bestCombination = findBestCombination(allCards);
    this->comboType = findComboType(bestCombination);
    this->weightedValue = calculateWeightedValue(bestCombination);
}

Combination::Combination(const Card cards[], int size) : Combination(toVector(cards, size)) {
}

Combination::~Combination() {
}

ComboTypes Combination::findComboType(vector<Card> cards) {
}

vector<Card> Combination::findBestCombination(vector<Card> cards) {
}

double Combination::calculateWeightedValue(vector<Card> cards) {
}

vector<Card> Combination::getAllCards() const {
    return allCards;
}
vector<Card> Combination::getBestCombination() const {
    return bestCombination;
}
ComboTypes Combination::getComboType() const {
    return comboType;
}

double Combination::getWeightedValue() const {
    return weightedValue;
}