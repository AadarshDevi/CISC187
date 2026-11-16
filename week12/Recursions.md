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