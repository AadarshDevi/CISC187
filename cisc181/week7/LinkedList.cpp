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

    void insertBack(int value);

    bool insertAfter(int target, int value);

    bool remove(int value);

    ~LinkedList();
};

int main() {
    return 0;
}
