//
// Created by CryosArtic on 10/1/2026.
//

#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    static const int CAPACITY = 10;

    int data[CAPACITY];
    int topIndex;

public:
    Stack() {
        topIndex = -1; // it means the stack is empty
    }

    bool empty() const {
        return topIndex == -1; // this means there is nothing in the stack.
    }

    bool full() const {
        return topIndex == (CAPACITY - 1); // max capacity fo stack reached
    }

    int size() const {
        return topIndex + 1; // index starts at 0 so 1 has to be added
    }

    void push(int value) {
        if (full()) throw std::overflow_error("Stack Overflow"); // full stack
        topIndex++; // increment index to get new index
        data[topIndex] = value; // set value to the new empty index
    }

    int pop() {
        if (empty()) throw std::underflow_error("Stack Underflow"); // empty stack
        int value = data[topIndex]; // get top value
        topIndex--; // decrement to the new top value
        return value;
    }

    // also called peek
    int top() const {
        if (empty()) throw std::underflow_error("Stack Underflow"); // empty stack
        return data[topIndex]; // return top item without changing stack
    }
};

int main() {
    Stack stack;

    // Add 5 items
    cout << "Before: " << stack.size() << "\n";
    for (int i = 0; i < 5; i++) {
        stack.push(i + 1);
        cout << stack.size() << "\n";
    }

    // Get the last item
    std::cout << "\nTop: " << stack.top() << "\n";
    std::cout << "Size: " << stack.size() << "\n";

    // Remove 11 items
    cout << "\nBefore Removing: " << stack.size() << "\n";
    for (int i = 3; i > 0; i--) {
        stack.pop();
        cout << stack.size() << "\n";
    }

    // Get the last item
    std::cout << "\nTop: " << stack.top() << "\n";
    std::cout << "Size: " << stack.size() << "\n";

    // Remove 11 items
    cout << "\nBefore Removing: " << stack.size() << "\n";
    for (int i = 2; i > 0; i--) {
        stack.pop();
        cout << stack.size() << "\n";
    }

    // Get the last item
    std::cout << "\nTop: " << stack.top() << "\n";
    std::cout << "Size: " << stack.size() << "\n";

    return 0;
}
