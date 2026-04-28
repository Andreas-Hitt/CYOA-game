/*
Author: Andreas Hitt & Esteban Mora
Description: Main game engine. Manages room transitions and user input.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Player.h"
#include "RandomEvent.h"

using namespace std;

void displayPlayerReport(const Player& p) {
    p.displayStatus();
}

void handleSurvivalBonus(Player& p) {
    static int actions = 0;
    if (++actions % 3 == 0) {
        cout << ">> SURVIVOR BONUS: +1 Luck!" << endl;
        p.addLuck(1);
    }
}

void processLoot(Player& p, Room& r) {
    if (!r.isSearched() && r.getItem().name != "None") {
        cout << ">> You scavenged a [" << r.getItem().name << "]!" << endl;
        p.addItem(r.getItem());
        r.clearItem();
        r.setSearched(true);
    } else {
        cout << ">> This area has been thoroughly picked over." << endl;
    }
}

bool checkEventSafety(const Player& p) {
    if (p.getLuck() > 20) {
        cout << ">> Your intuition warns you of danger. You avoid a trap!" << endl;
        return true;
    }
    return false;
}

int main() {
    LinkedList castle;
    Player player;
    RandomEvent events;

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
        getline(ss, itemName);
        
        stringstream as(acts);
        string action;
        vector<string> actionList;
        while (getline(as, action, ';')) {
            actionList.push_back(action);
        }
        castle.addRoom(Room(name, desc, actionList, Item(itemName, 20))); 
    }

    auto curr = castle.getHead();
    while (curr && player.isAlive()) {
        displayPlayerReport(player);
        cout << curr->room.toString();

        int count = 1;
        auto roomActions = curr->room.getActions();
        for (const auto& a : roomActions) {
            cout << count++ << ". " << a << endl;
        }
        cout << count << ". Organize/Check Bag (Sort & Search)" << endl;

        int choice;
        cout << "\nChoose (1-" << count << "): ";
        if (!(cin >> choice)) break;

        if (choice == (int)roomActions.size()) {
            // Last action in CSV is always "Leave"
            curr = curr->next;
        } else if (choice == count) {
            // Algorithm Demo: Sort and search
            cout << ">> Sorting inventory by value (Selection Sort)..." << endl;
            player.sortInventoryByValue();
            player.displayStatus();
            
            string searchName;
            cout << "Search for an item by name: ";
            cin.ignore();
            getline(cin, searchName);
            int idx = player.findItemIndex(searchName);
            if(idx != -1) cout << ">> Found " << searchName << " at index " << idx << endl;
            else cout << ">> Item not found." << endl;
        } else {
            if (!checkEventSafety(player)) events.trigger(player);
            processLoot(player, curr->room);
            handleSurvivalBonus(player);
        }

        if (!player.isAlive()) {
            cout << "\n*** GAME OVER ***\nYou died after finding " << player.getInvSize() << " items." << endl;
            return 0;
        }
    }

    cout << "\nCongratulations! You escaped the castle with $" << player.getTotalInventoryValue() << " in loot!" << endl;
    return 0;
}