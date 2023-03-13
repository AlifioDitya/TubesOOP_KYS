#ifndef DECKCARDEXCEPTION_H
#define DECKCARDEXCEPTION_H

#include <exception>

using std::exception;

// exception when cards in deck is unsifficient to be drawed
class InsufficientCards : public exception {
public:
	const char* what() const throw() {
		return "Kartu pada deck tidak cukup!";
	}
};

#endif