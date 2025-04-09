#include "Enemy.h"

void Enemy::displayInfo() const {
    Entity::displayInfo(); // Âûçîâ ìåòîäà áàçîâîãî êëàññà
    std::cout << "Type: " << type << std::endl;
}
