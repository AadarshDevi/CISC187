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

    void printLogicalQueue() {
        std::cout << "Logical Queue:" << "\t";
        for (int i = 0; i < CAPACITY; i++) {
            std::cout << queue[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Queue queue;
    std::cout << "\nBefore Adding Items\n";
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(10);
    queue.printInfo();
    queue.printLogicalQueue();

    queue.dequeue();
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(20);
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(30);
    queue.printInfo();
    queue.printLogicalQueue();

    queue.dequeue();
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(40);
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(50);
    queue.printInfo();
    queue.printLogicalQueue();

    queue.dequeue();
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(60);
    queue.printInfo();
    queue.printLogicalQueue();

    queue.enqueue(70);
    queue.printInfo();
    queue.printLogicalQueue();

    return 0;
}

// <, , , , , >
// <10, 20, 22, , , >
// F           R
// <  ,   , 22, , , >
//          F  R
// <  ,   ,   , , , >
//            FR
