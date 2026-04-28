
# CYOA Game 

## Description of the Program
CYOA Game is a text-based Choose Your Own Adventure game where players navigate through a series of rooms in a castle. Players can explore, fight enemies, collect items, experience random events, and manage their inventory. The game features combat, shopping, saving/loading, and survival mechanics.

## How to Compile and Run the Program
### Prerequisites
- C++11 compatible compiler (e.g., g++)
- Make utility

### Compilation
Run the following command in the project directory: 

make clean
make

### Running the Program
After compilation, execute: 

./adventure

## Features of the Program
- **Player Status Tracking**: Dynamic health, money, and luck stats with condition labels (Healthy/Wounded).
- **Item System**: Collect items with rarity and weight, manage inventory with sorting and searching.
- **Combat System**: Turn-based fights against enemies.
- **Random Events**: Chance-based events that can affect health, money, or luck.
- **Room Exploration**: Navigate linked rooms with actions like searching or leaving.
- **Shop System**: Buy and sell items.
- **Save/Load System**: Persist game state to a file.
- **Survival Bonuses**: Luck increases over time for better event outcomes.

## Data Structures Used
- **std::vector**: Used for storing items in inventory and enemies/items in rooms.
- **LinkedList**: Custom linked list for managing room sequences.
- **std::string**: For names, descriptions, and text data.
- **std::shared_ptr**: For node management in the linked list.

## Algorithms Used
- **Bubble Sort**: Implemented in the Inventory class for sorting items by name.
- **Linear Search**: Used in the Inventory class for searching items by name.
- **Random Number Generation**: For event outcomes and loot.

## Names of Contributors
- Carlos Vega
- Esteban Mora
- Andreas Hitt

Source: Esteban & Copilot
Modified by: Esteban Mora
Changes: added Readme.md
