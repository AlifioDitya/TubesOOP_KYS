/**
*   @file IO.hpp
*   @brief Header file for the IO class.
**/

#ifndef IO_HPP
#define IO_HPP

#include <vector>

using std::vector;

/**
*   @class Program
*   @brief Class representing the Input/Output operations.
**/
class IO {
private:
    /**
    *   @brief Integer value for the user's choice
    **/
    int choice;

public:
    /**
    *   @brief Constructor for IO class
    **/
    IO();

    /**
    *   @brief Overloaded comparison operator to check if the user's choice is equal to an integer.
    *   @param[in] integer value to compare with.
    *   @return bool value indicating whether the user's choice is equal to the input integer.
    **/
    bool operator==(const int);

    /**
    *   @brief Getter method to get the user's choice.
    *   @return the integer value of the user's choice.
    **/
    int getChoice() const;

    /**
    *   @brief Method to get an integer input from the user in a specified range.
    *   @param[in] lowerBound the lower bound of the input range.
    *   @param[in] upperBound the upper bound of the input range.
    **/
    void getInput(int lowerBound, int upperBound);


    vector<int> inputCardStream(int n);

    /**
    *   @brief Method to print newline character
    **/
    static void newl();

    /**
    *   @brief Method to print border
    **/
    static void border();
};

#endif