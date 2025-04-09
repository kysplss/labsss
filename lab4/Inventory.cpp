#include "Inventory.h"

Inventory::Inventory() {
    n = 0;  // ßâíàÿ èíèöèàëèçàöèÿ
    inventory = nullptr;
}

void Inventory::addItem(const std::string& item) {
    n += 1;  // Óâåëè÷èâàåì ðàçìåð

  // Ñîçäàåì íîâûé ìàññèâ ñ íîâûì ðàçìåðîì
    std::unique_ptr<std::string[]> newInventory(new std::string[n]);

    // Êîïèðóåì ñòàðûå ýëåìåíòû
    for (int i = 0; i < n - 1; i++) {
        newInventory[i] = inventory[i];
    }

    // Äîáàâëÿåì íîâûé ýëåìåíò
    newInventory[n - 1] = item;

    // Ïåðåíîñèì âëàäåíèå (ñòàðûé ìàññèâ àâòîìàòè÷åñêè óäàëèòñÿ)
    inventory = std::move(newInventory);
}

void Inventory::displayInventory() {
    for (int i = 0; i < n; i++) {
        std::cout << inventory[i] << "\n";
    }
}
