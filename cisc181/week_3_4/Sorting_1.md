# Week 3/4 - Sorting I

## Table of Contents

1. [Linear Complexity](#linear-complexity)
2. [Quadratic Complexity](#quadratic-complexity)
3. [Analyzing Multiple Sequential Loops](#analyzing-multiple-sequential-loops)
4. [Multiple Constant-Time Operations](#multiple-constant-time-operations)
5. [Analyzing Nested Iteration](#analyzing-nested-iteration)
6. [Analysis & Reflection](#analysis--reflection)
7. [Resources](#resources)

## Linear Complexity

$$\text{Let: } \quad k = \text{No of Steps to sort some Data}$$
$$\text{Let: } \quad N = \text{No of Items in array}$$

When we are comparing items to sort them, the more elements added to the data, the number of comparisons will increase
linearly.

We will use a sorted array as an example.

```c++
int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```

$$N = 10$$

We will take the first item and compare it to the next

$$N (1) = 0 \text{ and } N (2) = 1$$

So, we compare them (to check if they are sorted using Bubble Sort). And after we compare each one of them, there will 9
comparisons. Below are the comparisons

| Comparison |    k    |
|:----------:|:-------:|
|  $0 > 1$   | $k = 1$ |
|  $1 > 2$   | $k = 2$ |
|   $...$    |  $...$  |
|  $7 > 8$   | $k = 8$ |
|  $8 > 9$   | $k = 9$ |

So the number of comparisons needed for a sorted array

$$k = 9$$

In the above example we add 1 comparison when comparing 2 numbers. Below is the question asked:

```
In 4N + 16, Why does the constant and coefficient not affect Big-O Notation?
```

If we chart this equation as a graph, it is similar to the example above. It is a straight line and when numbers are
added to the data, the number of comparisons needed will increase by the same amount.

$$N = 10$$
$$k = 4 (10) + 16 = 56$$

$$N = 20$$
$$k = 4 (20) + 16 = 96$$

For each item added to the data, there will be additional 4 comparisons. Since each number will have 4 comparisons, any
number added after will have the same. This shows that mow many numbers added, the no of comparisons needed to check the
array will increase constantly.

Using the equation:

$$4N + 16$$

There will be at least 16 comparisons even when the array is empty. For each item added, the number of comparisons will
increase by 4.

Apart from the math, Big-O notations ignores numbers as explained in "**Sorting Algorithms > Selection Sort > Efficiency
of Selection Sort**". Big-O notation only takes the highest degree in the function.

So based on that information:

$$4N + 16$$
$$4N \quad\because{\text{16 is a constant}}$$
$$N \quad\because{\text{4 is a constant multiplier}}$$

So this leaves:

$$O (N)$$

TL:DR;

1. Base Comparisons: 16
2. Comparisons for each item: 4
3. Linear Graph
4. Big-O Notation ignores:
    1. constants
    2. constant multipliers
    3. non highest degrees of a function/algorithm

## Quadratic Complexity

The algorithm given has the given time complexity:

$$2N^2$$

First, the $N^2$ tells us that the equations is quadratic. Using the "**Rules of Big O Notations**" we see below that

$$2N^2 \to N^2 \quad\because{\text{2 is a constant multiplier}}$$

When the dataset increases aka becomes very large, the constants and constant multiplier will be less useful.

So below is a table for the number of items and the number of comparisons needed to sort it when the algorithm is$N^2$.

| $N$ | 0 | 1 | 2 | 3 | $...$ | 8  | 9  | 10  |
|:---:|:-:|:-:|:-:|:-:|:-----:|:--:|:--:|:---:|
| $k$ | 0 | 0 | 4 | 9 | $...$ | 64 | 81 | 100 |

It's a quadratic equation. Then $2N^2$ will be twice that of $N^2$.

| $N$ | 0 | 1 | 2 | 3  | $...$ |  8  |  9  | 10  |
|:---:|:-:|:-:|:-:|:--:|:-----:|:---:|:---:|:---:|
| $k$ | 0 | 0 | 8 | 18 | $...$ | 128 | 192 | 200 |

An example using Bubble Sort: each element will go through each and every item till all the items are sorted.

$$N=10$$

$$\text{iteration 1:} \quad k = 10$$
$$\text{iteration 2:} \quad k = 10$$
$$...$$
$$\text{iteration 9:} \quad k = 10$$
$$\text{iteration 10:} \quad k = 10$$

so

$$k = N^2$$

The behavior of the algorithm will follow a quadratic curve as the number of elements increase. This means the larget
$N$ is, the longer it will take to sort.

Both $N^2$ and $2N^2$ follow the behavior of the quadratic equation.

## Analyzing Multiple Sequential Loops

We are given pseudocode below.

```
def double_then_sum(array)
    doubled_array = []

    array.each do |number|
        doubled_array << number * 2
    end

    sum = 0

    doubled_array.each do |number|
        sum += number
    end

    return sum
end
```

## Multiple Constant-Time Operations

## Analyzing Nested Iteration

## Analysis & Reflection

## Resources

1. [Big O Notations](https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/) - GeeksForGeeks