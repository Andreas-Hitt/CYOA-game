#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include "Room.h"

// Node stores a room and a pointer to the next list node.
class Node {
public:
    Room room;
    std::shared_ptr<Node> next;
    Node(Room r) : room(r), next(nullptr) {}
};

// Simple singly linked list used to chain rooms together.
class LinkedList {
private:
    std::shared_ptr<Node> head;  // Head pointer for the list.
public:
    LinkedList() : head(nullptr) {}

    // Append a room to the end of the list.
    void addRoom(const Room& room);

    // Get the first node to traverse the list.
    std::shared_ptr<Node> getHead() const { return head; }
};

#endif