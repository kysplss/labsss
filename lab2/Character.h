#pragma once
#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    // Êîíñòðóêòîð
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}
    // Äåñòðóêòîð
    ~Character();

    void displayInfo() const;
};
