/**
 * @file IOException.hpp
 * @brief Header file containing the declarations of custom I/O exception classes used in the game.
 * This file contains the declaration of custom exception classes that can be thrown during the execution of the game.
 * These exceptions provide additional information and error messages to the user in case an exceptional situation occurs.
 * 
 */
#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <exception>

using std::exception;

/**
 * @exception Thrown when command string is invalid.
 * 
 */
class InvalidCommandString : public exception {
public:
    const char *what() const throw() {
        return "String input bukan command yang valid!";
    }
};

/**
 * @exception Thrown when ability string is invalid.
 * 
 */
class InvalidAbilityString : public exception {
public:
    const char *what() const throw() {
        return "String input bukan ability yang valid!";
    }
};

/**
 * @exception Thrown when input type is invalid.
 * 
 */
class UnmatchedType : public exception {
public:
    const char *what() const throw() {
        return "Tipe masukan tidak valid!";
    }
};

/**
 * @exception Thrown when the input is out of range.
 * 
 */
class InvalidChoice : public exception {
public:
    const char *what() const throw() {
        return "Nilai pilihan tidak valid!";
    }
};

/**
 * @exception Thrown when input is empty.
 * 
 */
class EmptyChoice : public exception {
public:
    const char *what() const throw() {
        return "Tidak ada pilihan!";
    }
};

/**
 * @exception Thrown when file is not found.
 * 
 */
class FileNotFoundException : public exception {
public:
    const char *what() const throw() {
        return "File tidak ditemukan!";
    }
};

/**
 * @exception Thrown when given file format is invalid.
 * 
 */
class InvalidFileInputFormatException : public exception {
public:
    const char *what() const throw() {
        return "Terdapat kesalahan format penulisan di dalam file";
    }
};

#endif