#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <exception>
#include "../../enums/AbilityTypes.hpp"
#include "../Commands/Ability.hpp"

using std::exception;

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

class MissingAbility : public exception  {
private:
	AbilityTypes targetType;
	string msg;

public:
	MissingAbility(AbilityTypes targetType) {
		this->targetType = targetType;
		msg = "Eits, tidak bisa. Kamu tidak punya kartu Ability " + Ability::parseAbility(targetType) + ".";
	}

	const char* what() const throw() {
		// PERLU MEKANISME PRINT ENUM

		return msg.c_str();
	}
};

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