#ifndef CANGKULEXCEPTION_HPP
#define CANGKULEXCEPTION_HPP

#include <exception>

using std::exception;

class NotEnoughPlayerException : public exception {
public:
    const char* what() const throw() {
        return "Jumlah pemain terlalu sedikit!";
    }
};

class TooManyPlayerException : public exception {
public:
    const char* what() const throw() {
        return "Jumlah pemain terlalu banyak!";
    }
};

#endif