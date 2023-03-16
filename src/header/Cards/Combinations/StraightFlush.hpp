#include "../Combination.hpp"

/**
 * @class StraightFlush
 * @brief Class that defines the Straight Flush combination
 * @extends Combination
 *
 */
class StraightFlush : public Combination {
   private:
    /**
     * @brief Construct a new StraightFlush object
     */
    StraightFlush(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Straight Flush combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Straight Flush from given cards, combination will contain at
     * least one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type StraightFlush
     */
    static Combination* getStraightFlush(const vector<Card>& tableCards,
                                         const vector<Card>& handCards);
};
