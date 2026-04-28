#ifndef ACCESSORY_H
#define ACCESSORY_H

#include <string>
#include <vector>

// Accessory models headwear options with protection, luck, and value stats.
class Accessory {
public:
    enum class Type {
        Fedora,
        Cowboy,
        Beanie
    };

private:
    Type type;               // The specific accessory type.
    std::string name;        // Display name.
    int protection;          // Defensive quality of the hat.
    int luckBonus;           // Luck bonus granted when equipped.
    int value;               // Monetary or comparative worth.

public:
    Accessory(Type type = Type::Fedora);

    std::string getName() const;
    int getProtection() const;
    int getLuckBonus() const;
    int getValue() const;
};

// AccessoryManager holds a collection of hats and provides selection/search logic.
class AccessoryManager {
private:
    std::vector<Accessory> hats;  // Stores available hat choices.

public:
    AccessoryManager();

    void displayHatOptions() const;
    const Accessory* chooseHat(int choice) const;
    void sortHatsByValue();
    int findHatIndex(int targetValue) const;
};

#endif
