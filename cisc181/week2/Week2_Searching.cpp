#include <iostream>

int linear_search(int search_num, int *arr, int ARRAY_SIZE, int *comparisons);

int main() {
    // create array
    const int ARRAY_SIZE = 100'000;
    int arr[ARRAY_SIZE];

    // populate array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }

    return 0;
}

int binary_search(int search_num, int *arr, const int ARRAY_SIZE) {
    int start_i = 0;
    int end_i = ARRAY_SIZE - 1;
    int mid_i = -1;
    int mid_num = -1;
    int iterations = 0;

    while (start_i <= end_i) {
        iterations++;
        mid_i = (start_i + end_i) / 2;
        mid_num = arr[mid_i];

        if (search_num == mid_num) {
            std::cout << "Iterations: " << iterations << "\n";
            return mid_i;
        }

        if (search_num < mid_num) {
            end_i = mid_i - 1;
        } else if (search_num > mid_num) {
            start_i = mid_i + 1;
        }
    }
    std::cout << "Iterations: " << iterations << "\n";
    return -1;
}

int linear_search(int search_num, int *arr, int ARRAY_SIZE, int *comparisons) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        (*comparisons)++;
        if (arr[i] == search_num) {
            return i;
        }
    }
    return -1;
}

void print_search(int num, int num_index) {
    std::cout << "Number " << num << " @ index " << num_index << ".\n";
}

/*
const int ARRAY_SIZE = 7;
    int arr[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 13};

    // Linear Search
    std::cout << "Linear Search\n";
    std::cout << "-----------------------\n";
    std::cout << "array:";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << "\n\n";

    int search_num = 8;
    int search_num_i = linear_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);

    search_num = 18;
    search_num_i = linear_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);

    search_num = 13;
    search_num_i = linear_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);

    // Binary Search
    std::cout << "\n\nBinary Search\n";
    std::cout << "-----------------------\n";
    std::cout << "array:";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << "\n\n";

    search_num = 2;
    search_num_i = binary_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);

    search_num = 18;
    search_num_i = binary_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);

    search_num = 13;
    search_num_i = binary_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);
 */
