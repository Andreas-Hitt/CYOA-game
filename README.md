[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23170704)
# Castle Escape: C++ Adventure

A terminal-based "Choose Your Own Adventure" game where the player explores a 10-room castle, scavenges for loot, and manages survival against random events.

## Features
* **Dynamic Room System:** Explore 10 unique rooms loaded from a CSV file.
* **Inventory Management:** Scavenge for items with varying rarity (Common, Rare, Legendary) and condition.
* **Attrition Engine:** Random survival events affected by a "Luck" stat.
* **Action Logic:** Each room has custom actions that change based on whether the room has been searched.

## How to Compile and Run
1. Ensure `rooms.csv` is in the same directory as the source files.
2. Open a terminal and run the following commands ('make clean' may not be defined, if so just continue):
   ```bash
   make clean
   make
   ./adventure