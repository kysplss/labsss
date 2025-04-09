#pragma once
#include <string>
#include <iostream>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    // Ïåðåãðóçêà îïåðàòîðà ==
    bool operator==(const Character& other) const {
        return name == other.name && health == other.health;
    }

    // Ïåðåãðóçêà îïåðàòîðà <<
    friend std::ostream& operator<<(std::ostream& os, const Character& character) {
        os << "Character: " << character.name << ", HP: " << character.health
            << ", Attack: " << character.attack << ", Defense: " << character.defense;
        return os;
    }
};

