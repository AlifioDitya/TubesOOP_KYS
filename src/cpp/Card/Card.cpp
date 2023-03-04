#include "../../header/Cards/Card.hpp"

Card::Card(Color color, Rank rank) : color(color), rank(rank) {
}

Color Card::getColor() const {
    return color;
}

Rank Card::getRank() const {
    return rank;
}

double Card::getWeightedValue() const {
    return (double)rank / 10 + color * 0.3;
}