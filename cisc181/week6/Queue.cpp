//
// Created by CryosArtic on 10/1/2026.
//

#include <iostream>
#include <stdexcept>

class Queue {
private:
    static constexpr int CAPACITY = 5;
    int queue[CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

    inline int nextIndex(int index) const {
        return (index + 1) % this->CAPACITY;
    }

public:
    Queue() {
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count >= this->CAPACITY;
    }

    int size() const {
        return count;
    }

    void enqueue(int item) {
        if (full()) throw std::overflow_error("Queue Overflow");
        queue[rearIndex] = item;
        rearIndex = nextIndex(rearIndex);
        count++;
    }

    int dequeue() {
        if (empty()) throw std::underflow_error("Queue Underflow");
        const int item = queue[frontIndex];
        frontIndex = nextIndex(frontIndex);
        count--;
        return item;
    }

    int front() const {
        if (empty()) throw std::underflow_error("Queue Underflow");
        return queue[frontIndex];
    }

    void printInfo() {
        std::cout << "Queue Information" << "\n";
        std::cout << "----------------------" << "\n";
        std::cout << "Front Index: " << frontIndex << "\n";
        std::cout << "Rear Index: " << rearIndex << "\n";
        std::cout << "Size: " << size() << "\n";
        std::cout << "Count: " << count << "\n\n";
    }
};

int main() {
    Queue queue;
    std::cout << "\nBefore Adding Items\n";
    queue.printInfo();

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    std::cout << "After Adding Items\n";
    queue.printInfo();

    while (!queue.empty()) {
        queue.dequeue();
    }

    std::cout << "Attempting Underflow Error\n";
    try {
        queue.dequeue();
    } catch (std::underflow_error const &e) {
        std::cout << " >> Error: " << e.what() << "\n";
    }

    return 0;
}

// <, , , , , >
// <10, 20, 22, , , >
// F           R
// <  ,   , 22, , , >
//          F  R
// <  ,   ,   , , , >
//            FR
