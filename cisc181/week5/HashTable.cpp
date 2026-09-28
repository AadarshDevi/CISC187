//
// Created by CryosArtic on 9/27/2026.
//

#include <iostream>
#include <vector>


int hashFunction(int, int);

int main() {
    std::cout << "Hash: " << hashFunction(555223, 10) << "\n";
    std::cout << "Hash: " << hashFunction(555980, 10) << "\n";
    std::cout << "Hash: " << hashFunction(555000, 10) << "\n";
    std::cout << "Hash: " << hashFunction(555890, 10) << "\n";

    std::cout << "\n";
    return 0;
}

int hashFunction(int key, int tableSize) {
    int digit_sum = 0;
    for (int i = 0; i < INT_MAX; i++) {
        int digit = key % 10; // get last digit
        digit_sum += digit; // add to sum
        key = key / 10; // remove the last digit which is now 0
        if (key == 0) break; // escapes if key = 0
    }
    return digit_sum % tableSize; // index = digital_sum % table_size
}
