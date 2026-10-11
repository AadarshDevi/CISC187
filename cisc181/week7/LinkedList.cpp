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

    bool empty() const;

    void display() const;

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
