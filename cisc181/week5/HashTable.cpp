//
// Created by CryosArtic on 9/27/2026.
//

#include <iostream>
#include <cmath>

int hashFunction(int, int);

int main() {
    hashFunction(555223, 10);
    hashFunction(555980, 10);
    hashFunction(555000, 10);
    hashFunction(555890, 10);

    std::cout << "\n";
    return 0;
}

int hashFunction(int key, int tableSize) {
    int lastNum = 0;
    int sum = 0;
    // std::cout << lastNum << '\n';
    for (int i = 1; i < 10; i++) {
        int remainder = (key % (int) pow(10, i));
        std::cout << "rem: " << remainder;

        int value = remainder - lastNum;
        std::cout << ", val: " << value;

        int digit = value / pow(10, i - 1);
        std::cout << ", ext: " << digit;

        lastNum = remainder;
        std::cout << ", last: " << lastNum << '\n';

        sum += digit;
    }
    std::cout << "Sum: " << sum << "\n\n";

    return 0;
}
