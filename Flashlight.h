#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include <string>
#include <vector>

// Flashlight models a light source with brightness, durability, and value.
class Flashlight {
public:
    enum class Tier {
        Basic,
        Standard,
        Premium
    };

private:
    Tier tier;                // Internal tier category.
    std::string name;         // Display name of the flashlight.
    int brightness;           // Light output rating.
    int durability;           // How long the flashlight can last.
    int value;                // Relative worth or cost.

public:
    Flashlight(Tier tier = Tier::Basic);

    std::string getName() const;
    int getBrightness() const;
    int getDurability() const;
    int getValue() const;
};

// FlashlightManager stores available flashlight options and supports sorting/search.
class FlashlightManager {
private:
    std::vector<Flashlight> flashlights;

public:
    FlashlightManager();

    void displayFlashlightOptions() const;
    const Flashlight* chooseFlashlight(int choice) const;
    void sortFlashlightsByBrightness();
    int findFlashlightIndex(int targetBrightness) const;
};

#endif
