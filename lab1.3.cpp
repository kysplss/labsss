#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Entity {
protected:
    std::string name;
    int health;
    int attack;
    int defense;
    const int maxHealth = 100;

public:
    Entity(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    virtual void attack(Entity& target) {
        int damage = attack - target.defense;
        if (damage > 0) {
            target.health -= damage;
            std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
        }
    }

    virtual void heal(int amount) {
        if (amount > 0) {
            health += amount;
            if (health > maxHealth) health = maxHealth;
            std::cout << name << " healed for " << amount << " HP. Current HP: " << health << "\n";
        }
    }

    virtual void displayInfo() const {
        std::cout << "Entity: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << "\n";
    }

    virtual ~Entity() {}
};

class Character : public Entity {
public:
    Character(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    void attack(Entity& target) override {
        int damage = attack - target.defense;
        if (damage > 0) {
            if (rand() % 100 < 20) {
                damage *= 2;
                std::cout << "Critical hit! ";
            }
            target.health -= damage;
            std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
        }
    }

    void heal(int amount) override {
        if (amount > 0) {
            health += amount * 1.5; 
            if (health > maxHealth) health = maxHealth;
            std::cout << name << " used healing potion! HP restored to " << health << "\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Character: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << "\n";
    }
};

class Monster : public Entity {
public:
    Monster(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    void attack(Entity& target) override {
        int damage = attack - target.defense;
        if (damage > 0) {
            if (rand() % 100 < 30) {
                damage += 5;
                std::cout << "Poisonous attack! ";
            }
            target.health -= damage;
            std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Monster: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << "\n";
    }
};

class Boss : public Monster {
private:
    std::string specialAbility;

public:
    Boss(const std::string& n, int h, int a, int d, const std::string& ability)
        : Monster(n, h, a, d), specialAbility(ability) {}

    void attack(Entity& target) override {
        int damage = attack - target.defense;
        if (damage > 0) {
            if (rand() % 100 < 40) {
                damage *= 1.5;
                std::cout << specialAbility << "! ";
            }
            target.health -= damage;
            std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Boss: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense
            << ", Ability: " << specialAbility << "\n";
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Character hero("Hero", 100, 20, 10);
    Monster goblin("Goblin", 50, 15, 5);
    Boss dragon("Dragon", 200, 30, 20, "Fire Breath");

    Entity* entities[] = { &hero, &goblin, &dragon };

    for (auto& entity : entities) {
        entity->displayInfo();
    }

    hero.attack(goblin);
    goblin.attack(hero);
    dragon.attack(hero);

    hero.heal(20);
    hero.attack(dragon);

    return 0;
}
