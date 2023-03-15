#include "../Combination.hpp"

class StraightFlush : public Combination {
   private:
    StraightFlush(const vector<Card>& combinationCards);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getStraightFlush(const vector<Card>& tableCards,
                                         const vector<Card>& handCards);
};
