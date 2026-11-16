//
// Created by CryosArtic on 11/15/2026.
//

#include <iostream>

void countdown(int i);

void countdownRecursive(int i);

int main() {
    int i = 5;
    countdown(i);
    countdownRecursive(i);
}

static void countdownRecursive(int num) {
    if (num == 0) return;
    std::cout << num << "\n";
    countdownRecursive(num - 1);
}

static void countdown(int num) {
    for (int i = num; i >= 0; i--) {
        std::cout << i << "\n";
    }
}

static int sumTo(int num) {
    if (num == 1) return 1;
    return num + sumTo(num - 1);
}
