#include "../Combination.hpp"

class Straight : public Combination {
   public:
    Straight(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
