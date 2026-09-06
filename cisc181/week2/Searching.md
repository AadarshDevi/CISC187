# Week 2 - Searching

## Table of Contents

## Linear Search

A linear search is a search algorithm where the entire array is searched from the first item to the last one after
another. The first item in the array will have a time complexity of `O(1)`. The rest of the items will have a time
complexity of `O(N)`.

```c++
std::vector<int> vec = {2, 4, 6, 8, 10, 12, 13};
```

```c++
int linear_search(int search_num, std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == search_num) {
            return i;
        }
    }
    return -1;
}
```


```terminaloutput
Number 2 @ index 0.
Number 18 @ index -1.
Number 13 @ index 6.
```

## Sources

1. [C++ Vectors](https://www.w3schools.com/cpp/cpp_vectors.asp) - Working with C++ Vectors
2. [Linear Search Algorithm](https://www.geeksforgeeks.org/dsa/linear-search/) - Used for learning about it's time
   complexity.
3. [DSA Linear Search](https://www.w3schools.com/dsa/dsa_algo_linearsearch.php) - Used for the search simulator and how
   does Linear Search work.