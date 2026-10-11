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
    LinkedList();

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


    bool search(int value) const;

    void insertFront(int value);

    void insertBack(int value);

    bool insertAfter(int target, int value);

    bool remove(int value);

    ~LinkedList();
};

int main() {
    Node *first = new Node{7, nullptr};
    Node *second = new Node{7, nullptr};
    Node *third = new Node{7, nullptr};

    Node *head = first;

    first->next = second;
    second->next = third;

    return 0;
}
