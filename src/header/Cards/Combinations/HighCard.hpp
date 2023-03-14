#include "../Combination.hpp"

class HighCard : public Combination {
   public:
    HighCard(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
