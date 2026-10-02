//
// Created by CryosArtic on 10/1/2026.
//

class Queue {
public:
    void enqueue();

    void dequeue();

    void front();

    void empty();

    void full();

    void size();

private:
    const int CAPACITY = 10;
    int queue[CAPACITY];

};
