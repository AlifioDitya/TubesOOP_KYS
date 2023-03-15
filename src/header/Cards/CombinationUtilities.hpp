#include "Combination.hpp"

using std::pair;
using std::vector;

namespace CombinationUtilities {
// TODO: UPDATE
enum ComboMaxTimesTen {
    HighCard = 14,
    Pair = 28,
    TwoPair = 42,
    ThreeOfAKind = 56,
    Straight = 70,
    Flush = 87,
    FullHouse = 101,
    FourOfAKind = 115,
    StraightFlush = 129
};
bool ofSameColor(vector<Card>&);
bool ofSameRank(vector<Card>&);
bool inSequence(vector<Card>&);
bool hasFourOfAKind(vector<Card>&);
bool isFullHouse(vector<Card>&);
bool hasThreeOfAKind(vector<Card>&);
bool isTwoPair(vector<Card>&);
pair<int, int> findPairIdx(vector<Card>&);
}  // namespace CombinationUtilities
