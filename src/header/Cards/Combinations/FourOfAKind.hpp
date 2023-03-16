#include "../Combination.hpp"

/**
 * @class FourOfAKind
 * @brief Class that defines the Four of a Kind combination
 * @extends Combination
 *
 */
class FourOfAKind : public Combination {
   private:
    /**
     * @brief Construct a new FourOfAKind object
     */
    FourOfAKind(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Four of a Kind combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Four of a Kind from given cards, combination will contain at
     * least one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type FourOfAKind
     */
    static Combination* getFourOfAKind(const vector<Card>& tableCards,
                                       const vector<Card>& handCards);
};
