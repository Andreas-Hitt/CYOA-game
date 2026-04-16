#include "LinkedList.h"

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