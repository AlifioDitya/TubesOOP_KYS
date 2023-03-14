#include "../../header/Cards/CardInterface.hpp"

#include <iostream>

using std::cout;
using std::endl;

CardInterface::CardInterface(double value) : value(value) {
}

CardInterface::~CardInterface() {
}

bool CardInterface::operator==(const CardInterface& other) {
    return this->value == other.value;
}

bool CardInterface::operator>(const CardInterface& other) {
    return this->value > other.value;
}

bool CardInterface::operator<(const CardInterface& other) {
    // cout << this->getValue() << " " << other.getValue() << endl;
    return this->value < other.value;
}

bool CardInterface::operator>=(const CardInterface& other) {
    return this->value >= other.value;
}

bool CardInterface::operator<=(const CardInterface& other) {
    return this->value <= other.value;
}