#include "../Combination.hpp"

/**
 * @class ThreeOfAKind
 * @brief Class that defines the Three of a Kind combination
 * @extends Combination
 *
 */
class ThreeOfAKind : public Combination {
   private:
    /**
     * @brief Construct a new ThreeOfAKind object
     */
    ThreeOfAKind(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Three of a Kind combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Three of a Kind from given cards, combination will contain at
     * least one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type ThreeOfAKind
     */
    static Combination* getThreeOfAKind(const vector<Card>& tableCards,
                                        const vector<Card>& handCards);
};
