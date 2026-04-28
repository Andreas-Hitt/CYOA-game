#include "LinkedList.h"

// Add a new room node to the end of the linked list.
void LinkedList::addRoom(const Room& room) {
    auto newNode = std::make_shared<Node>(room);
    if (!head) {
        head = newNode;
    } else {
        auto current = head;
        while (current->next) {
            current = current->next;  
        }
        current->next = newNode;
    }
}