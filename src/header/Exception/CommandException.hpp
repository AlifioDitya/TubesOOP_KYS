#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <exception>
#include "../enums/AbilityTypes.hpp"
#include "../Commands/Ability.hpp"

using std::exception;

class InvalidCommandString: public exception {

	const char* what() const throw() {
		return "String input bukan command yang valid!";
	}
};

class InvalidAbilityString: public exception {

	const char* what() const throw() {
		return "String input bukan ability yang valid!";
	}
};

class UsedAbility : public exception  {
private:
	AbilityTypes targetType;

public:
	UsedAbility(AbilityTypes targetType) {
		this->targetType = targetType;
	}

	const char* what() const throw() {

		return ("Maaf, kamu sudah pernah menggunakan ability " + Ability::parseAbility(targetType)).c_str();
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
		return ("Ets, tidak bisa. Kamu tidak punya kartu Ability " + Ability::parseAbility(targetType)).c_str();
	}
};

class NerfedAbility : public exception {
public:
	const char* what() const throw() {
		return "Ets, tidak bisa. Ability kamu sudah dimatikan lawan";
	}
};

#endif