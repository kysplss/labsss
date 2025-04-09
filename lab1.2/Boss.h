#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>

class Boss:public Enemy
{
private:
	std::string type; // Ïðèâàòíîå ïîëå: òèï âðàãà

public:
	// Êîíñòðóêòîð ïðîèçâîäíîãî êëàññà
	Boss(const std::string& n, int h, const std::string& t)
		: Enemy(n, h, t) {}

	void specialAbility() const;
	void displayInfo() const override;
};
