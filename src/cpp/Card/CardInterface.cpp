#include "../../header/Cards/CardInterface.hpp"

#include <iostream>

using std::cout;
using std::endl;

CardInterface::~CardInterface() {
}

bool CardInterface::operator==(const CardInterface& other) {
    return this->getValue() == other.getValue();
}

bool CardInterface::operator!=(const CardInterface& other) {
    return this->getValue() != other.getValue();
}

bool CardInterface::operator>(const CardInterface& other) {
    return this->getValue() > other.getValue();
}

bool CardInterface::operator<(const CardInterface& other) {
    return this->getValue() < other.getValue();
}

bool CardInterface::operator>=(const CardInterface& other) {
    return this->getValue() >= other.getValue();
}

bool CardInterface::operator<=(const CardInterface& other) {
    return this->getValue() <= other.getValue();
}