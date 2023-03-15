/**
 * @file CommandException.hpp
 * @brief Header file containing the declarations of custom commands exception classes used in the game.
 * This file contains the declaration of custom exception classes that can be thrown during the execution of the game.
 * These exceptions provide additional information and error messages to the user in case an exceptional situation occurs.
 * 
 */

#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include "../../enums/AbilityTypes.hpp"
#include "../../enums/CangkulCmdTypes.hpp"
#include "../Commands/Ability.hpp"
#include "../Commands/CangkulCommand.hpp"

#include <exception>

using std::exception;

/**
 * @exception Thrown when the player tries to use an ability that has already been used in the current round. 
 * 
 */
class UsedAbility : public exception {
private:
    AbilityTypes targetType;
    string msg;

public:
    UsedAbility(AbilityTypes targetType) {
        this->targetType = targetType;
        msg = "Maaf, kamu sudah pernah menggunakan ability " + Ability::parseAbility(targetType) + ".";
    }

    const char *what() const throw() {
        return msg.c_str();
    }
};

/**
 * @exception Thrown when current player doesn't have the target ability.
 * 
 */
class MissingAbility : public exception {
private:
    AbilityTypes targetType;
    string msg;

public:
    MissingAbility(AbilityTypes targetType) {
        this->targetType = targetType;
        msg = "Ets, tidak bisa. Kamu tidak punya kartu Ability " + Ability::parseAbility(targetType) + ".";
    }

    const char *what() const throw() {
        // PERLU MEKANISME PRINT ENUM
        return msg.c_str();
    }
};

/**
 * @exception Thrown when a player's ability is nerfed by abilityless.
 * 
 */
class NerfedAbility : public exception {
private:
    AbilityTypes targetType;
    string msg;

public:
    NerfedAbility(AbilityTypes targetType) {
        this->targetType = targetType;
        msg = "Oops, kartu ability " + Ability::parseAbility(targetType) + "-mu telah dimatikan sebelumnya:(.";
    }

    const char *what() const throw() {
        return msg.c_str();
    }
};

/**
 * @exception Thrown when an unnecessary action is done
 * 
 */
class UnnecessaryAction : public exception {
private:
    CangkulCmdTypes targetType;
    string msg;
public:
    UnnecessaryAction(CangkulCmdTypes targetType) {
        this->targetType = targetType;
        msg = "Aksi " + CangkulCommand::parseCommand(targetType) +
              " tidak diperlukan! Kamu dapat meletakkan salah satu kartu yang dimiliki.";
    }

    const char *what() const throw() {
        return msg.c_str();
    }
};

/**
 * @exception Thrown when skip is forbidden.
 * 
 */
class ForbiddenSkip : public exception {
public:
    const char *what() const throw() {
        return "Aksi SKIP tidak dapat dilakukan karena masih ada kartu yang dapat di-CANGKUL!";
    }
};

/**
 * @exception Thrown when a card color does not match.
 * 
 */
class UnmatchedColor : public exception {
public:
    const char *what() const throw() {
        return "Warna kartu yang dipilih tidak cocok dengan kartu table!";
    }
};

#endif