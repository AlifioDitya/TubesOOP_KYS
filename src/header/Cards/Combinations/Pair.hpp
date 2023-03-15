#include <utility>

#include "../Combination.hpp"

class Pair : public Combination {
   private:
    Pair(const vector<Card>& combinationCards);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getPair(const vector<Card>& tableCards, const vector<Card>& handCards);
};
