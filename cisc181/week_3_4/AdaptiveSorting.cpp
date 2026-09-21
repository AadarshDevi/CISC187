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
    std::cout << "There are " << unsortedElements << " elements that are unsorted\n\n";

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    selectionSort(array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

/*
 * Broken
 */
void selectionSort(int *array, int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int currentI = i;
        int newI = i + 1;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[newI] < array[currentI]) {
                newI = j;
            }
        }

        int temp = array[currentI];
        array[currentI] = array[newI];
        array[newI] = temp;
    }
}
