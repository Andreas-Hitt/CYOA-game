#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    std::string name;
    int health;
    int damage;

    Enemy(std::string n = "Goblin", int h = 20, int d = 5);
};

#endif