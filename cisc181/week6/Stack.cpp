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
    // 1. empty stack - default size = 10 items
    Stack stack;

    // 2. is stack empty
    std::cout << "2. Stack Empty? " << stack.empty() << "\n";

    // 3. push 5 values
    for (int i = 0; i < 5; i++) {
        stack.push((i + 1) * 10);
    }

    // 4. display current stack size
    std::cout << "\n4. Stack Size: " << stack.size() << "\n";

    // 5. display current top value
    std::cout << "\n5. Top Value: " << stack.top() << "\n";

    // 6. pop 2 values
    for (int i = 0; i < 2; i++) {
        stack.pop();
    }

    // 7.1. display current top
    std::cout << "\n7.1. Top Value: " << stack.top() << "\n";

    // 7.2. display current stack size
    std::cout << "\n7.2. Stack Size: " << stack.size() << "\n";

    // 8. remove all items via pop
    while (!stack.empty()) {
        stack.pop();
    }

    // 9. display underflow handling - pop @ (size = 0)
    try {
        stack.pop();
    } catch (std::underflow_error e) {
        std::cout << e.what() << "\n";
    }


    // 10. fill up stack
    while (!stack.full()) {
        stack.push(stack.size() + 1);
    }

    // 11. overflow handling - push @ (size = 10)
    try {
        stack.push(stack.size() + 1);
    } catch (std::overflow_error e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}


/*

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
 */
