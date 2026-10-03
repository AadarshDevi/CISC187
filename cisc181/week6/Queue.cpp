//
// Created by CryosArtic on 10/1/2026.
//

class Queue {
private:
    const int CAPACITY = 10;
    int queue[CAPACITY];
    int frontIndex;
    int rearIndex;
    int count;

public:
    void enqueue(int item);

    void dequeue();

    void front();

    void empty();

    void full();

    void size();
};
