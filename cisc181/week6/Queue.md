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

| Operation     | Value Returned | Logical Queue After Operation               | Front | Size |
| ------------- | -------------- | ------------------------------------------- | ----- | ---- |
| `enqueue(10)` | —              | $10$                                        | 10    | 1    |
| `enqueue(20)` | —              | $10\rightarrow20$                           | 10    | 2    |
| `enqueue(30)` | —              | $10\rightarrow20\rightarrow30$              | 10    | 3    |
| `dequeue()`   | 10             | $20\rightarrow30$                           | 20    | 2    |
| `enqueue(40)` | —              | $20\rightarrow30\rightarrow40$              | 20    | 3    |
| `enqueue(50)` | —              | $20\rightarrow30\rightarrow40\rightarrow50$ | 20    | 4    |
| `dequeue()`   | 20             | $30\rightarrow40\rightarrow50$              | 30    | 3    |
| `enqueue(60)` | —              | $30\rightarrow40\rightarrow50\rightarrow60$ | 30    | 4    |
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

```c++
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
1. ***Why does `count == 0` represent an empty queue?*** It means that there is no data in the queue which means the queue is empty.
2. ***Why does `count == CAPACITY` represent a full queue?*** This means all the spaces in the queue are occupied by items. There are no empty spaces left.
3. ***Why can `frontIndex == rearIndex` represent either an empty or full circular queue in this design?*** 
   
   The `frontIndex` is the element to be removed from the queue. When it is removed, it goes to the next index. For `rearIndex`, it is the next empty space where the new item can be added to the queue. When a new item is added, it goes to the next index.
   
   When data is being added, and not being removed, the `frontIndex` will be the same. The `rearIndex` will continue to go to the next index till it reaches the `frontIndex` where it is full. `rearIndex` will think that the index where `frontIndex` is on is empty.
   
   If the queue is full and data is being removed instead, the `frontIndex` will continue to go to the next item in the queue. `rearIndex` will staty in the same place. `frontIndex` will catch up. When the last item is removed, `frontIndex` will think that there is data int he next index and move. But there is no data and `rearIndex` and `frontIndex` are on the same index.
1. ***How does maintaining `count` remove this ambiguity?*** Because count increments when items are added and decrements when items are removed, this will have up-to date information on the number of items in the queue. So it is checking one number instead of trying to guess if the queue is empty or not.

## Part 5 — Implement `enqueue()`

```c++
// Inline Method to help give the next index
// A separate method because it is used a lot
// and I can make mistakes when I copy paste
inline int nextIndex(int index) const {  
    return (index + 1) % this->CAPACITY; // Circular Indexing
}

void enqueue(int item) {
    if (full()) throw std::overflow_error("Queue Overflow"); // check if queue is full
    queue[rearIndex] = item; // store item at rearIndex  
    rearIndex = nextIndex(rearIndex);  // advance rearindex
    count++;  // increase count
}
```

1. [x] Verify that the queue is not full.
2. [x] Store the value at `rearIndex`.
3. [x] Advance `rearIndex`.
4. [x] Increase `count`.
5. [x] Circular Indexing
6. [x] If queue is full, throw `overflow_error`
### Testing

Method to get Queue Information
```c++
void printInfo() {  
    std::cout << "Queue Information" << "\n";  
    std::cout << "----------------------" << "\n";  
    std::cout << "Front Index: " << frontIndex << "\n";  
    std::cout << "Rear Index: " << rearIndex << "\n";  
    std::cout << "Count: " << count << "\n\n";  
}
```

***Test:*** Fill queue and force `overflow_error`

```c++
Queue queue;  
std::cout << "\nBefore Adding Items\n";  
queue.printInfo();  
  
queue.enqueue(10);  
queue.enqueue(20);  
queue.enqueue(30);  
queue.enqueue(40);  
queue.enqueue(50);  
  
std::cout << "After Adding Items\n";  
queue.printInfo();  
  
  
std::cout << "Attempting Overflow Error\n";  
try {  
    queue.enqueue(50);  
} catch (std::overflow_error const &e) {  
    std::cout << " >> Error: " << e.what() << "\n";  
}
```

1. [x] Fill up queue
2. [x] Overflow Queue

### Output

```terminalOutput
Before Adding Items
Queue Information
----------------------
Front Index: 0
Rear Index: 0
Count: 0

After Adding Items
Queue Information
----------------------
Front Index: 0
Rear Index: 0
Count: 5

Attempting Overflow Error
 >> Error: Queue Overflow
```
### Part 5 Analysis

***Question:*** Explain why `++rearIndex;` by itself is not sufficient for a circular queue?

***Answer:*** When the queue starts empty, nothing will be affected much. But items are added and removed, `rearIndex` will be at the last index of the queue. There if an item is added, the index will go out of the range of the array. This is how we get the ***`Array Index Out Of Bounds Error`***. A modulus helps to make the index stay inside the array.
## Part 6 — Implement `dequeue()`

```c++
// Inline Method to help give the next index
// A separate method because it is used a lot
// and I can make mistakes when I copy paste
inline int nextIndex(int index) const {  
    return (index + 1) % this->CAPACITY; // Circular Indexing
}

int dequeue() {  
    if (empty()) throw std::underflow_error("Queue Underflow");  // check queue is not empty
    const int item = queue[frontIndex];  // save value at frontIndex
    frontIndex = nextIndex(frontIndex);  // advance frontIndex
    count--;  // decrease count
    return item;  // return value removed
}
```

1. [x] Verify that the queue is not empty.
2. [x] Save the value at `frontIndex`.
3. [x] Advance `frontIndex`.
4. [x] Decrease `count`.
5. [x] Return the removed value.
6. [x] Circular indexing
7. [x] If queue is empty, throw `underflow_error`
### Testing

We will use the logging/Queue Info method from before. It will be used a lot.

***Test:*** Add items to queue. Then force `underflow_error`

```c++
Queue queue;  
std::cout << "\nBefore Adding Items\n";  
queue.printInfo();  
  
// add items to queue
queue.enqueue(10);  
queue.enqueue(20);  
queue.enqueue(30);  
queue.enqueue(40);  
queue.enqueue(50);  
  
std::cout << "After Adding Items\n";  
queue.printInfo();  

// empty queue
std::cout << "Emptying Queue\n";
while (!queue.empty()) {  
    queue.dequeue();  
}  
queue.printInfo();

// force underflow
std::cout << "Attempting Underflow Error\n";  
try {  
    queue.dequeue();  
} catch (std::underflow_error const &e) {  
    std::cout << " >> Error: " << e.what() << "\n";  
}
```

### Output

```terminalOutput
Before Adding Items
Queue Information
----------------------
Front Index: 0
Rear Index: 0
Count: 0

After Adding Items
Queue Information
----------------------
Front Index: 0
Rear Index: 0
Count: 5

Emptying Queue
Queue Information
----------------------
Front Index: 0
Rear Index: 0
Count: 0

Attempting Underflow Error
 >> Error: Queue Underflow
```
### Part 6 Analysis

***Question:*** Explain why `dequeue()` should advance `frontIndex` instead of shifting all remaining elements.

***Answer:***
By shifting all elements, the time takes for $N$ items will be $N-1$ operations. So each time an item is removed, the rest of the items will eb shifted front. Instead of shifting the elements, shifting the `frontIndex`, which is a single `int`, it takes $1$ operation.

The time complexity for moving $N$ items (after removing the front item) forward is $O(N)$, while updating the `frontIndex` is $O(1)$.
## Part 7 — Implement `front()`

```c++
int front() const {  
	// underflow_error if queue is empty
    if (empty()) throw std::underflow_error("Queue Underflow");  
    return queue[frontIndex];  // return oldest element, queue unchanged
}
```

1. [x] Return the oldest element currently in the queue.
2. [x] Leave the queue unchanged.
3. [x] Throw an underflow exception if the queue is empty.
### Part 7 Analysis

***Question:*** Explain the difference between `front()` and `dequeue()`.

***Answer:***

|             | Element Returned | Stack Modified |
| ----------- | ---------------- | -------------- |
| `front()`   | oldest items     | No             |
| `dequeue()` | oldest items     | Yes            |
both methods `front()` and `dequeue()` perform similar functions. but they operate differently. `front()` gives the oldest item on the list. Method `dequeue()` also returns the oldest item, but unlike `front()`, it removes the oldest item from the queue. It modifies the queue, which `front()` doesn't.
## Part 8 — Demonstrate Circular Wraparound

***Test:*** Check if my implementation of circular indexing works.

```c++
Queue queue;  
std::cout << "\nBefore Adding Items\n";  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(10);  
queue.printInfo();  
queue.printLogicalQueue();  

queue.dequeue();  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(20);  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(30);  
queue.printInfo();  
queue.printLogicalQueue();  

queue.dequeue();  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(40);  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(50);  
queue.printInfo();  
queue.printLogicalQueue();  

queue.dequeue();  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(60);  
queue.printInfo();  
queue.printLogicalQueue();  

queue.enqueue(70);  
queue.printInfo();  
queue.printLogicalQueue();
```

### Output

There is a table below the output section that shows the terminal output as a table: [Output Table](#output-table)

```terminalOuput
Before Adding Items
Queue Information
----------------------
Front Index: 0
Rear Index: 0
Count: 0

Physical Queue: 1099699712 520 104 1 -1150320624
Queue Information
----------------------
Front Index: 0
Rear Index: 1
Count: 1

Physical Queue: 10 520 104 1 -1150320624
Queue Information
----------------------
Front Index: 1
Rear Index: 1
Count: 0

Physical Queue: 10 520 104 1 -1150320624
Queue Information
----------------------
Front Index: 1
Rear Index: 2
Count: 1

Physical Queue: 10 20 104 1 -1150320624
Queue Information
----------------------
Front Index: 1
Rear Index: 3
Count: 2

Physical Queue: 10 20 30 1 -1150320624
Queue Information
----------------------
Front Index: 2
Rear Index: 3
Count: 1

Physical Queue: 10 20 30 1 -1150320624
Queue Information
----------------------
Front Index: 2
Rear Index: 4
Count: 2

Physical Queue: 10 20 30 40 -1150320624
Queue Information
----------------------
Front Index: 2
Rear Index: 0
Count: 3

Physical Queue: 10 20 30 40 50
Queue Information
----------------------
Front Index: 3
Rear Index: 0
Count: 2

Physical Queue: 10 20 30 40 50
Queue Information
----------------------
Front Index: 3
Rear Index: 1
Count: 3

Physical Queue: 60 20 30 40 50
Queue Information
----------------------
Front Index: 3
Rear Index: 2
Count: 4

Physical Queue: 60 70 30 40 50
```

### Output Table

| Operation          | `frontIndex` | `rearIndex` | `count` | Logical Queue                               |
| ------------------ | ------------ | ----------- | ------- | ------------------------------------------- |
| Initial            | 0            | 0           | 0       |                                             |
| enqueue(10);       | 0            | 1           | 1       | $10$                                        |
| dequeue();         | 1            | 1           | 0       |                                             |
| enqueue(20);  <br> | 1            | 2           | 1       | $20$                                        |
| enqueue(30);       | 1            | 3           | 2       | $20 \rightarrow 30$                         |
| dequeue();         | 2            | 3           | 1       | $30$                                        |
| enqueue(40);       | 2            | 4           | 2       | $30\rightarrow40$                           |
| enqueue(50);       | 2            | 0           | 3       | $30\rightarrow40\rightarrow50$              |
| dequeue();         | 3            | 0           | 2       | $40\rightarrow50$                           |
| enqueue(60);       | 3            | 1           | 3       | $40\rightarrow50\rightarrow60$              |
| enqueue(70);       | 3            | 2           | 4       | $40\rightarrow50\rightarrow60\rightarrow70$ |
### Part 8 Analysis

1. ***When did wraparound occur?*** The wrap around occurred  when `rearIndex` reached max limit of the array.
2. ***Why is the next position after the last physical array index index `0`?*** We modulo the indices so that we can go around the array with getting an array index out of bounds error. After the index becomes 4 (last index), the next index is 0 because $(4+1) \space\%\space 5 = 0$ so the index goes to 0. Hence the wraparound.
3. ***Why can physical array order differ from logical queue order?*** The logical order sees what item is the oldest in the array.
4. ***How does modular arithmetic make this possible?***

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

***Answer:*** The worker should process the orders that come first so they can be sent to be delivered earlier.
### Scenario C — Undo

***Question:*** A text editor should undo the most recent operation first.

***Answer:*** This is the job for a stack, not a queue. For the text editor to undo a certain change, it has to undo the changes done after it. This is not what a queue does.
### Scenario D — Breadth-First Search

***Question:*** Vertices discovered earlier should be processed before vertices discovered later.

***Answer:*** The vertices that are discovered first are processed first in a `Breadth-First Seach`. The later vertices have to wait to be processed. 
### Scenario E — Function Calls

***Question:*** The most recently called unfinished function must complete before the calling function resumes.

***Answer:*** Function calling is a `Call Stack`. It means the function on the top has to be finished before the function that called the top function can finish processing. So a queue will not work here because it will try to process the first but it's inputs are dependent on method that will be called. So a queue will not be able to process the functions.

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