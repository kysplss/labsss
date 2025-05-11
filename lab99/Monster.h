#pragma once
#include <string>

// Forward declaration
class Character;

class Monster {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Monster(const std::string& n, int h, int a, int d);
    virtual ~Monster() = default;

    virtual void attackEnemy(Character& enemy); // Òîëüêî îáúÿâëåíèå
    virtual void displayInfo() const;          // Òîëüêî îáúÿâëåíèå

    std::string getName() const;
    int getHealth() const;
    void setHealth(int h);
    int getAttack() const;
    int getDefense() const;
};

class Goblin : public Monster {
public:
    Goblin(const std::string& n);
    void attackEnemy(Character& enemy) override;
};

class Dragon : public Monster {
public:
    Dragon(const std::string& n);
    void attackEnemy(Character& enemy) override;
};

class Skeleton : public Monster {
public:
    Skeleton(const std::string& n);
    void attackEnemy(Character& enemy) override;
};
