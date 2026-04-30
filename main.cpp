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

// --- Helper Functions ---

void processLoot(Player& p, Room& r) {
    if (!r.isSearched() && !r.getItems().empty()) {
        for (const auto& item : r.getItems()) {
            cout << ">> You scavenged a [" << item.name << "]!" << endl;
            p.addItem(item);
        }
        r.clearItems();
        r.setSearched(true);
    } else {
        cout << ">> This area has been thoroughly picked over." << endl;
    }
}

void visitShop(Shop& shop, Player& player) {
    cout << "\n>> You enter the castle shop!" << endl;
    shop.displayItems();
    cout << "Options: buy <name>, sell <name>, leave" << endl;
    // Simple shop interaction logic
    string cmd;
    cin >> cmd;
    if (cmd == "leave") return;
    string itemName;
    cin >> itemName;
    if (cmd == "buy") shop.buyItem(itemName, player);
    else if (cmd == "sell") shop.sellItem(itemName, player);
}

int main() {
    LinkedList castle;
    Player player;
    RandomEvent events;
    Combat combat;
    SaveSystem saveSystem;
    Shop shop;

    // Add some default items to the shop
    shop.addItem(Item("HealthPotion", "Common", 1, 15));
    shop.addItem(Item("SteelSword", "Rare", 5, 40));

    // --- Room Loading (CSV Parsing) ---
    ifstream file("rooms.csv");
    string line;
    if (!file.is_open()) {
        cout << "Error: rooms.csv not found!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string name, desc, acts, itemName, eName, eHealth, eDmg;
        
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, acts, ',');
        getline(ss, itemName, ',');
        getline(ss, eName, ',');
        getline(ss, eHealth, ',');
        getline(ss, eDmg);

        stringstream as(acts);
        string action;
        vector<string> actionList;
        while (getline(as, action, ';')) actionList.push_back(action);

        vector<Item> roomItems;
        if (itemName != "" && itemName != "None") roomItems.push_back(Item(itemName));

        vector<Enemy> roomEnemies;
        if (!eName.empty()) {
            roomEnemies.push_back(Enemy(eName, stoi(eHealth), stoi(eDmg)));
        }

        castle.addRoom(Room(name, desc, actionList, roomItems, roomEnemies));
    }

    // --- Main Game Loop ---
    auto curr = castle.getHead();
    size_t roomIdx = 0;

    cout << "Welcome to Castle Escape! Load save? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') saveSystem.load(player, roomIdx);

    while (curr && player.isAlive()) {
        player.displayStatus();
        cout << curr->room.toString();

        auto roomActions = curr->room.getActions();
        int actionCount = (int)roomActions.size();
        
        for (int i = 0; i < actionCount; ++i) {
            cout << i + 1 << ". " << roomActions[i] << endl;
        }
        cout << actionCount + 1 << ". Manage Bag (Sort/Search/Save)" << endl;

        int input;
        cout << "\nAction: ";
        if (!(cin >> input)) break;

        // OPTION: Manage Bag
        if (input == actionCount + 1) {
            cout << "1. Sort by Value | 2. Search Value | 3. Save | 4. Back" << endl;
            int sub; cin >> sub;
            if (sub == 1) player.sortInventoryByValue();
            else if (sub == 2) {
                int val; cout << "Value: "; cin >> val;
                cout << "Index: " << player.findItemIndex(val) << endl;
            }
            else if (sub == 3) saveSystem.save(player, roomIdx);
            continue; 
        }

        // VALIDATE INPUT
        if (input < 1 || input > actionCount) {
            cout << "Invalid choice." << endl;
            continue;
        }

        string chosenAction = roomActions[input - 1];

        // OPTION: Leave the Room 
        if (chosenAction == "Leave the room") {
            curr = curr->next;
            roomIdx++;
            cout << ">> You move deeper into the castle..." << endl;
            continue; 
        }

        // OPTION: Visit Shop 
        if (chosenAction == "Visit Shop") {
            visitShop(shop, player);
            continue;
        }

        // DEFAULT: Combat and Looting for all other actions
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

    if (player.isAlive()) cout << "You escaped!" << endl;
    else cout << "Game Over." << endl;

    return 0;
}