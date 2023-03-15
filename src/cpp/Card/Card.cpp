#include "../../header/Cards/Card.hpp"

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

Card::Card(Color color, Rank rank) : CardInterface(), color(color), rank(rank) {
}

Color Card::getColor() const {
    return color;
}

Rank Card::getRank() const {
    return rank;
}

string Card::getColorString() const {
    map<Color, string> colorMap = {
        {Color::Blue, "Biru"},
        {Color::Green, "Hijau"},
        {Color::Red, "Merah"},
        {Color::Yellow, "Kuning"},
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

long double Card::getValue() const {
    return (long double)rank / 10 + color * 0.03;
}

ostream& operator<<(ostream& o, const Card& card) {
    map<Color, int> terminalColorMapping = {
        {Red, 31},
        {Green, 32},
        {Yellow, 33},
        {Blue, 34}
    };

    o << "\033[;" << terminalColorMapping[card.getColor()] << "m" << card.getRank() << " (" << card.getColorString() << ")" << "\033[0m";

    return o;
}