# Week 2 - Searching

> [!NOTE]
> This is a long lab doc.

## Table of Contents

1. [Linear Search](#linear-search)
2. [Binary Search](#binary-search)
3. [Binary search on a Large DataSet](#binary-search-on-a-large-dataset)
4. [Searching Dataset](#searching-dataset)
    1. [Linear Search Table](#table-for-linear-search)
    2. [Binary Search Table](#table-for-binary-search)
    3. [Analysis](#analysis)
        1. [Question 1](#question-1)
        2. [Question 2](#question-2)
        3. [Question 3](#question-3)
5.

## Linear Search

A linear search is a search algorithm where the entire array is searched from the first item to the last one after
another. The first item in the array will have a time complexity of `O(1)`. The rest of the items will have a time
complexity of `O(N)`.

$$ \text{Base Case: } O (1)$$
$$ \text{Average of Worst Case: } O (N)$$

To find element 8, we will iterate through the array 4 times.
![linear search.png](linear%20search.png)
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

When we start a linear search, it goes through every single item in the array. When we do linear search on an array with
1 item, the best case it `O(1)` and the iterations is 1.

$$N=1 \quad \because{\text{No of items in array}}$$
$$k=1 \quad \because{\text{No of iterations to find the number}}$$

Let's change it

$$N=10 \quad \because{\text{No of items in array}}$$
$$k=10 \quad \because{\text{No of iterations (worst case) to find the number}}$$

So when we increase the number of items in the array, the longer it will take linear search to find it. The dataset
expands each iteration.

$$N=1 \quad \because{\text{1 item}}$$
$$k=1 \quad \because{\text{1 comparison}}$$

$$N=2 \quad \because{\text{2 item}}$$
$$k=2 \quad \because{\text{2 comparisons}}$$

$$...$$

$$N \quad \because{\text{N item}}$$
$$k=N \quad \because{\text{N comparisons}}$$

So linear search has a time complexity of

$$O (N)$$

## Binary Search

Binary Search is a searching algorithm with a time complexity of `O(log(n))`. It is usually used on data that is sorted.
Binary Search doesn't search each item in the array, instead it takes chunks of data and checks it.

It starts by getting the middle value in the array and checks if the value there is the value needed. If the value is
before the middle data, the data in the latter section of the array is ignored. If the data is after the middle value,
the former section of the array is ignored. This will continue to reduce the searchable array. If the value is found, it
will return the index of the item. if it doesn't find the value, it returns -1, value not found.

$$ \text{Base Case: } O (1)$$
$$ \text{Average of Worst Case: } O (log{N})$$

To find element 8, we will iterate through the array 3 times.
![binary search.png](binary%20search.png)
The array will have the data:

```c++
const int ARRAY_SIZE = 7;
int arr[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 13};
```

Each iteration of binary search reduces the searchable indices of the array by half. I am trying to understand time
complexity so the explanation is below code output. The code for Binary Search:

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

$$n = 2^{k}$$

because we are using a base of 2, our log will have the same base so we can get the number of iterations.

$$\log_2{n} = log_2{2^{k}}$$
$$\log_2{n} = k \quad \because{\log_2{2}} = 1$$

This is why the time complexity of Binary Search is
$$O (\log{n})$$

## Binary search on a Large DataSet

We need to find the maximum iterations that can be done on a sorted dataset with 10,000 elements.

So, let
$$N = 100,000 \text{ elements}$$

and

$$k = \text{The number of iterations}$$

so the max number of iterations needed for this dataset is

$$k = \log_2{N} \quad \because{\text{ Derived previously}} $$
$$k = \log_2{100,000}$$
$$k \approx 16.6096404744 $$

I round it up because we have an iteration or not. So the maximum number of iterations on a dataset with 100,000
elements is

$$k \approx 17 $$

## Searching DataSet

Below I am creating an int array with 100,000 values. They will be sorted and there will not be multiple values of the
same number. The array has the range:

$$Range_{array} = [1, 100,000]$$

```c++
// create array
const int ARRAY_SIZE = 100'000;
int arr[ARRAY_SIZE];

// populate array
for (int i = 1; i <= ARRAY_SIZE; i++) {
    arr[i - 1] = i;
}
```

Next are the variables needed to make the search algorithms work properly.

```c++
// vars needed to search for vars
int num = 1;
int comparisons = 0;
int num_i = 0;
```

Now we have a modified implementation of the Linear Search from before:

```c++
int linear_search(int search_num, int *arr, const int ARRAY_SIZE, int *comparisons) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        (*comparisons)++;
        if (arr[i] == search_num) {
            return i;
        }
    }
    return -1;
}
```

Now we have a modified implementation of the Binary Search from before:

```c++
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
```

Using the output in the format below to find iterations and index of the number.

```terminaloutput
Linear Search: 103302 at index: -1 with iterations: 100000
Binary Search: 103302 at index: -1 with iterations: 17
```

Below is a table for the numbers searched, the iterations it took and if the values were found.

### Table for Linear Search

| Number  | Found | Iterations | Index | Part of the Array |
|:-------:|:-----:|:----------:|:-----:|:-----------------:|
|    1    |  Yes  |     1      |   0   |     Beginning     |
| 100,000 |  Yes  |  100,000   | 99999 |        End        |
| 103,302 |  No   |  100,000   |       |   Out of Range    |

### Table for Binary Search

| Number  | Found | Iterations | Index | Part of the Array |
|:-------:|:-----:|:----------:|:-----:|:-----------------:|
|    1    |  Yes  |     16     |   0   |     Beginning     |
| 100,000 |  Yes  |  100,000   | 99999 |        End        |
| 103,302 |  No   |     17     |  -1   |   Out of Range    |

### Analysis

#### Question 1

Linear Search has worst-case time complexity of `O(N)` because it has to go through every single item in the array. so
if the value is at the end of the array, the entire array has to be searched. The searchable dataset will remain
constant, and it will not change. So the search will have to go through all the values.

#### Question 2

Binary Search has worst-case time complexity of `O(log(N))` because at each iteration, half of the searchable dataset
becomes searchable. This reduction of the dataset give it, it's time complexity.

#### Question 3

Binary Search needs a sorted dataset because binary search use values and compares them with the middle value. Because
the dataset it ordered, the binary search will know that if a value is lower than the middle val, it can logically
deduce that the upper half of the dataset will never contain the data. If the data is unsorted, binary search will think
that the value is below when in reality it is above the middle value. This defeats the purpose of using binary search
because linear search (between linear and binary search) would be a better option. Binary search is efficient when the
data is sorted and linear search can be used regardless if the data is sorted or not.

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
7. Google Gemini - LaTeX Syntax