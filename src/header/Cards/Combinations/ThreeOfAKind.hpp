#include "../Combination.hpp"

class ThreeOfAKind : public Combination {
   private:
    vector<Card> triple;
    vector<Card> kickers;

   public:
    ThreeOfAKind(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
