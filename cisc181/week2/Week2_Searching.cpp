#include <iostream>
#include <vector>

int linear_search(int search_num, std::vector<int> &vec);

void print_search(int search_num_i, int search_num_i1);

int main() {
    std::cout << "Hello World!\n";

    std::vector<int> vec = {2, 4, 6, 8, 10, 12, 13};

    return 0;
}

int linear_search(int search_num, std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == search_num) {
            return i;
        }
    }
    return -1;
}

void print_search(int num, int num_index) {
    std::cout << "Number " << num << " @ index " << num_index << ".\n";
}
