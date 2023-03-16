/**
 * @file DeckCardException.hpp
 * @brief Header file containing the declarations of custom  deck card exception classes used in the game.
 * This file contains the declaration of custom exception classes that can be thrown during the execution of the game.
 * These exceptions provide additional information and error messages to the user in case an exceptional situation occurs.
 * 
 */
#ifndef DECKCARDEXCEPTION_H
#define DECKCARDEXCEPTION_H

#include <exception>

using std::exception;

/**
 * @exception Thrown when there are insufficient cards to be drawn.
 * 
 */
class InsufficientCards : public exception {
public:
    const char *what() const throw() {
        return "Kartu pada deck tidak cukup!";
    }
};

/**
 * @exception Thrown when there are duplicate cards in the input file.
 * 
 */
class DuplicateCard: public exception {
public:
    const char *what() const throw() {
        return "Ada kartu duplikat dalam deck!";
    }
};

#endif