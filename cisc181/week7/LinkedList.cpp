//
// Created by CryosArtic on 10/11/2026.
//

struct Node {
    int data;
    Node *next;
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
