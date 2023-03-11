#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>

using std::exception;

class InsufficientCards : public exception {
public:
	const char* what() const throw() {
		return "Kartu pada deck tidak cukup!";
	}
};

#endif