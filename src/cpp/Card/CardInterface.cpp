#include "../../header/Cards/CardInterface.hpp"

#include <iostream>

using std::cout;
using std::endl;

CardInterface::~CardInterface() {
}

bool operator==(const CardInterface& lhs, const CardInterface& rhs) {
    return lhs.getValue() == rhs.getValue();
}

bool operator!=(const CardInterface& lhs, const CardInterface& rhs) {
    return !(lhs == rhs);
}

bool operator>(const CardInterface& lhs, const CardInterface& rhs) {
    return lhs.getValue() > rhs.getValue();
}

bool operator<(const CardInterface& lhs, const CardInterface& rhs) {
    return rhs > lhs;
}

bool operator>=(const CardInterface& lhs, const CardInterface& rhs) {
    return !(lhs < rhs);
}

bool operator<=(const CardInterface& lhs, const CardInterface& rhs) {
    return !(lhs > rhs);
}