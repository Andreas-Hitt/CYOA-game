#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include "Room.h"

// Node is an element in a linked list of rooms.
// It stores a Room object and a pointer to the next node.
class Node {
public:
    Room room;
    std::shared_ptr<Node> next;

    // Create a node that owns the provided room.
    Node(Room r) : room(r), next(nullptr) {}
};

// LinkedList manages a sequence of rooms using shared pointers.
// Rooms can be added to the end of the list.
class LinkedList {
private:
    std::shared_ptr<Node> head;
public:
    LinkedList() : head(nullptr) {}

    // Append a room to the end of the linked list.
    void addRoom(const Room& room);

    // Return the head node of the list for traversal.
    std::shared_ptr<Node> getHead() const { return head; }
};

#endif