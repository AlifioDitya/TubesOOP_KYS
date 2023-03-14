#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "../GameEnvironment/CandyGameManager.hpp"
#include "../GameEnvironment/CangkulGameManager.hpp"

class Program {
public:
    CandyGameManager candyGameManager;
    CangkulGameManager cangkulGameManager;
    
    // Initiate program
    void start();
};

#endif