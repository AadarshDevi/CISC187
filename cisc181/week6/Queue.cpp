//
// Created by CryosArtic on 10/1/2026.
//

#include <stdexcept>

class Queue {
private:
    const int CAPACITY = 10;
    int queue[CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

public:
    void enqueue(int item);
    Queue() {
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }


    void dequeue();

    void front();

    void empty();

    void full();

    void size();
};
