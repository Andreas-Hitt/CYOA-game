#include "Player.h"

// Initialize a new player with default statistics.
Player::Player() : health(100), money(50), luck(5), damage(10) {}

// Adjust the player's health by the provided amount.
void Player::adjustHealth(int amount) { health += amount; }

// Adjust the player's money by the provided amount.
void Player::adjustMoney(int amount) { money += amount; }

// Increase the player's luck stat.
void Player::addLuck(int amount) { luck += amount; }

// Add an item to the player's inventory.
void Player::addItem(Item item) { inventory.add(item); }

// Accessor methods for the player's current stats.
int Player::getHealth() const { return health; }
int Player::getMoney() const { return money; }
int Player::getLuck() const { return luck; }
int Player::getDamage() const { return damage; }
int Player::getInvSize() const { return inventory.getSize(); }

// Determine whether the player is still alive.
bool Player::isAlive() const { return health > 0; }

// Display the player's current status and inventory contents.
void Player::displayStatus() const {
    std::string condition = (health < 30) ? "WOUNDED" : "HEALTHY";
    std::cout << "\n========================================" << std::endl;
    std::cout << " STATUS: " << condition << " | HP: " << health << " | Gold: " << money << " | Luck: " << luck << std::endl;
    std::cout << " INV: ";
    if(inventory.getSize() == 0) std::cout << "Empty";
    for (const auto& item : inventory.getItems()) std::cout << "[" << item.name << "] ";
    std::cout << "\n========================================" << std::endl;
}

// Provide mutable and const access to the player's inventory.
Inventory& Player::getInventory() { return inventory; }
const Inventory& Player::getInventory() const { return inventory; }

// Check whether the player has an item with the given name.
bool Player::hasItem(const std::string& name) { return inventory.search(name) != nullptr; }

// Remove an item from the player's inventory by name.
void Player::removeItem(const std::string& name) { inventory.remove(name); }