#pragma once
#include <iostream>
#include <string>
#include "Entity.h"

class Player : public Entity {
private:
    int experience; // Ïðèâàòíîå ïîëå: îïûò

public:
    // Êîíñòðóêòîð ïðîèçâîäíîãî êëàññà
    Player(const std::string& n, int h, int exp)
        : Entity(n, h), experience(exp) {}

    // Ïåðåîïðåäåëåíèå ìåòîäà displayInfo
    void displayInfo() const override;
};
