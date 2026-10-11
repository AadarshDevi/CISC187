//
// Created by CryosArtic on 10/11/2026.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    }

    bool empty() const {
        return head == nullptr;
    }

    void display() const {
        // check if the list is empty
        if (empty()) {
            std::cout << "Linked List is Empty\n";
            return;
        }

        // a node to hold the pointers for the next value
        Node *current = head;

        // loop over each item in the list
        while (current != nullptr) {
            // print out the value
            std::cout << current->data << " ";

            // go to the next node
            current = current->next;
        }
        std::cout << "\n";
    }

    bool search(int value) const {
        // check if list is empty
        if (empty()) {
            return false;
        }

        // pointer to the first node
        Node *current = head;

        // go through each node to check if the value exists
        while (current != nullptr) {
            if (current->data == value) {
                // value found
                return true;
            }
            current = current->next;
        }

        // value not found
        return false;
    }

    void insertFront(int value) {
        // check if empty
        if (empty()) {
            Node *node = new Node{value, nullptr};
            head = node;
            return;
        }

        // get the first node of the list
        Node *firstNode = head;

        // create a new node that points to the first node
        Node *newNode = new Node{value, firstNode};

        // head points to new node (not first node)
        head = newNode;
    }

    void insertBack(int value) {
        // check if list is empty
        if (empty()) {
            Node *node = new Node{value, head};
            head = node;
            return;
        }

        // create new last node
        Node *node = new Node{value, nullptr};

        // check if the list has a single node
        if (head->next == nullptr) {
            head->next = node;
            return;
        }

        // find the last node
        Node *lastNode = head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }

        // set the last node to point at the new node
        lastNode->next = node;
    }

    bool insertAfter(int target, int value) {
        // node cannot be inserted after a value in an empty list
        if (empty()) return false;

        // find target node
        Node *targetNode = head;

        while (targetNode != nullptr) {
            if (targetNode->data == target) {
                break;
            }
            targetNode = targetNode->next;
        }

        if (targetNode == nullptr) return false;

        // get target's old next pointer
        Node *oldNext = targetNode->next;

        // create a new node with the pointer to the target's old next pointer
        Node *newNode = new Node{value, oldNext};

        // target node points to new node
        targetNode->next = newNode;

        // node inserted successfully
        return true;
    }

    bool remove(int value) {
        // list is empty
        if (empty()) return false;

        // keep track of current and previous node
        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr) {
            // node with the value to be removed found
            if (current->data != value) {
                previous = current; // current node is now previous node
                current = current->next; // the next node is the current node
                continue;
            }

            // the node that has the value is not connected to the list anymore
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            // delete current
            delete current;
            return true;
        }

        return false;
    }

    ~LinkedList() {
        // get start of the node
        Node *current = head;

        // loop through list
        while (current != nullptr) {
            // get next node
            Node *next = current->next;

            // delete current node
            delete current;

            // current node is next node
            current = next;
        }

        // make head point to nothing
        head = nullptr;
    }
};

int main() {
    // 1. Create an empty list
    LinkedList list = LinkedList();

    // 2. Verify that it is empty
    list.display();

    // 3. Insert several values at the front
    for (int i = 1; i < 6; i++) {
        list.insertFront(i * 10 * 3 / 2);
    }

    // 4. Insert several values at the back
    for (int i = 1; i < 6; i++) {
        list.insertBack(i * 10 * 5 / 2);
    }

    // 5. Display the list
    list.display();

    // 6. Search for existing and missing values
    std::cout << "Item Found: 45 ? " << (list.search(45) ? "true" : "false") << "\n";
    std::cout << "Item Found: 10 ? " << (list.search(10) ? "true" : "false") << "\n";

    // 7. Insert after a value in the middle
    std::cout << "Inserted Value: 15 -> 230 ? " << (list.insertAfter(15, 230) ? "true" : "false") << "\n";

    // 8. Attempt insertion after a nonexistent value
    std::cout << "Inserted Value: 120 -> 40 ? " << (list.insertAfter(120, 40) ? "true" : "false") << "\n";

    // 9. Remove the first node
    std::cout << "Removed Value: 75 ? " << (list.remove(75) ? "true" : "false") << "\n";

    // 10. Remove a middle node
    std::cout << "Removed Value: 230 ? " << (list.remove(230) ? "true" : "false") << "\n";

    // 11. Remove the last node
    std::cout << "Removed Value: 125 ? " << (list.remove(125) ? "true" : "false") << "\n";

    // 12. Attempt to remove a nonexistent value
    std::cout << "Removed Value: 1192 ? " << (list.remove(1192) ? "true" : "false") << "\n";

    // 13. Display the final list
    list.display();

    return 0;
}
