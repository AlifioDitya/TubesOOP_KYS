#ifndef DECKCARDEXCEPTION_H
#define DECKCARDEXCEPTION_H

#include <exception>

using namespace std;


class InsufficientCards : public exception {
	const char* what() const throw() {

		return "Kartu pada deck tidak cukup!";
	}
};

#endif