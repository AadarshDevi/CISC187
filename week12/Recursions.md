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

Write an iterative C++ function that prints a countdown from a positive integer to `0`.

Example:

```
countdown(5)
```

should produce:

```
5
4
3
2
1
0
```

Then rewrite the function using recursion instead of a loop.

Before writing the recursive version, identify:

|Question|Your Response|
|---|---|
|What is the base case?||
|What is the recursive case?||
|How does each call move toward the base case?||

## Part 3 — Trace the Countdown