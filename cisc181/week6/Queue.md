# Week 6: Queues

## Part 1 — Trace Queue Operations

***Question:*** Perform the operations below
```c++
enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)
enqueue(50)
dequeue()
enqueue(60)
```

| Operation     | Value Returned | Logical Queue After Operation        | Front | Size | Queue              |
| ------------- | -------------- | ------------------------------------ | ----- | ---- | ------------------ |
| `enqueue(10)` | —              | ⟨ 10,     ,     ,     ,     ,      ⟩ | 10    | 1    | ⟨ 10 ⟩             |
| `enqueue(20)` | —              | ⟨ 10, 20,     ,     ,     ,      ⟩   | 10    | 2    | ⟨ 10, 20 ⟩         |
| `enqueue(30)` | —              | ⟨ 10, 20, 30,     ,     ,      ⟩     | 10    | 3    | ⟨ 10, 20, 30 ⟩     |
| `dequeue()`   | 10             | ⟨     , 20, 30,     ,     ,      ⟩   | 20    | 2    | ⟨ 20, 30 ⟩         |
| `enqueue(40)` | —              | ⟨     , 20, 30, 40,     ,      ⟩     | 20    | 3    | ⟨ 20, 30, 40 ⟩     |
| `enqueue(50)` | —              | ⟨     , 20, 30, 40, 50,      ⟩       | 20    | 4    | ⟨ 20, 30, 40, 50 ⟩ |
| `dequeue()`   | 20             | ⟨     ,     , 30, 40, 50,      ⟩     | 30    | 3    | ⟨ 30, 40, 50 ⟩     |
| `enqueue(60)` | —              | ⟨     ,     , 30, 40, 50, 60 ⟩       | 30    | 4    | ⟨ 30, 40, 50, 60 ⟩ |
### Part 1 Analysis

## Part 2 — Why Not Shift the Array?

### Part 2 Analysis

## Part 3 — Implement a Circular Queue

## Part 4 — Queue State and Invariants

### Part 4 Analysis

## Part 5 — Implement `enqueue()`

### Testing

### Part 5 Analysis

## Part 6 — Implement `dequeue()`

### Testing

### Part 6 Analysis

## Part 7 — Implement `front()`

### Part 7 Analysis

## Part 8 — Demonstrate Circular Wraparound

### Part 8 Analysis

## Part 9 — Logical Position vs. Physical Position

## Part 10 — Test the Complete Circular Queue

## Part 11 — Complexity Analysis

## Part 12 — FIFO Correctness

## Part 13 — Queue Applications
### Scenario A — Print Server

***Question:*** Print jobs should be processed in the order in which they arrive.

***Answer:***
### Scenario B — Server Requests

***Question:*** Requests waiting for a worker should generally be processed in arrival order.

***Answer:***
### Scenario C — Undo

***Question:*** A text editor should undo the most recent operation first.

***Answer:***
### Scenario D — Breadth-First Search

***Question:*** Vertices discovered earlier should be processed before vertices discovered later.

***Answer:***
### Scenario E — Function Calls

***Question:*** The most recently called unfinished function must complete before the calling function resumes.

***Answer:***

## Part 14 — Queue and Breadth-First Search

## Analysis and Reflection

1. ***Why a queue is an Abstract Data Type rather than a specific physical representation.***
2. ***How FIFO differs from LIFO.***
3. ***Why circular indexing is preferable to shifting elements after every dequeue.***
4. ***How `frontIndex`, `rearIndex`, and `count` work together.***
5. ***Why modular arithmetic is necessary for wraparound.***
6. ***Why `frontIndex == rearIndex` can be ambiguous without additional state.***
7. ***How maintaining `count` solves the empty-versus-full problem.***
8. ***Why properly implemented enqueue and dequeue operations are O(1).***
9. ***Why queues are appropriate for systems that process work in arrival order.***
10. ***How FIFO ordering supports breadth-first traversal.***