# Recursions

## Part 1 — Recognizing Recursion

```
void example() {
    example();
}
```

***Questions:***
1. ***Why is this function recursive?*** Yes
2. ***Does this function contain a base case?*** No
3. ***What will happen if `example()` is called?*** This is like an infinite loop
4. ***What happens to the call stack as the function continues to call itself?*** The stack will fill up with `example()` and at some point, `StackOverflowError`.

## Part 2 — From Loop to Recursion

Write an iterative C++ function that prints a countdown from a positive integer to `0`. Then rewrite the function using recursion instead of a loop. Before writing the recursive version, identify:

| Question                                      | Your Response                                                                                                                                                                                                                 |
| --------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| What is the base case?                        | The best case is `0`, the countdown reaches `0`.                                                                                                                                                                              |
| What is the recursive case?                   | `countdownRecursive(num - 1)` is the recursive case. We reduce the num by 1 so we don't end up in an infinite loop.                                                                                                           |
| How does each call move toward the base case? | In the iterative function, the loop reduces the value and it loops till the number hits 0. In the recursive function, it will call itself after it decrements the number. This will help move the recursion to the base case. |

```c++
static void countdown(int num) {  
    for (int i = num; i >= 0; i--) {  
        std::cout << i << "\n";  
    }  
}
```

```c++
static void countdownRecursive(int num) {  
    if (num == 0) return;  
    std::cout << num << "\n";  
    countdownRecursive(num - 1);  
}
```

## Part 3 — Trace the Countdown

Assume the following recursive function below. Trace `countdown(3)` on the table below.

```c++
void countdown(int number) {
    cout << number << "\n";
    if (number == 0) return;
    countdown(number - 1);
}
```

| Step | Function Call  | Value Printed | Next Action    |
| ---- | -------------- | ------------- | -------------- |
| 1    | `countdown(3)` | `3`           | `countdown(2)` |
| 2    | `countdown(2)` | `2`           | `countdown(1)` |
| 3    | `countdown(1)` | `1`           | `countdown(0)` |
| 4    | `countdown(0)` | `0`           | `return`       |

***Question:*** Explain why the base case prevents the function from continuing into negative numbers.

***Answer:*** The base case there to stop `StackOverflow`. Lets say that the recursive func doesn't have a base case, the function will call itself infinitely. The call stack will add the new function call and it will go on and never stop. The `StackOverflowError` is the only way to stop infinite recursion.

## Part 4 — Reading Recursive Code: Factorial

Consider the following function. Then answer the questions below.

```c++
int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}
```

***Question:***
1. What is the base case? `1`
2. What is the recursive case? `n * factorial(n - 1)`
3. How does `n - 1` move the function toward the base case? This reduces the number so that it will not loop forever.
4. What does `factorial(1)` return? `1`
5. Use that result to determine `factorial(2)`. $2\times 1 = 2$
6. Use the previous result to determine `factorial(3)`. $3\times 2\times 1 = 6$
7. Determine `factorial(4)`. $4\times 3\times 2\times 1 = 24$

## Part 5 — Expanding Recursive Calls

Expand `factorial(4)` until the base case is reached. Complete the pattern below. At what point does the recursive calling phase stop?

```
factorial(4)
= 4 * factorial(3)
= 4 * (3 * factorial(2))
= 4 * (3 * (2 * factorial(1)))
= 4 * (3 * (2 * 1))  // base case = 1
= 4 * (3 * 2)
= 4 * 6
= 24
```

## Part 6 — The Call Stack

Trace the call stack for `factorial(4)`. Show the order in which functions are **called**.

| Call Order | Function       |
| ---------- | -------------- |
| 1          | `factorial(4)` |
| 2          | `factorial(3)` |
| 3          | `factorial(2)` |
| 4          | `factorial(1)` |

Show the order in which those functions **complete**. Explain why the completion order is the reverse of the call order.

| Completion Order | Function            |
| ---------------- | ------------------- |
| 1                | `4 * (3 * (2 * 1))` |
| 2                | `4 * (3 * 2)`       |
| 3                | `4 * 6`             |
| 4                | `24`                |

## Part 7 — Passing Values Up the Call Stack

Complete the return-value trace for `factorial(4)`. Then explain what it means for a value to be passed back up through the call stack.

| Function     | Expression      | Returned Value |
| ------------ | --------------- | -------------- |
| factorial(1) | `1`             | `1`            |
| factorial(2) | `2 * 1`         | `2`            |
| factorial(3) | `3 * 2 * 1`     | `6`            |
| factorial(4) | `4 * 3 * 2 * 1` | `24`           |

***Answer:*** The value that is being passed back up is the value that was being calculated for the result using the value given. Each time the function calls itself, it is calculating another number that is needed for the final result. So by going back up, we are giving multiple

## Part 8 — Debugging Recursive Functions

### Example A

```c++
void mystery(int n) {
    if (n == 0) return;
    mystery(n + 1);
}
```

***Question:*** Assume `mystery(5)` is called.

1. ***Does this function contain a base case?*** Yes, `n == 0` is the base case.
2. ***Will the base case ever be reached?*** no, the base case will never be reached.
3. ***What is wrong with the recursive step?*** When recursion happens, `n` is incrementing so, the base case won't be reached.
4. ***How would you correct it?*** To fix the recursion, we need to decrement `n` so we can reach the base case of `n == 0`.

### Example B

```c++
void mystery2(int n) {
    cout << n << "\n";
    mystery2(n - 1);
}
```

***Question:*** Explain why this function eventually causes a stack overflow. The function will cause stack overflow because there is no base condition to stop the function from looping forever.
## Part 9 — Write a Recursive Function

Write a recursive C++ function that calculates the sum of the integers from `1` through `n`. For example: `sumTo(5)` represents `5 + 4 + 3 + 2 + 1`. Before coding, state:
1. ***The base case***: `n == 1`
2. ***The recursive case***: `n + sumTo(n - 1)`
3. ***How the recursive argument moves toward the base case*** For each number, we are adding the `n - 1` each recursive loop.

Then trace `sumTo(4)`, showing both recursive calls and returned values.

### Trace

| Order | Call Stack                 |
| ----- | -------------------------- |
| 1     | `sumTo(4)`                 |
| 2     | `4 + sumTo(3)`             |
| 3     | `4 + (3 + sumTo(2))`       |
| 4     | `4 + (3 + (2 + sumTo(1)))` |
| 5     | `4 + (3 + (2 + 1))`        |
| 6     | `4 + (3 + 3)`              |
| 7     | `4 + 6`                    |
| 8     | `10`                       |
## Part 10 — Recursion vs. Iteration

Compare a loop-based countdown with a recursive countdown.

| Question                                                     | Response                                                                                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------ |
| Which version is easier for you to read?                     | loop-based because the call stack is on a single level. And it is a loop which is straight forward.                            |
| Which version uses the call stack?                           | Recursive countdown uses the call stack because each recursive call is an unfinished operation.                                |
| Is recursion automatically more efficient than iteration?    | No, because the call stack has to do more work managing recursion. Recursion takes more resources than a loop based countdown. |
| Why might a loop still be preferable for a simple countdown? | For a simple countdown, a loop-based function is preffered because it is easier and straight forward.                          |

## Part 11 — Recursive Structure: Filesystem Traversal

```
projects/
    cpp/
        graphs/
        recursion/
    python/
        data/
            raw/
            processed/
    notes/
```

Consider the following nested directory structure above. Suppose you need to visit every directory regardless of how deeply nested it is.
1. ***Why is recursion a natural approach to this problem?*** Because each folder has sub folders, using a loop will be more tedious. By using recursion, we are able to iterate through a list of folders.
2. ***What could serve as the base case when processing a directory?*** A base case could be that the length of the list of folders is 0.
3. ***What would the recursive case do?*** recursive case would go through each folder in a list and return once there are no folders left to search.
4. ***Why is it difficult to know in advance how many levels of nesting may exist?*** Many folders can have varying level of subfolders. If we known the levels, nested loops can be used, but because we do not know how many levels there are, it would be least preferred. Other than that, all folders might not have the same no of levels in them.

Write pseudocode or a short C++-style recursive function showing the general idea of traversing nested directories. The focus is on the recursive structure rather than operating-system-specific file APIs.

```psuedocode
void recursiveFolderSearch(folder):

	for subfolder in folder.subfolder_list:
	
		print(subfolder.name)
		recursiveFolderSearch(folder)
		
	end_for
	
end_function

```

...