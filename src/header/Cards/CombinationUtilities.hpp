#include "Combination.hpp"

using std::pair;
using std::vector;

namespace CombinationUtilities {
Combination* findComboType(const vector<Card>&);
bool ofSameColor(const vector<Card>&);
bool inSequence(const vector<Card>&);
bool hasFourOfAKind(const vector<Card>&);
bool isFullHouse(const vector<Card>&);
bool hasThreeOfAKind(const vector<Card>&);
pair<int, int> findPairIdx(const vector<Card>&);
}  // namespace CombinationUtilities
