#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include "Room.h"

class Node {
public:
    Room room;
    std::shared_ptr<Node> next;
    Node(Room r) : room(r), next(nullptr) {}
};

class LinkedList {
private:
    std::shared_ptr<Node> head;
public:
    LinkedList() : head(nullptr) {}
    void addRoom(const Room& room);
    std::shared_ptr<Node> getHead() const { return head; }
};

#endif