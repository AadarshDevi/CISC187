#include <iostream>
#include <vector>


void print_search(int search_num_i, int search_num_i1);

int main() {
    std::cout << "Hello World!\n";

    std::vector<int> vec = {2, 4, 6, 8, 10, 12, 13};

    return 0;
}


void print_search(int num, int num_index) {
    std::cout << "Number " << num << " @ index " << num_index << ".\n";
}
