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

Let's go through the pseudocode line by line.

Our input is an int array `int array[]` with a length $N$.

```
def double_then_sum(array)
    doubled_array = []
```

We are going through each item and doubling it. then we are writing it to `doubled_array` using the same index in
`array`.

```
array.each do |number|
   doubled_array << number * 2
end
```

rewritten for _my understanding_.

```java
for (int i = 0; i < array.length; i++) {
    doubled_array[i] = 2 * array[i]
}
```

The time complexity for this loop is $O (N)$ because we are going through $N$ item.

Next we are summing all the doubled values.

```
sum = 0

doubled_array.each do |number|
   sum += number
end
```

The time complexity for this is also $O (N)$ because we are going through the $N$ items but here it is in
`doubled_array`.

So, the double loop has time complexity of $N$. So does the sum loop.

$$N + N = 2N$$

With this info, the time complexity derived:

$$N + N = 2N = N \quad\because{\text{ Constant Multipliers ignored}}$$

So, the time complexity for the pseudocode is
$$O (N)$$

If anyone was wondering why it is $O (N)$, it is because both for loops fun sequentially. If they were inside each other
(nested for loops) then the time complexity would've been $O (N^2)$ but here they are not.

## Multiple Constant-Time Operations

We are given the below pseudocode.

```
def multiple_cases(array)
    array.each do |string|
        puts string.upcase
        puts string.downcase
        puts string.capitalize
    end
end
```

Rewritten for my convenience.

```java
for (int i = 0; i < array.length; i++) {
    IO.println(array[i].toUpperCase());
    IO.println(array[i].toLowerCase());
    // capitalize the string - code not important
}
```

Here we are looping through an array of strings and, we are doing string operations before we print it out to the
terminal. Because there is only 1 loop running in the function, we are doing one operation after another, the time
complexity for this would be $O (N)$. Below is the breakdown:

looping through each item so

$$
k = N
$$

$$
1 \text{ loop} = 1 \text{ iteration}
$$
$$
N \text{ loop} = k \text{ iterations}
$$

Even though each string goes through 3 different string operations, they are happening in the same iteration of the
loop. If they were in 3 different iterations it would be the same except instead of $N$, it will be $3N$, which is still
the same $O (N)$.

If the time complexity is based on the operations:

$$
1 \text{ item} = 3 \text{ operations}
$$
$$
N \text{ items} = 3 \text{ operations}
$$

So it will be as the other example $N+N+N=3N =O (3N)=O (N)$.

## Analyzing Nested Iteration

We are given the below pseudocode.

```
def every_other(array)
    array.each_with_index do |number, index|
        if index.even?
            array.each do |other_number|
                puts number + other_number
            end
        end
    end
end
```

rewritten for my understanding.

Lets breakdown the pseudocode.

```
array.each_with_index do |number, index|
   ...
end
```

First the outer loop is running. It is running through each item so, it's time complexity would be $O (N)$.

The if condition runs for half of the items because it will run the inner loop only if the outer index is even. The
complexity for this is $N/2$.

The inner loop inside the condition is running for each item and, it is printing it to the terminal. So its time
complexity is $O (N)$. But because it is run for half of the items in the array, time complexity is $O (N/2)$.

So the pseudocode has nested loops which means:

$$
\frac{N}{2} \times N = \frac{N^2}{2} = N^2 \quad\because{\text{ Big-O Notation Rule}}
$$

So the time complexity for the pseudocode given is

$$
O (N^2)
$$

If the condition was present or not, the item in the array will still go through the two loops. The conditional being
present only lets half of the items to go to the loop which means $N/2$ items go to the inner loop. If it isn't present,
the loop will have N items to loop.

## Analysis & Reflection

### Why constants are normally ignored in Big-O notation

Explained in the book: "**Searching and Big O Notations > Big O Notations**". It is the number of steps needed that
determine the efficiency. A loop goes through $N$ item which means it has $N$ steps to complete in order to do search,
sort, etc.

Let's say that there are 2 sequential for loops, both loops are going through $N$ items. Which would make the time $2N$.
But the number of steps needed will remain the same. Both $N$ and $2N$ explain that the algorithm has a linear time
complexity. Adding an item to the dataset will increase the number of steps needed to $N$.

### The difference between O (N) and O (N²) growth

In $O (N)$ each item is accessed and processed once. But in $O (N^2)$, each item is processed $N$ times. Which results
in $O (N^2)$.

A single loop will access and use an item one time so $N$ items, $N$ steps, which means $O (N)$.

A nested loop (2 loops in this case) will access each item $N$ times. $N$ items and each item used $N$ times. So we
get $O (N^2)$.

$O (N)$ is a linear time complexity while $O (N^2)$ is quadratic time complexity.

### Why sequential loops and nested loops can result in different time complexities

### Why understanding time complexity becomes increasingly important as the size of a dataset grows

## Resources

1. [Big O Notations](https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/) - GeeksForGeeks