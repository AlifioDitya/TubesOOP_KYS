#include "../Combination.hpp"

/**
 * @class Straight
 * @brief Class that defines the Straight combination
 * @extends Combination
 *
 */
class Straight : public Combination {
   private:
    /**
     * @brief Construct a new Straight object
     */
    Straight(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Straight combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Straight from given cards, combination will contain at least
     * one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type Straight
     */
    static Combination* getStraight(const vector<Card>& tableCards, const vector<Card>& handCards);
};
