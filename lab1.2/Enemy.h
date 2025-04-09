#pragma once

#include <iostream>
#include <string>
#include "Entity.h"
class Enemy : public Entity {
private:
    std::string type; // Ïðèâàòíîå ïîëå: òèï âðàãà

public:
    // Êîíñòðóêòîð ïðîèçâîäíîãî êëàññà
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {}

    // Ïåðåîïðåäåëåíèå ìåòîäà displayInfo
    virtual void displayInfo() const override;
};


