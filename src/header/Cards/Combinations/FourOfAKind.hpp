#include "../Combination.hpp"

class FourOfAKind : public Combination {
   private:
    vector<Card> quad;
    Card kicker;

   public:
    FourOfAKind(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
