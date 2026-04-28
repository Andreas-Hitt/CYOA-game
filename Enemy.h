#ifndef ENEMY_H
#define ENEMY_H

#include <string>

// Enemy represents a single combat opponent in the game.
// It stores the enemy's name, health, and damage output.
class Enemy {
public:
    std::string name;
    int health;
    int damage;

    // Create an enemy with an optional name, health, and damage.
    // Defaults are provided for a basic Goblin enemy.
    Enemy(std::string n = "Goblin", int h = 20, int d = 5);
};

#endif