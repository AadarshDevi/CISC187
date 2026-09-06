#include <iostream>
#include <vector>

int linear_search(int search_num, std::vector<int> &vec);

int binary_search(int search_num, std::vector<int> &vec);

void print_search(int search_num_i, int search_num_i1);

int main() {
    std::vector<int> vec = {2, 4, 6, 8, 10, 12, 13};

    // Linear Search
    std::cout << "Linear Search\n";
    std::cout << "-----------------------\n";
    std::cout << "vector:";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << " " << vec[i];
    }
    std::cout << "\n\n";

    int search_num = 2;
    int search_num_i = linear_search(search_num, vec);
    print_search(search_num, search_num_i);

    search_num = 18;
    search_num_i = linear_search(search_num, vec);
    print_search(search_num, search_num_i);

    search_num = 13;
    search_num_i = linear_search(search_num, vec);
    print_search(search_num, search_num_i);

    // Binary Search
    std::cout << "\n\nBinary Search\n";
    std::cout << "-----------------------\n";
    std::cout << "vector:";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << " " << vec[i];
    }
    std::cout << "\n\n";

    search_num = 2;
    search_num_i = binary_search(search_num, vec);
    print_search(search_num, search_num_i);

    search_num = 18;
    search_num_i = binary_search(search_num, vec);
    print_search(search_num, search_num_i);

    search_num = 13;
    search_num_i = binary_search(search_num, vec);
    print_search(search_num, search_num_i);

    return 0;
}

int binary_search(int search_num, std::vector<int> &vec) {
    int start_i = 0;
    int end_i = vec.size() - 1;
    int mid_i = start_i + ((start_i + end_i) / 2);

    while (start_i < end_i) {
        int start_num = vec[start_i];
        int end_num = vec[end_i];
        int mid_num = vec[mid_i];

        std::cout << "s:m:e - " << start_num << ":" << mid_num << ":" << end_num << "\n";

        if (search_num > mid_num) {
            start_i = mid_i + 1;
        } else if (search_num < mid_num) {
            end_i = mid_i - 1;
        } else if (search_num == mid_num) {
            return mid_i;
        }

        mid_i = start_i + (start_i + end_i) / 2;
    }
    std::cout << "i: " << mid_i << "\n";
    return -1;
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
