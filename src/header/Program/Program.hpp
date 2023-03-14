/**
*   @file Program.hpp
*   @brief Header file for the Program class.
**/

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "../GameEnvironment/CandyGameManager.hpp"
#include "../GameEnvironment/CangkulGameManager.hpp"


/**
*   @class Program
*   @brief Class representing the main program.
**/
class Program {
public:
    /**
    *   @brief Manager for Candy Game
    **/
    CandyGameManager candyGameManager;
    /**
    *   @brief Manager for Cangkul Game
    **/
    CangkulGameManager cangkulGameManager;
    
    /*
    *   @brief Method to initiate the program
    */
    void start();
};

#endif