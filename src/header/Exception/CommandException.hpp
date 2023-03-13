#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <exception>
#include "../../enums/AbilityTypes.hpp"
#include "../Commands/Ability.hpp"

using std::exception;

class UsedAbility : public exception  {
private:
	AbilityTypes targetType;

public:
	UsedAbility(AbilityTypes targetType) {
		this->targetType = targetType;
	}

	const char* what() const throw() {
		return ("Maaf, kamu sudah pernah menggunakan ability " + Ability::parseAbility(targetType) + ".").c_str();
	}
};

class MissingAbility : public exception  {
private:
	AbilityTypes targetType;

public:
	MissingAbility(AbilityTypes targetType) {
		this->targetType = targetType;
	}

	const char* what() const throw() {
		// PERLU MEKANISME PRINT ENUM
		return ("Eits, tidak bisa. Kamu tidak punya kartu Ability " + Ability::parseAbility(targetType) + ".").c_str();
	}
};

class NerfedAbility : public exception {
private:
	AbilityTypes targetType;

public:
	NerfedAbility(AbilityTypes targetType) {
		this->targetType = targetType;
	}

	const char* what() const throw() {
		return ("Oops, kartu ability "+ Ability::parseAbility(targetType) + "-mu telah dimatikan sebelumnya:(.").c_str();
	}
};

#endif