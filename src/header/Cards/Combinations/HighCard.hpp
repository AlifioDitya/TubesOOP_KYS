#include "../Combination.hpp"

class HighCard : public Combination {
   private:
    HighCard(const vector<Card>& combinationCards);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getHighCard(const vector<Card>& tableCards, const vector<Card>& handCards);
};
