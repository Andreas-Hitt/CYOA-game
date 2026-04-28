#include "Enemy.h"

// Create an enemy with an optional name, health, and damage.
// Defaults are provided for a basic Goblin enemy.
Enemy::Enemy(std::string n, int h, int d)
    : name(n), health(h), damage(d) {}
