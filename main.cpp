//esteban mora
//esteban mora
#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Player.h"
#include "RandomEvent.h"

using namespace std;

// Function 1 & 2 (Player Focus)
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

// Function 3 & 4 (Item Focus)
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
string getItemFlavorText(const Item& i) {
    return "The " + i.name + " feels cold in your hands.";
}

// Function 5 & 6 (Event Focus)
void executeEvent(RandomEvent& re, Player& p) {
    re.trigger(p);
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

        castle.addRoom(Room(name, desc, actionList, Item(itemName)));
    }

    auto curr = castle.getHead();
    while (curr && player.isAlive()) {
        displayPlayerReport(player);
        cout << curr->room.toString();

        int count = 1;
        for (const auto& a : curr->room.getActions()) {
            cout << count++ << ". " << a << endl;
        }

        int choice;
        cout << "\nChoose (1-" << curr->room.getActions().size() << "): ";
        if (!(cin >> choice)) break;

        if (choice == (int)curr->room.getActions().size()) {
            curr = curr->next;
        } else {
            if (!checkEventSafety(player)) executeEvent(events, player);
            processLoot(player, curr->room);
            handleSurvivalBonus(player);
        }

        if (!player.isAlive()) {
            cout << "\n*** GAME OVER ***\nYou died after finding " << player.getInvSize() << " items." << endl;
            return 0;
        }
    }

    cout << "\nCongratulations! You escaped the castle!" << endl;
    return 0;
}