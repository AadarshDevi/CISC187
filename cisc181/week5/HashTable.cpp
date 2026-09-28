//
// Created by CryosArtic on 9/27/2026.
//

#include <iostream>
#include <vector>


int hashFunction(int, int);
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


int main() {
    HashTable hash_table(10);

    std::cout << "Hash: " << hash_table.hashFunction(555223, hash_table.getSize()) << "\n";
    std::cout << "Hash: " << hash_table.hashFunction(555980, hash_table.getSize()) << "\n";
    std::cout << "Hash: " << hash_table.hashFunction(555000, hash_table.getSize()) << "\n";
    std::cout << "Hash: " << hash_table.hashFunction(555890, hash_table.getSize()) << "\n";

    std::cout << "\n";
    return 0;
}
