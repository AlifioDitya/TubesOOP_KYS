// Commands.hpp
#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP


#include <string>

using std::string;

template <class T1, class T2>
class BaseCommand {
protected:
    T1 command;
    
public:
    // Default ctor
    BaseCommand() {

    }

    // dtor
    virtual ~BaseCommand() {

    }

    // ========== Getters ==========
    
    // getter for command type
    virtual T1 getCommandType() const {
        return command;
    }

    // ========== Methods ==========

    // Execute command
    virtual void executeCommand(T2&) = 0;
};

#endif