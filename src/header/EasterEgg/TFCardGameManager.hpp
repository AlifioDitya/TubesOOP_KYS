#ifndef TFCARDGAMEMANAGER_HPP
#define TFCARDGAMEMANAGER_HPP

#include "Solver.hpp"

class TFCardGameManager {
private:
    Player player;
    Solver solver;
public:
    void startGame();
};

#endif