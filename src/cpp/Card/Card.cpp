#include "../../header/Cards/Card.hpp"
#include <map>

using std::map;

Card::Card(Color color, Rank rank) : CardInterface(0), color(color), rank(rank) { // NILAI CTOR CARDINTERFACE MASIH ASAL

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
        {Rank::One, "As"},
        {Rank::Two, "Two"},
        {Rank::Three, "Three"},
        {Rank::Four, "Four"},
        {Rank::Five, "Five"},
        {Rank::Six, "Six"},
        {Rank::Seven, "Seven"},
        {Rank::Eight, "Eight"},
        {Rank::Nine, "Nine"},
        {Rank::Ten, "Ten"},
        {Rank::Eleven, "Jack"},
        {Rank::Twelve, "Queen"},
        {Rank::Thirteen, "King"},
    };

    return rankMap[rank];
}


double Card::getWeightedValue() const {
    return (double)rank / 10 + color * 0.3;
}

bool Card::operator=(const Card& other) {
    return CardInterface::operator==(other);
}

