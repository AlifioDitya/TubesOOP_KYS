#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <exception>
#include "../../enums/AbilityTypes.hpp"

using std::exception;

class UsedAbility : public exception  {
private:
	AbilityTypes targetType;

public:
	UsedAbility(AbilityTypes targetType) {
		this->targetType = targetType;
	}

	const char* what() const throw() {
		// PERLU MEKANISME PRINT ENUM
		return "Maaf, kamu sudah pernah menggunakan ability [nama]";
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
		return "Ets, tidak bisa. Kamu tidak punya kartu Ability [nama]";
	}
};

class NerfedAbility : public exception {
public:
	const char* what() const throw() {
		return "Ets, tidak bisa. Ability kamu sudah dimatikan lawan";
	}
};

#endif