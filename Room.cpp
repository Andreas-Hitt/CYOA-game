/*
Author: Andreas Hitt & Gemini
Class: Room
Description: room data storage with dynamic descriptions.
*/
#include "Room.h"

Room::Room(std::string n, std::string d, std::vector<std::string> a, Item i) 
    : name(n), description(d), actions(a), item(i), searched(false) {}

std::string Room::toString() const {
    std::string output = "\nLocation: " + name + "\n";
    if (searched) {
        output += "[!] This room has been ransacked. " + description + "\n";
    } else {
        output += description + "\n";
    }
    return output;
}