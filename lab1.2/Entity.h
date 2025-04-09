#pragma once
#include <iostream>
#include <string>

class Entity {
protected:
    std::string name; // Çàùèùåííîå ïîëå: èìÿ
    int health;      // Çàùèùåííîå ïîëå: çäîðîâüå

public:
    // Êîíñòðóêòîð áàçîâîãî êëàññà
    Entity(const std::string& n, int h) : name(n), health(h) {};

    // Ìåòîä äëÿ âûâîäà èíôîðìàöèè
    virtual void displayInfo() const ;

    virtual ~Entity() {}
};
