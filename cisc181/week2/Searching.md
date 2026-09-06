# Week 2 - Searching

## Table of Contents

## Linear Search

A linear search is a search algorithm where the entire array is searched from the first item to the last one after
another. The first item in the array will have a time complexity of `O(1)`. The rest of the items will have a time
complexity of `O(N)`.

```terminaloutput
Best Case: O(1)
Average Case: O(N)
```

The vector will have the data:

```c++
std::vector<int> vec = {2, 4, 6, 8, 10, 12, 13};
```

Searching the vector is linear, just like it's name.

```c++
int linear_search(int search_num, std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) == search_num) {
            return i;
        }
    }
    return -1;
}
```

When we try to find 2, we see that the index for it is 0, the first item. this gives the time complexity `O(1)`. For the
numbers 18 and 13, the indices are -1 and 6. Number 13 is the last item on the vector so its complexity is `O(N)`
while the number 18 doesn't appear in the vector. So the index for 18 is -1, number not found.

For the number 2, the algorithm will check the first item and see that it is the value needed. So it will give the index
of the value 2, 0. For 18, It will loop through every item till the end. Since it didn't find the value 18, it will
return -1, item/value not found. for the value 13, the algorithm will go through every single item till the last where
it will find it.

```terminaloutput
Number 2 @ index 0.
Number 18 @ index -1.
Number 13 @ index 6.
```

## Binary Search

Binary Search is a searching algorithm with a time complexity of `O(log(n))`. It is usually used on data that is sorted.
Binary Search doesn't search each item in the vector, instead it takes chunks of data and checks it.

```terminaloutput
Best Case: O(1)
Average Case: O(log N)
```

## Sources

1. [C++ Vectors by W3Schools](https://www.w3schools.com/cpp/cpp_vectors.asp) - Working with C++ Vectors
2. [Linear Search Algorithm by GeeksForGeeks](https://www.geeksforgeeks.org/dsa/linear-search/) - Used for learning
   about it's time complexity.
3. [DSA Linear Search by W3Schools](https://www.w3schools.com/dsa/dsa_algo_linearsearch.php) - Used for the search
   simulator and how does Linear Search work.
4. [Binary Search by GeeksForGeeks](https://www.geeksforgeeks.org/dsa/binary-search/) - How to write Binary Search
5. [Time and Space Complexity Analysis of Binary Search Algorithm by GeeksForGeeks](https://www.geeksforgeeks.org/dsa/complexity-analysis-of-binary-search/) -
   What is the Time Complexity of Binary Search why is it?