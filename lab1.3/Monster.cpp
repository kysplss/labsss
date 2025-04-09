#include "Monster.h"

void Monster::toAttack(Entity& target){
    int damage = attack - target.getDefense();
    if (damage > 0) {
        // Øàíñ íà ÿäîâèòóþ àòàêó (30%)
        if (rand() % 100 < 30) {
            damage += 5; // Äîïîëíèòåëüíûé óðîí îò ÿäà
            std::cout << "Poisonous attack! ";
        }
        target.takeDamage(damage);
        std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
    }
    else {
        std::cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
    }
}

void Monster::displayInfo() const{
    std::cout << "Monster: " << name << ", HP: " << health
        << ", Attack: " << attack << ", Defense: " << defense << std::endl;
}
