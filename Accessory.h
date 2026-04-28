#ifndef ACCESSORY_H
#define ACCESSORY_H

#include <string>
#include <vector>

class Accessory {
public:
    enum class Type {
        Fedora,
        Cowboy,
        Beanie
    };

private:
    Type type;
    std::string name;
    int protection;
    int luckBonus;
    int value;

public:
    Accessory(Type type = Type::Fedora);

    std::string getName() const;
    int getProtection() const;
    int getLuckBonus() const;
    int getValue() const;
};

class AccessoryManager {
private:
    std::vector<Accessory> hats;

public:
    AccessoryManager();

    void displayHatOptions() const;
    const Accessory* chooseHat(int choice) const;
    void sortHatsByValue();
    int findHatIndex(int targetValue) const;
};

#endif
