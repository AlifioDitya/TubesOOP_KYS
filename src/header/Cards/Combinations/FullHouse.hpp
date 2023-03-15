#include "../Combination.hpp"

class FullHouse : public Combination {
   private:
    FullHouse(const vector<Card>& combinationCards);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getFullHouse(const vector<Card>& tableCards, const vector<Card>& handCards);
};
