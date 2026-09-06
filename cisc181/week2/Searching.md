# Week 2 - Searching

## Table of Contents

1. Linear Search
2. Binary Search

## Linear Search

A linear search is a search algorithm where the entire array is searched from the first item to the last one after
another. The first item in the array will have a time complexity of `O(1)`. The rest of the items will have a time
complexity of `O(N)`.

```terminaloutput
Best Case: O(1)
Average Case: O(N)
```

The array will have the data:

```c++
const int ARRAY_SIZE = 7;
int arr[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 13};
```

Searching the array is linear, just like it's name.

```c++
// *arr used instead of arr so the data in arr will not be duplicated in memeory
int linear_search(int search_num, int *arr, const int ARRAY_SIZE) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == search_num) {
            return i;
        }
    }
    return -1;
}
```

When we try to find 2, we see that the index for it is 0, the first item. this gives the time complexity `O(1)`. For the
numbers 18 and 13, the indices are -1 and 6. Number 13 is the last item on the array so its complexity is `O(N)`
while the number 18 doesn't appear in the array. So the index for 18 is -1, number not found.

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
Binary Search doesn't search each item in the array, instead it takes chunks of data and checks it.

It starts by getting the middle value in the array and checks if the value there is the value needed. If the value is
before the middle data, the data in the latter section of the array is ignored. If the data is after the middle value,
the former section of the array is ignored. This will continue to reduce the searchable array. If the value is found, it
will return the index of the item. if it doesn't find the value, it returns -1, value not found.

```terminaloutput
Best Case: O(1)
Average Case: O(log N)
```

The array will have the data:

```c++
const int ARRAY_SIZE = 7;
int arr[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 13};
```

Each iteration of binary search reduces the searchable indices of the array by half.

I am trying to understand time complexity so the explanation is below code output.

and the code for Binary Search:

```c++
// *arr used instead of arr so the data in arr will not be duplicated in memeory
int binary_search(int search_num, int *arr, const int ARRAY_SIZE) {
    int start_i = 0;
    int end_i = ARRAY_SIZE - 1;
    int mid_i = -1;
    int mid_num = -1;

    while (start_i <= end_i) {
        mid_i = (start_i + end_i) / 2;
        mid_num = arr[mid_i];

        if (search_num == mid_num) {
            return mid_i;
        }

        if (search_num < mid_num) {
            end_i = mid_i - 1;
        } else if (search_num > mid_num) {
            start_i = mid_i + 1;
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

> [!NOTE]
> I had a hard time understanding time complexity. The math below helped me understand it better. I used a video that
did math proof for time complexity of binary search.

> [Source 6](#sources)

Here with the help of **_Source #6_**, I am going to try my best to explain the Time Complexity of Binary Search.

At the start we have the entire dataset. The dataset has n values. When we iterate through the dataset, we reduce the
dataset by half.

So our array holds 7 values, Number of values:

$$N = 7$$

In each iteration, we reduce the dataset by half

$$\frac{n}{2} = \frac{n}{2^{1}}$$
$$\frac{n}{4} = \frac{n}{2^{2}}$$
$$...$$

This dataset will be reduced by half till the range of the dataset is 1. We are reducing the dataset by powers of 2. Let
the number of iterations be _k_.

$$\frac{n}{2^{k}} = 1$$

We do math

$$n = 2^{k}$$

because we are using a base of 2, our log will have the same base.

$$\log_2{n} = log_2{2^{k}}$$
$$\log_2{n} = k$$
$$\because{\log_2{2}} = 1$$

This is why the time complexity of Binary Search is
$$O (\log{n})$$

## Sources

1. [C++ Pass Structures to a Function](https://www.w3schools.com/cpp/cpp_function_structures.asp) - How to send arrays
   as arguments to a function
2. [Linear Search Algorithm by GeeksForGeeks](https://www.geeksforgeeks.org/dsa/linear-search/) - Used for learning
   about it's time complexity.
3. [DSA Linear Search by W3Schools](https://www.w3schools.com/dsa/dsa_algo_linearsearch.php) - Used for the search
   simulator and how does Linear Search work.
4. [Binary Search by GeeksForGeeks](https://www.geeksforgeeks.org/dsa/binary-search/) - How to write Binary Search
5. [Time and Space Complexity Analysis of Binary Search Algorithm by GeeksForGeeks](https://www.geeksforgeeks.org/dsa/complexity-analysis-of-binary-search/) -
   Learning the Time Complexity of Binary Search?
6. [Binary Search time complexity || O (log n) Mathematical Proof by SWE HQ](https://www.youtube.com/watch?v=lv6RPAFP_UU) -
   Video proofing the time complexity of binary search is `O(log(n))`