/**
 * @file BaseCommand.hpp
 * @brief Header file for BaseCommand class that defines the bases of an in-game command
 * 
 */
#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP

#include <string>

using std::string;

/**
 * @brief Class that defines the bases of an in-game command.
 * 
 * @tparam T1 Command type
 * @tparam T2 Game state type
 */
template<class T1, class T2>
class BaseCommand {
protected:
    T1 command;

public:
    /**
     * @brief Construct a new Base Command object
     * 
     */
    BaseCommand() {

    }

    /**
     * @brief Destroy the Base Command object
     * 
     */
    virtual ~BaseCommand() {

    }

    /**
     * @brief Get the Command Type object
     * 
     * @return Command type
     */
    virtual T1 getCommandType() const {
        return command;
    }

    /**
     * @brief Executes specific command
     * 
     * @param gameState State of the game to be applied to
     */
    virtual void executeCommand(T2&) = 0;
};

#endif