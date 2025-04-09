#pragma once
#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Entity(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    // Âèðòóàëüíûé ìåòîä äëÿ àòàêè
    virtual void toAttack(Entity& target);

    // Âèðòóàëüíûé ìåòîä äëÿ âûâîäà èíôîðìàöèè
    virtual void displayInfo() const;

    virtual void heal(int amount) {}

    // Âèðòóàëüíûé äåñòðóêòîð
    virtual ~Entity() {}



    // Ãåòòåðû
    int getHealth() const { return health; }
    int getDefense() const { return defense; }
    std::string getName() const { return name; }

    void takeDamage(int damage) { health -= damage; }
};
