#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include "../../enums/AbilityTypes.hpp"
#include "../Commands/Ability.hpp"

#include <exception>

using std::exception;

// exception when ability is already used
class UsedAbility : public exception  {
private:
	AbilityTypes targetType;
	string msg;

public:
	UsedAbility(AbilityTypes targetType) {
		this->targetType = targetType;
		msg = "Maaf, kamu sudah pernah menggunakan ability " + Ability::parseAbility(targetType) + ".";
	}

	const char* what() const throw() {
		
		return msg.c_str();
	}
};

// exception when current player doesn't have the target ability
class MissingAbility : public exception  {
private:
	AbilityTypes targetType;
	string msg;

public:
	MissingAbility(AbilityTypes targetType) {
		this->targetType = targetType;
		msg = "Ets, tidak bisa. Kamu tidak punya kartu Ability " + Ability::parseAbility(targetType) + ".";
	}

	const char* what() const throw() {
		// PERLU MEKANISME PRINT ENUM

		return msg.c_str();
	}
};

// exception when ability is already nerfed
class NerfedAbility : public exception {
private:
	AbilityTypes targetType;
	string msg;

public:
	NerfedAbility(AbilityTypes targetType) {
		this->targetType = targetType;
		msg = "Oops, kartu ability "+ Ability::parseAbility(targetType) + "-mu telah dimatikan sebelumnya:(.";
	}

	const char* what() const throw() {
		return msg.c_str();
	}
};

#endif