#include "Inventory.h"

void Inventory::add(Item item) {
    items.push_back(item);
}

bool Inventory::remove(const std::string& name) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].name == name) {
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}

void Inventory::bubbleSortByName() {
    if (items.empty()) return;
    for (size_t i = 0; i < items.size() - 1; ++i) {
        for (size_t j = 0; j < items.size() - 1 - i; ++j) {
            if (items[j].name > items[j + 1].name) {
                std::swap(items[j], items[j + 1]);
            }
        }
    }
}

Item* Inventory::linearSearchByName(const std::string& name) {
    for (auto& item : items) {
        if (item.name == name) return &item;
    }
    return nullptr;
}

int Inventory::getTotalWeight() const {
    int total = 0;
    for (const auto& i : items) total += i.weight;
    return total;
}

int Inventory::getSize() const { return (int)items.size(); }

const std::vector<Item>& Inventory::getItems() const { return items; }