#pragma once
#include <iostream>
#include <string>

class Weapon {
private:
    std::string title;
    int damage;
    int weight;

public:
    // Êîíñòðóêòîð
    Weapon(const std::string& t, int d, int w)
        : title(t), damage(d), weight(w) {}

    // Äåñòðóêòîð
    ~Weapon();

    void displayInfo() const;
};
