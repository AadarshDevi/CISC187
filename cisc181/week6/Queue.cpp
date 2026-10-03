//
// Created by CryosArtic on 10/1/2026.
//

#include <stdexcept>

class Queue {
private:
    int CAPACITY;
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

    Queue(int capacity) {
        if (capacity <= 0) throw std::invalid_argument("Capcaity cannot be less than or equal to 0.");
        CAPACITY = capacity;
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
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

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count >= this->CAPACITY;
    }

    int size() const {
        return count;
    }
};
