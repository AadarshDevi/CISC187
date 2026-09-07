#include <iostream>

int linear_search(int search_num, int *arr, const int ARRAY_SIZE, int *comparisons);

int linear_search(int search_num, int *arr, const int ARRAY_SIZE);

int binary_search(int search_num, int *arr, const int ARRAY_SIZE, int *comparisons);

int binary_search(int search_num, int *arr, const int ARRAY_SIZE);

void print_search(int num, int num_index);

int main() {
    const int ARRAY_SIZE = 7;
    int arr[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 13};

    // Linear Search
    std::cout << "\nSearching\n";
    std::cout << "-----------------------\n";
    std::cout << "array:";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << "\n\n";

    int search_num = -1;
    int search_num_i = -1;

    search_num = 8;
    search_num_i = linear_search(search_num, arr, ARRAY_SIZE);
    std::cout << "Linear Search -> ";
    print_search(search_num, search_num_i);
    search_num_i = binary_search(search_num, arr, ARRAY_SIZE);
    std::cout << "Binary Search -> ";
    print_search(search_num, search_num_i);
    std::cout << "\n";

    search_num = 13;
    search_num_i = linear_search(search_num, arr, ARRAY_SIZE);
    std::cout << "Linear Search -> ";
    print_search(search_num, search_num_i);
    std::cout << "Binary Search -> ";
    search_num_i = binary_search(search_num, arr, ARRAY_SIZE);
    print_search(search_num, search_num_i);
    std::cout << "\n";


    search_num = 18;
    search_num_i = linear_search(search_num, arr, ARRAY_SIZE);
    std::cout << "Linear Search -> ";
    print_search(search_num, search_num_i);
    search_num_i = binary_search(search_num, arr, ARRAY_SIZE);
    std::cout << "Binary Search -> ";
    print_search(search_num, search_num_i);
    std::cout << "\n";

    // create array
    const int ARRAY_SIZE_2 = 100'000;
    int arr_2[ARRAY_SIZE];

    // populate array
    for (int i = 1; i <= ARRAY_SIZE_2; i++) {
        arr_2[i - 1] = i;
    }

    // vars needed to search for vars
    int num = 103'302;
    int comparisons = 0;
    int num_i = 0;

    // search array
    num_i = linear_search(num, arr_2, ARRAY_SIZE_2, &comparisons);
    std::cout << "Linear Search: " << num
            << " at index: " << num_i
            << " with iterations: " << comparisons
            << "\n";

    comparisons = 0;
    num_i = binary_search(num, arr_2, ARRAY_SIZE_2, &comparisons);
    std::cout
            << "Binary Search: " << num
            << " at index: " << num_i
            << " with iterations: " << comparisons
            << "\n";

    return 0;
}

int binary_search(int search_num, int *arr, const int ARRAY_SIZE, int *comparisons) {
    int start_i = 0;
    int end_i = ARRAY_SIZE - 1;
    int mid_i = -1;
    int mid_num = -1;

    while (start_i <= end_i) {
        mid_i = (start_i + end_i) / 2;
        mid_num = arr[mid_i];

        (*comparisons)++;
        if (search_num == mid_num) {
            return mid_i;
        } else if (search_num < mid_num) {
            end_i = mid_i - 1;
        } else if (search_num > mid_num) {
            start_i = mid_i + 1;
        }
    }
    return -1;
}

int linear_search(int search_num, int *arr, const int ARRAY_SIZE, int *comparisons) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        (*comparisons)++;
        if (arr[i] == search_num) {
            return i;
        }
    }
    return -1;
}

int linear_search(int search_num, int *arr, const int ARRAY_SIZE) {
    int comparisons = 0;
    return linear_search(search_num, arr, ARRAY_SIZE, &comparisons);
}

int binary_search(int search_num, int *arr, const int ARRAY_SIZE) {
    int comparisons = 0;
    return binary_search(search_num, arr, ARRAY_SIZE, &comparisons);
}

void print_search(int num, int num_index) {
    std::cout << "Number " << num << " @ index " << num_index << ".\n";
}
