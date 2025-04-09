#pragma once
#include "Entity.h"
class Character : public Entity {
public:
    Character(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    // Ïåðåîïðåäåëåíèå ìåòîäà attack
    void toAttack(Entity& target) override;

    void heal(int amount) override;

    // Ïåðåîïðåäåëåíèå ìåòîäà displayInfo
    void displayInfo() const override;
};

