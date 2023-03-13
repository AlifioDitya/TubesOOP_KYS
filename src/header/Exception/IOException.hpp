#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <exception>

using std::exception;

// exception when command string is invalid
class InvalidCommandString: public exception {

	const char* what() const throw() {
		return "String input bukan command yang valid!";
	}
};

// exception when ability string is invalid
class InvalidAbilityString: public exception {

	const char* what() const throw() {
		return "String input bukan ability yang valid!";
	}
};

// exception when input type is invalid
class UnmatchedType : public exception {
public:
	const char* what() const throw() {

		return "Tipe masukan tidak valid!";
	}
};

// exception when integer input is out of range
class InvalidChoice : public exception {
public:
	const char* what() const throw() {
		return "Nilai pilihan tidak valid!";
	}
};

// exception when input is empty
class EmptyChoice: public exception {
public:
	const char* what() const throw() {
		return "Tidak ada pilihan!";
	}
};

// exception when file is not found
class FileNotFoundException: public exception {
public:
	const char* what() const throw() {
		return "File tidak ditemukan!";
	}
};

// exception when file format is invalid
class InvalidFileInputFormatException: public exception {
public:
	const char* what() const throw() {
		return "Terdapat kesalahan format penulisan di dalam file";
	}
};

#endif