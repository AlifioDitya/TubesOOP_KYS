/**
 * @file CardInterface.hpp
 * @brief Header file for the CardInterface class
 *
 */
#ifndef CARDINTERFACE_HPP
#define CARDINTERFACE_HPP

/**
 * @class CardInterface
 * @brief Interface class for card objects
 *
 */
class CardInterface {
   public:
    /**
     * @brief Construct a new Card Interface object
     *
     */
    CardInterface();

    /**
     * @brief Destroy the Card Interface object
     *
     */
    virtual ~CardInterface();

    // ========== Operators ==========

    /**
     * @brief Equality operator for comparing two cards.
     *
     * @param other The card to compare against.
     * @return true if the cards are equal, false otherwise.
     */
    bool operator==(const CardInterface&);
    bool operator!=(const CardInterface&);

    /**
     * @brief Greater-than operator for comparing two cards.
     *
     * @param other The card to compare against.
     * @return true if this card is greater than the other card, false otherwise.
     */
    bool operator>(const CardInterface&);

    /**
     * @brief Less-than operator for comparing two cards.
     *
     * @param other The card to compare against.
     * @return true if this card is less than the other card, false otherwise.
     */
    bool operator<(const CardInterface&);

    /**
     * @brief Greater-than-or-equal-to operator for comparing two cards.
     *
     * @param other The card to compare against.
     * @return true if this card is greater than or equal to the other card, false otherwise.
     */
    bool operator>=(const CardInterface&);

    /**
     * @brief Less-than-or-equal-to operator for comparing two cards.
     *
     * @param other The card to compare against.
     * @return true if this card is less than or equal to the other card, false otherwise.
     */
    bool operator<=(const CardInterface&);

    // ========== Getters ==========

    /**
     * @brief Get the value of cards
     *
     * @return Card value
     */
    long double virtual getValue() const = 0;
};

#endif