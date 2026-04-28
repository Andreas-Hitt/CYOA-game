//Esteban Mora
//Carlos Vega
//Andreas Hitt
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "LinkedList.h"
#include "Player.h"
#include "RandomEvent.h"
#include "Shop.h"
#include "Combat.h"
#include "SaveSystem.h"

using namespace std;

// Function 1 & 2 (Player Focus)
void displayPlayerReport(const Player& p) {
    p.displayStatus();
}
std::string handleSurvivalBonus(Player& p) {
    static int actions = 0;
    if (++actions % 3 == 0) {
        p.addLuck(1);
        return ">> SURVIVOR BONUS: +1 Luck!\n";
    }
    return std::string();
}

// Function 3 & 4 (Item Focus)
std::string processLoot(Player& p, Room& r) {
    std::string result;
    if (!r.isSearched() && !r.getItems().empty()) {
        for (const auto& item : r.getItems()) {
            result += ">> You scavenged a [" + item.name + "]!\n";
            p.addItem(item);
        }
        r.clearItems();
        r.setSearched(true);
    } else {
        result += ">> This area has been thoroughly picked over.\n";
    }
    return result;
}
string getItemFlavorText(const Item& i) {
    return "The " + i.name + " feels cold in your hands.";
}

// Function 5 & 6 (Event Focus)
std::string executeEvent(RandomEvent& re, Player& p) {
    return re.trigger(p);
}
bool checkEventSafety(const Player& p) {
    if (p.getLuck() > 20) {
        return true;
    }
    return false;
}

// Shop Function
void visitShop(Shop& shop, Player& player) {
    cout << "\n>> You enter the castle shop!" << endl;
    while (true) {
        shop.displayItems();
        cout << "\nOptions: buy <item_name>, sell <item_name>, leave" << endl;
        cout << "Your gold: " << player.getMoney() << endl;
        cout << "> ";
        string command;
        getline(cin, command);
        if (command == "leave") break;
        size_t space = command.find(' ');
        if (space == string::npos) {
            cout << "Invalid command." << endl;
            continue;
        }
        string action = command.substr(0, space);
        string itemName = command.substr(space + 1);
        if (action == "buy") {
            shop.buyItem(itemName, player);
        } else if (action == "sell") {
            shop.sellItem(itemName, player);
        } else {
            cout << "Invalid action." << endl;
        }
    }
    cout << ">> You leave the shop." << endl;
}

int main() {
    LinkedList rooms;
    size_t roomCount = 0;
    Player player;
    RandomEvent events;
    Combat combat;
    SaveSystem saveSystem;

    ifstream file("rooms.csv");
    string line;
    if (!file.is_open()) {
        cout << "Error: Place rooms.csv in the same folder as the exe." << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, desc, acts, itemName;
        
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, acts, ',');
        getline(ss, itemName, ',');
        string enemyName, enemyHealthStr, enemyDamageStr;
        getline(ss, enemyName, ',');
        getline(ss, enemyHealthStr, ',');
        getline(ss, enemyDamageStr);
        
        stringstream as(acts);
        string action;
        vector<string> actionList;
        while (getline(as, action, ';')) {
            actionList.push_back(action);
        }

        vector<Enemy> enemies;
        if (!enemyName.empty()) {
            int eh = stoi(enemyHealthStr);
            int ed = stoi(enemyDamageStr);
            enemies.push_back(Enemy(enemyName, eh, ed));
        }

        rooms.addRoom(Room(name, desc, actionList, std::vector<Item>{Item(itemName)}, enemies));
        ++roomCount;
    }

    Shop shop;
    shop.addItem(Item("Sword", "Rare", 5, 50));
    shop.addItem(Item("Shield", "Uncommon", 8, 40));
    shop.addItem(Item("Potion", "Common", 1, 20));

    size_t currentIndex = 0;
    auto currentRoom = rooms.getHead();
    cout << "Load save? (y/n): ";
    char loadChoice;
    cin >> loadChoice;
    if (loadChoice == 'y' || loadChoice == 'Y') {
        if (saveSystem.load(player, currentIndex)) {
            cout << ">> Save loaded!" << endl;
        } else {
            cout << ">> No save found, starting new game." << endl;
            currentIndex = 0;
        }
    } else {
        currentIndex = 0;
    }
    cin.ignore(1000, '\n');

    currentRoom = rooms.getHead();
    for (size_t i = 0; i < currentIndex && currentRoom; ++i) {
        currentRoom = currentRoom->next;
    }

    std::string turnMessages;
    while (currentRoom && currentIndex < roomCount && player.isAlive()) {
        displayPlayerReport(player);
        if (!turnMessages.empty()) {
            cout << endl << turnMessages << endl;
            turnMessages.clear();
        }
        cout << currentRoom->room.toString();

        int count = 1;
        for (const auto& a : currentRoom->room.getActions()) {
            cout << count++ << ". " << a << endl;
        }
        cout << "9. Save Game" << endl;

        int choice;
        cout << "\nChoose (1-9): ";
        if (!(cin >> choice)) break;
        cin.ignore(1000, '\n');

        if (choice < 1 || choice > 9) {
            cout << "Invalid choice. Please choose a number between 1 and 9." << endl;
            continue;
        }

        string chosenAction;
        if (choice == 9) {
            chosenAction = "Save Game";
        } else if (choice >= 1 && choice < count) {
            chosenAction = currentRoom->room.getActions()[choice-1];
        } else {
            cout << "Invalid choice." << endl;
            continue;
        }

        if (chosenAction == "Leave the room") {
            currentIndex++;
            if (currentRoom) currentRoom = currentRoom->next;
        } else if (chosenAction == "Visit Shop") {
            visitShop(shop, player);
        } else if (chosenAction == "Save Game") {
            saveSystem.save(player, currentIndex);
            cout << ">> Game saved!" << endl;
        } else {
            // Combat first
            for (auto& enemy : currentRoom->room.getEnemies()) {
                if (!combat.fight(player, enemy)) {
                    cout << "\n*** GAME OVER ***\nYou died after finding " << player.getInvSize() << " items." << endl;
                    return 0;
                }
            }
            if (player.getLuck() > 20) {
                turnMessages += ">> Your intuition warns you of danger. You avoid a trap!\n";
            } else {
                turnMessages += events.trigger(player);
            }
            turnMessages += processLoot(player, currentRoom->room);
            turnMessages += handleSurvivalBonus(player);
        }

        if (!player.isAlive()) {
            cout << "\n*** GAME OVER ***\nYou died after finding " << player.getInvSize() << " items." << endl;
            return 0;
        }
    }

    if (currentIndex >= roomCount) {
        cout << "\nCongratulations! You escaped the castle!" << endl;
    }
    return 0;
}