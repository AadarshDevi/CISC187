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

        for (int i = 0; i < this->CAPACITY; i++) {
            queue[i] = -1;
        }
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
        queue[frontIndex] = -1;
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
        std::cout << "Count: " << count << "\n\n";
    }

    void printPhysicalQueue() {
        std::cout << "Physical Queue:" << "\t";
        for (int i = 0; i < CAPACITY; i++) {
            if (queue[i] == -1) {
                std::cout << "__" << " ";
                continue;
            }
            std::cout << queue[i] << " ";
        }
        std::cout << "\n";
    }

    void printLogicalQueue() {
        std::cout << "Logical Queue:" << "\t";
        for (int i = 0; i < CAPACITY; i++) {
            int index = nextIndex(frontIndex + i - 1);
            const int value = queue[index];
            if (value == -1) continue;
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    // empty queue
    Queue queue;
    queue.printPhysicalQueue();
    queue.printLogicalQueue();

    // multiple enqueue operations
    queue.enqueue(10);
    queue.printPhysicalQueue();

    queue.enqueue(20);
    queue.printPhysicalQueue();

    queue.enqueue(30);
    queue.printPhysicalQueue();

    queue.enqueue(40);
    queue.printPhysicalQueue();

    queue.enqueue(50);
    queue.printPhysicalQueue();

    // FIFO removal order
    queue.printLogicalQueue();

    // front()
    std::cout << "First Item: " << queue.front() << "\n";

    // size()
    std::cout << "Size: " << queue.size() << "\n";

    // multiple dequeue operations
    queue.dequeue();
    queue.printPhysicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    queue.printLogicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    // circular wrap around
    queue.enqueue(60);
    queue.printPhysicalQueue();

    queue.enqueue(70);
    queue.printPhysicalQueue();

    queue.enqueue(80);
    queue.printPhysicalQueue();

    queue.enqueue(90);
    queue.printPhysicalQueue();

    // Queue Overflow Error
    try {
        queue.enqueue(100);
        queue.printPhysicalQueue();
    } catch (std::overflow_error const &e) {
        std::cout << "Attempting Overflow Error: " << e.what() << "\n";
    }

    // Dequeue Operations
    queue.dequeue();
    queue.printPhysicalQueue();

    queue.printLogicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    queue.dequeue();
    queue.printPhysicalQueue();

    try {
        queue.dequeue();
        queue.printPhysicalQueue();
    } catch (std::underflow_error const &e) {
        std::cout << "Attempting Underflow Error: " << e.what() << "\n";
    }

    return 0;
}
