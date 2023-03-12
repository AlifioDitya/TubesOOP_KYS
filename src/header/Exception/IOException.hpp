#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <exception>

using std::exception;

class InvalidCommandString: public exception {

	const char* what() const throw() {
		return "String input bukan command yang valid!";
	}
};

class InvalidAbilityString: public exception {

	const char* what() const throw() {
		return "String input bukan ability yang valid!";
	}
};

class UnmatchedType : public exception {
public:
	const char* what() const throw() {

		return "Tipe masukan tidak valid!";
	}
};

class InvalidChoice : public exception {
public:
	const char* what() const throw() {
		return "Nilai pilihan tidak valid!";
	}
};

class EmptyChoice: public exception {
public:
	const char* what() const throw() {
		return "Tidak ada pilihan!";
	}
};

class FileNotFoundException: public exception {
public:
	const char* what() const throw() {
		return "File tidak ditemukan!";
	}
};

class InvalidFileInputFormatException: public exception {
public:
	const char* what() const throw() {
		return "Terdapat kesalahan format penulisan di dalam file";
	}
};

#endif