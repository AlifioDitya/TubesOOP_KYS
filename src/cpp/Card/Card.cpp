#include "../../header/Cards/Card.hpp"

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

Card::Card(Color color, Rank rank)
    : CardInterface((double)rank / 10 + color * 0.03), color(color), rank(rank) {
}

Color Card::getColor() const {
    return color;
}

Rank Card::getRank() const {
    return rank;
}

string Card::getColorString() const {
    map<Color, string> colorMap = {
        {Color::Blue, "Blue"},
        {Color::Green, "Green"},
        {Color::Red, "Red"},
        {Color::Yellow, "Yellow"},
    };

    return colorMap[color];
}

string Card::getRankString() const {
    map<Rank, string> rankMap = {
        {Rank::One, "As"},        {Rank::Two, "Two"},     {Rank::Three, "Three"},
        {Rank::Four, "Four"},     {Rank::Five, "Five"},   {Rank::Six, "Six"},
        {Rank::Seven, "Seven"},   {Rank::Eight, "Eight"}, {Rank::Nine, "Nine"},
        {Rank::Ten, "Ten"},       {Rank::Eleven, "Jack"}, {Rank::Twelve, "Queen"},
        {Rank::Thirteen, "King"},
    };

    return rankMap[rank];
}

double Card::getValue() const {
    return value;
}

ostream& operator<<(ostream& o, const Card& card) {
    o << card.getRank() << " " << card.getColorString();
    return o;
}
