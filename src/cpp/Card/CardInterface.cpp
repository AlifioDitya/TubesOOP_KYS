#include "../../header/Cards/CardInterface.hpp"

CardInterface::CardInterface(int weightedValue) : weightedValue(weightedValue) {
}

CardInterface::~CardInterface() {
}

bool CardInterface::operator==(const CardInterface& other) {
    return this->weightedValue == other.weightedValue;
}

bool CardInterface::operator==(const CardInterface& other) {
    return this->weightedValue == other.weightedValue;
}

bool CardInterface::operator>(const CardInterface& other) {
    return this->weightedValue > other.weightedValue;
}

bool CardInterface::operator<(const CardInterface& other) {
    return this->weightedValue < other.weightedValue;
}

bool CardInterface::operator>=(const CardInterface& other) {
    return this->weightedValue >= other.weightedValue;
}

bool CardInterface::operator<=(const CardInterface& other) {
    return this->weightedValue <= other.weightedValue;
}