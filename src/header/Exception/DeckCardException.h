#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>

using namespace std;


class InsufficientCards : public exception {
	const char* what() const throw() {

		return "Kartu pada deck tidak cukup!";
	}
};

#endif