# Week 3/4 - Sorting II

## Table of Contents

1. [Average-Case Analysis of Insertion Sort](#average-case-analysis-of-insertion-sort)
2. [Changing the Starting Position of Insertion Sort](#changing-the-starting-position-of-insertion-sort)
3. [Improving a Search Algorithm](#improving-a-search-algorithm)
4. [Analysis & Reflection](#analysis--reflection)

## Average-Case Analysis of Insertion Sort

In Insertion Sort, there is a sorted pile (usually the left side of the array) and the unsorted array (right side). Each
item is compared to the rest of the items in the dataset. It will get the lowest value it finds and switches the values
in the two indices. It will then continue on till it sorts the dataset.

So if the dataset has $N$ items, the first item will have $N-1$ comparisons, the second item will have $N-2$
comparisons.

$$N-1$$
$$N-2$$
$$...$$
$$1$$

Each item will be compared to the rest of the array so $(N-I)$ where $I$ is the number of remaining items in the array.
The time complexity will be:

$$
N \times (N-I)=N^2 -NI
$$

Since Big-O Notation ignores terms that are not the highest degree, in this case $NI$, the time complexity is $O (N^2)$.

## Changing the Starting Position of Insertion Sort

## Improving a Search Algorithm

## Analysis & Reflection