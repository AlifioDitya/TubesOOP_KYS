#include "../Combination.hpp"

class ThreeOfAKind : public Combination {
   private:
    ThreeOfAKind(const vector<Card>& combinationCards);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getThreeOfAKind(const vector<Card>& tableCards,
                                        const vector<Card>& handCards);
};
