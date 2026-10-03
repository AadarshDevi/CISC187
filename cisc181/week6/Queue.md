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

| Operation     | Value Returned | Logical Queue After Operation        | Front | Size |
| ------------- | -------------- | ------------------------------------ | ----- | ---- |
| `enqueue(10)` | —              | ⟨ 10,     ,     ,     ,     ,      ⟩ | 10    | 1    |
| `enqueue(20)` | —              | ⟨ 10, 20,     ,     ,     ,      ⟩   | 10    | 2    |
| `enqueue(30)` | —              | ⟨ 10, 20, 30,     ,     ,      ⟩     | 10    | 3    |
| `dequeue()`   | 10             | ⟨     , 20, 30,     ,     ,      ⟩   | 20    | 2    |
| `enqueue(40)` | —              | ⟨     , 20, 30, 40,     ,      ⟩     | 20    | 3    |
| `enqueue(50)` | —              | ⟨     , 20, 30, 40, 50,      ⟩       | 20    | 4    |
| `dequeue()`   | 20             | ⟨     ,     , 30, 40, 50,      ⟩     | 30    | 3    |
| `enqueue(60)` | —              | ⟨     ,     , 30, 40, 50, 60 ⟩       | 30    | 4    |
### Part 1 Analysis
1. ***What is the final front element?*** The front item after the final operation is `30`.
2. ***What is the final queue size?*** The final size of the queue is `4`.
3. ***In what order would the remaining elements be removed?*** The order in which the objects will be removed is $30\rightarrow40\rightarrow50\rightarrow60$.
4. ***How does this demonstrate FIFO behavior?*** The item that was in the queue the longest, `10`, was removed first. The last element entered, `60`, would be out of the queue the last.
## Part 2 — Why Not Shift the Array?
Suppose the queue contains:

```
Index      0    1    2    3    4
         +----+----+----+----+----+
         | 10 | 20 | 30 | 40 |    |
         +----+----+----+----+----+
           ↑              ↑
         front           rear
```

A naïve `dequeue()` implementation could remove `10` and shift every remaining element one position to the left:

```
for (int i = 1; i < count; ++i) {
    data[i - 1] = data[i];
}
```
### Part 2 Analysis

1. ***If the queue contains `N` elements, approximately how many elements may need to move during one `dequeue()`?*** If there are $N$ elements, $N-1$ elements have to moved each time an item is removed from the queue.
2. ***What is the Big-O complexity of this approach?*** The time complexity is $O(N)$ for the operation. Each time, the $N$ items have to be moved.
3. ***Why can repeatedly removing all `N` elements this way require O(N²) total work?*** There are $N$ items in the queue. Removing an item make $N-1$ items move. So for $N$ items moving $N-1$ times, $N(N-1)=N^2-N=N^2$ work.
4. ***Why is advancing the front index preferable to physically moving every remaining element?*** Moving the `frontIndex` will not force the $N-1$ elements. Only thing that changes is `frontIndex`. Moving `frontIndex` is `1` operation and moving $N-1$ items is $N-1$ operations.
## Part 3 — Implement a Circular Queue
### Class: Queue
```c++
#include <iostream>  
#include <stdexcept>  
  
class Queue {  
private:  
    static constexpr int CAPACITY = 5;  
    int queue[CAPACITY];  
    int frontIndex;  
    int rearIndex;  
    int count;  
  
    inline int nextIndex(int index) const {  
        return (index + 1) % this->CAPACITY;  
    }
  
public:  
    Queue() {  
        frontIndex = 0;  
        rearIndex = 0;  
        count = 0;  
    }  
  
    bool empty() const {  
        return count == 0;  
    }  
  
    bool full() const {  
        return count >= this->CAPACITY;  
    }  
  
    int size() const {  
        return count;  
    }  
  
    void enqueue(int item) {  
        if (full()) throw std::overflow_error("Queue Overflow");  
        queue[rearIndex] = item;  
        rearIndex = nextIndex(rearIndex);  
        count++;  
    }  
  
    int dequeue() {  
        if (empty()) throw std::underflow_error("Queue Underflow");  
        const int item = queue[frontIndex];  
        frontIndex = nextIndex(frontIndex);  
        count--;  
        return item;  
    }  
  
    int front() const {  
        if (empty()) throw std::underflow_error("Queue Underflow");  
        return queue[frontIndex];  
    }  
  
    void printInfo() {  
        std::cout << "Front Index: " << frontIndex << "\n";  
        std::cout << "Rear Index: " << rearIndex << "\n";  
        std::cout << "Size: " << size() << "\n";  
        std::cout << "Count: " << count << "\n";  
    }  
};
```
## Part 4 — Queue State and Invariants

My Queue Implementation should maintain:
1. [x] `frontIndex`: location of the next element to remove
2. [x] `rearIndex`: location where the next element will be inserted
3. [x] `count`: number of elements currently stored

My implementation of Queue initializes the indices and count.
```c++
Queue() {  
	frontIndex = 0;  
	rearIndex = 0;  
	count = 0;  
}  
```

For a queue with capacity $N$:
1. [x] $0\leq\text{frontIndex}<N$: `inline int nextIndex(int index) const;`
2. [x] $0\leq\text{frontIndex}<N$: `inline int nextIndex(int index) const;`
3. [x] $0\leq\text{frontIndex}\leq N$: `bool empty() const;` and `bool full() cost;`
### Part 4 Task

#### Implement `empty()`
```c++
bool empty() const {  
	return count == 0;  
}  
```
#### Implement `full()`
```c++
bool full() const {  
	return count >= this->CAPACITY;  
}
```
#### Implement `size()`
```c++
int size() const {  
	return count;  
}
```
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

***Answer:*** A Queue is the appropriate structure because the first print job should be printed first. It's first come, first serve.
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