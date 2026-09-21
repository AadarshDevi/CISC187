//
// Created by CryosArtic on 9/20/2026.
//
#include <random>
#include <algorithm>
#include <iostream>
#include <ostream>

int main() {
    // create array
    const int ARRAY_SIZE = 50;
    int array[ARRAY_SIZE];

    // populate array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // print array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    // unsort array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(array, array + ARRAY_SIZE, gen);

    // print array
    int unsortedElements = 0;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        if (array[i] > array[i + 1]) unsortedElements++;
    }

    // how much sorted?
    std::cout << "There are " << unsortedElements << " elements that are unsorted";
}
