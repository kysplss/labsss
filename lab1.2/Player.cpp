#include "Player.h"

void Player::displayInfo() const {
    Entity::displayInfo(); // Âûçîâ ìåòîäà áàçîâîãî êëàññà
    std::cout << "Experience: " << experience << std::endl;
}
