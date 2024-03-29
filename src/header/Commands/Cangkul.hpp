/**
 * @file Cangkul.hpp
 * @brief Header file for the Cangkul class.
 * 
 */
#ifndef CANGKUL_HPP
#define CANGKUL_HPP

#include "CangkulCommand.hpp"

/**
 * @class Cangkul
 * @brief Class that defines the Cangkul command
 * @extends CangkulCommand
 * 
 */
class Cangkul : public CangkulCommand {
private:
    /**
     * @brief Validate command by throwing exception if necessary
     * 
     * @param gameState State of the game to be validated on
     */
    void validateCommand(CangkulGameState&);

public:
    /**
     * @brief Construct a new Cangkul object
     * 
     */
    Cangkul();

    // ========== Methods ==========

    /**
     * @brief Executes Cangkul
     * 
     * @param gameState State of the game to be applied to
     */
    void executeCommand(CangkulGameState& gameState);
};

#endif