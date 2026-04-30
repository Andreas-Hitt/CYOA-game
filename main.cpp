#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"
#include "Player.h"
#include "RandomEvent.h"
#include "Shop.h"
#include "Combat.h"
#include "SaveSystem.h"

using namespace std;

// Logic Fix: Generates random stats for scavenged items
void processLoot(Player& p, Room& r) {
    if (!r.isSearched() && !r.getItems().empty()) {
        for (auto& item : r.getItems()) {
            // 1. Roll for Rarity (1-5)
            int roll = (rand() % 5) + 1;
            if (roll == 1) item.rarity = "Common";
            else if (roll == 2) item.rarity = "Uncommon";
            else if (roll == 3) item.rarity = "Rare";
            else if (roll == 4) item.rarity = "Epic";
            else item.rarity = "Legendary";

            // 2. Roll for Quality (0.5 to 1.25)
            // (rand() % 76) gives 0-75. Adding 50 gives 50-125. Divide by 100.0.
            item.condition = ((rand() % 76) + 50) / 100.0f;

            cout << ">> You scavenged a [" << item.rarity << "] " << item.name 
                 << " (Quality: " << (int)(item.condition * 100) << "%)!" << endl;
            
            p.addItem(item);
        }
        r.clearItems();
        r.setSearched(true);
    } else {
        cout << ">> This area has been thoroughly picked over." << endl;
    }
}

void visitShop(Shop& shop, Player& player) {
    while (true) {
        cout << "\n--- CASTLE SHOP ---" << endl;
        shop.displayItems();
        cout << "Current Gold: " << player.getMoney() << "g" << endl;
        cout << "Options: [buy <name>] [sell <name>] [leave]" << endl;
        cout << ">> ";
        
        string cmd;
        cin >> cmd;
        if (cmd == "leave") break;
        
        string itemName;
        cin >> itemName;
        
        if (cmd == "buy") {
            if (!shop.buyItem(itemName, player)) cout << ">> Cannot buy that." << endl;
        } else if (cmd == "sell") {
            if (!shop.sellItem(itemName, player)) cout << ">> You don't have that." << endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed RNG for looting
    LinkedList castle;
    Player player;
    RandomEvent events;
    Combat combat;
    SaveSystem saveSystem;
    Shop shop;

    shop.addItem(Item("HealthPotion", "Common", 1, 15, 1.0f, 20));
    shop.addItem(Item("SteelSword", "Rare", 5, 40, 1.0f, 60));

    ifstream file("rooms.csv");
    string line;
    if (!file.is_open()) {
        cout << "Error: rooms.csv not found!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, desc, acts, itemName, eName, eHealth, eDmg, baseValStr;
        
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, acts, ',');
        getline(ss, itemName, ',');
        getline(ss, eName, ',');
        getline(ss, eHealth, ',');
        getline(ss, eDmg, ',');
        getline(ss, baseValStr); // New: Read base value from CSV

        int baseVal = (baseValStr.empty()) ? 30 : stoi(baseValStr);

        stringstream as(acts);
        string action;
        vector<string> actionList;
        while (getline(as, action, ';')) actionList.push_back(action);

        vector<Item> roomItems;
        if (itemName != "" && itemName != "None") {
            // Initialize item with base value from CSV
            roomItems.push_back(Item(itemName, "Common", 1, 0, 1.0f, baseVal));
        }

        vector<Enemy> roomEnemies;
        if (!eName.empty() && eName != "None") {
            roomEnemies.push_back(Enemy(eName, stoi(eHealth), stoi(eDmg)));
        }

        castle.addRoom(Room(name, desc, actionList, roomItems, roomEnemies));
    }

    auto curr = castle.getHead();
    size_t roomIdx = 0;

    cout << "Welcome to Castle Escape! Load save? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        size_t loadedIdx = 0;
        if (saveSystem.load(player, loadedIdx)) {
            for(size_t i = 0; i < loadedIdx && curr->next; ++i) {
                curr = curr->next;
                roomIdx++;
            }
        }
    }

    while (curr && player.isAlive()) {
        player.displayStatus();
        cout << curr->room.toString();

        auto roomActions = curr->room.getActions();
        int actionCount = (int)roomActions.size();
        
        for (int i = 0; i < actionCount; ++i) {
            cout << i + 1 << ". " << roomActions[i] << endl;
        }
        cout << actionCount + 1 << ". Manage Bag" << endl;

        int input;
        cout << "\nAction: ";
        if (!(cin >> input)) break;

        if (input == actionCount + 1) {
            cout << "1. Sort | 2. Search | 3. Save | 4. Back" << endl;
            int sub; cin >> sub;
            if (sub == 1) player.sortInventoryByValue();
            else if (sub == 3) saveSystem.save(player, roomIdx);
            continue; 
        }

        if (input < 1 || input > actionCount) continue;

        string chosenAction = roomActions[input - 1];

        if (chosenAction == "Leave the room") {
            curr = curr->next;
            roomIdx++;
            continue; 
        } 
        
        if (chosenAction == "Visit Shop") {
            visitShop(shop, player);
            continue;
        } 

        // Specific room actions trigger combat/loot
        bool defeatedAll = true;
        for (auto& enemy : curr->room.getEnemies()) {
            if (!combat.fight(player, enemy)) {
                defeatedAll = false;
                break;
            }
        }

        if (player.isAlive() && defeatedAll) {
            string eventMsg = events.trigger(player);
            if (!eventMsg.empty()) cout << eventMsg << endl;
            processLoot(player, curr->room);
        }
    }

    if (player.isAlive()) cout << "\n*** ESCAPED! ***" << endl;
    else cout << "\n--- DEAD ---" << endl;

    return 0;
}