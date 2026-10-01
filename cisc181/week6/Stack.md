
## Part 1 — Trace Stack Operations

***Question:***
```
push(10)
push(20)
push(30)
pop()
push(40)
push(50)
pop()
push(60)
```

***Answer:***

| Operation  | Value Returned | Stack After Operation | Top Element | Stack Size |
| ---------- | -------------- | --------------------- | ----------- | ---------- |
| `push(10)` | —              | ⟨ 10 ⟩                | 10          | 1          |
| `push(20)` | —              | ⟨ 10, 20 ⟩            | 20          | 2          |
| `push(30)` | —              | ⟨ 10, 20, 30 ⟩        | 30          | 3          |
| `pop()`    | 30             | ⟨ 10, 20 ⟩            | 20          | 2          |
| `push(40)` | —              | ⟨ 10, 20, 40 ⟩        | 40          | 3          |
| `push(50)` | —              | ⟨ 10, 20, 40, 50 ⟩    | 50          | 4          |
| `pop()`    | 50             | ⟨ 10, 20, 40⟩         | 40          | 3          |
| `push(60)` | —              | ⟨ 10, 20, 40, 60 ⟩    | 60          | 4          |
### Part 1 Analysis
1. What is the final top element? **60***
2. What is the final stack size? **4***
3. In what order would the remaining elements be removed? ***pop() -> 60, 40, 20, 10***
4. How does the result demonstrate LIFO behavior? ***The item added in last can be removed from the stack the first. the first item added to the stack is removed the last.***

## Part 2 — Implement an Array-Based Stack

***Question:*** Build an Array-based Stack

***Stack Template:***
```c++
#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    static const int CAPACITY = 10;

    int data[CAPACITY];
    int topIndex;

public:
    Stack();

    bool empty() const;
    bool full() const;
    int size() const;

    void push(int value);
    int pop();
    int top() const;
};
```

### Stack Class
```c++
class Stack {  
private:  
    static const int CAPACITY = 10;  
  
    int data[CAPACITY];  
    int topIndex;  
  
public:  
    Stack() {  
        topIndex = -1; // it means the stack is empty  
    }  
  
    bool empty() const {  
        return topIndex == -1; // this means there is nothing in the stack.  
    }  
  
    bool full() const {  
        return topIndex == (CAPACITY - 1); // max capacity fo stack reached  
    }  
  
    int size() const {  
        return topIndex + 1; // index starts at 0 so 1 has to be added  
    }
  
    void push(int value) {  
        if (full()) throw std::overflow_error("Stack Overflow"); // full stack  
        topIndex++; // increment index to get new index  
        data[topIndex] = value; // set value to the new empty index  
    }  
  
    int pop() {  
        if (empty()) throw std::underflow_error("Stack Underflow"); // empty stack  
        int value = data[topIndex]; // get top value  
        topIndex--; // decrement to the new top value  
        return value;  
    }  
  
    // also called peek  
    int top() const {  
        if (empty()) throw std::underflow_error("Stack Underflow"); // empty stack  
        return data[topIndex]; // return top item without changing stack  
    }  
};
```
## Part 3 — Maintaining

### Constructor: Stack Starts Empty
```c++
Stack() {  
	topIndex = -1; // it means the stack is empty  
}  
```

### Member Methods' Implementation
1. Methods: `empty()`, `full()`, `size()`
2. $1<= \text{topIndex} <+ CAPACITY$
```c++
bool empty() const {  
	return topIndex == -1; // this means there is nothing in the stack.  
}  

bool full() const {  
	return topIndex == (CAPACITY - 1); // max capacity fo stack reached  
}  

int size() const {  
	return topIndex + 1; // index starts at 0 so 1 has to be added  
}
```
### Part 3 Analysis
1. Why should `topIndex` initially be `-1` rather than `0`? ***`topIndex` being 0 means that there is a value at index 0. It means that the stack is not actually empty.***
2. Why is the stack size `topIndex + 1`? ***Index in C++ starts at 0 which means the last index will be 9 if $\text{topIndex} = 10$. If we return `topIndex`, we will get a size of 9 instead of 10.***
3. What value of `topIndex` indicates that the stack is full? ***$\text{topIndex} = \text{CAPACITY} - 1$ means it is full. `topIndex` has a max value of 9 and $\text{CAPCAITY} = 10$. So the max value for `topIndex` will be 9.***
## Part 4 — Implement `push()`

***Stack Template:***
```c++
void push(int value);
```

### Stack Method
```c++ 
void push(int value) {  
	if (full()) throw std::overflow_error("Stack Overflow"); // full stack  
	topIndex++; // increment index to get new index  
	data[topIndex] = value; // set value to the new empty index  
}  
```
#### Verification
1. [x] Verify that the stack is not full.
2. [x] Move `topIndex` to the next available position.
3. [x] Store the new value at that position.

### Testing

Testing involves pushing $N+1$ items in the stack. I have also printed out the stack size so we can see how many items are in the stack.
```c++
Stack stack;  
cout << "Before: " << stack.size() << endl;  
  
for (int i = 0; i < 11; i++) {  
    stack.push(i + 1);  
    cout << stack.size() << endl;  
}
```
#### Output
The output below is exactly what we need, getting a stack overflow. It also shows that it is hit when we try to add ***item #11***.
```terminalOutput
"{MyFilepath_To_Folder}\CISC 181 - Data Structures in C++\cisc181\week6\Stack.exe"
Before: 0
1
2
3
4
5
6
7
8
9
10
terminate called after throwing an instance of 'std::overflow_error'
  what():  Stack Overflow

Process finished with exit code 3
```
### Part 4 Analysis
Explain why writing beyond `data[CAPACITY - 1]` would be incorrect? ***It would be incorrect because the max capacity is reached and we are trying to write in memory where we do not have access to it. The segment after our stack doesn't belong to our stack. It is trying to write into memory that it has no access to.***
## Part 5 — Implement `pop()`

***Stack Template:***
```c++
void push(int value);
```

### Stack Method
```c++ 
int pop() {  
    if (empty()) throw std::underflow_error("Stack Underflow"); // empty stack  
    int value = data[topIndex]; // get top value  
    topIndex--; // decrement to the new top value  
    return value;  
}
```
#### Verification
1. [x] Verify that the stack is not empty.
2. [x] Save the current top value.
3. [x] Decrease `topIndex`.
4. [x] Return the removed value.

### Testing

Testing involves popping $N+1$ items from the stack. I have also printed out the stack size so we can see how many items are in the stack.
```c++
Stack stack;  
cout << "Before: " << stack.size() << "\n";  

// Add 10 items
for (int i = 0; i < 10; i++) {  
    stack.push(i + 1);  
    cout << stack.size() << "\n";  
}

// Remove 11 items
cout << "\nBefore Removing: " << stack.size() << "\n";  
for (int i = 10; i > -1; i--) {  
    stack.pop();  
    cout << stack.size() << "\n";  
}
```
#### Output
The output below is exactly what we need, getting a stack underflow. It also shows that it is hit when we try to pop ***item #11*** at index -1 which doesn't exist.
```terminalOutput
"{MyFilepath_To_Folder}\CISC 181 - Data Structures in C++\cisc181\week6\Stack.exe"
terminate called after throwing an instance of 'std::underflow_error'
  what():  Stack Underflow
Before: 0
... // removed because its adding items to stack logs
10

Before Removing: 10
9
8
7
6
5
4
3
2
1
0

Process finished with exit code 3
```
### Part 5 Analysis
Explain why accessing `data[topIndex]` when `topIndex = -1` is invalid. ***The remaining item in the stack is the first item added in the stack, which is at index 0. $\text{topIndex}=-1$ means that the stack is empty. We are trying to read items that do not exist at all.***
## Part 6 — Implement `top()`

***Stack Template:***
```c++
int top() const;
```

### Stack Method
```c++
// also called peek  
int top() const {  
    if (empty()) throw std::underflow_error("Stack Underflow"); // empty stack  
    return data[topIndex]; // return top item without changing stack  
}
```
#### Verification
1. [x] Return the element at the top of the stack.
2. [x] Leave the stack unchanged.
3. [x] Throw an underflow exception if the stack is empty.
### Testing
```c++
Stack stack;  
  
// Add 5 items  
cout << "Before: " << stack.size() << "\n";  
for (int i = 0; i < 5; i++) {  
    stack.push(i + 1);  
    cout << stack.size() << "\n";  
}  
  
// Get the last item  
std::cout << "\nTop: " << stack.top() << "\n";  
std::cout << "Size: " << stack.size() << "\n";  
  
// Remove 11 items  
cout << "\nBefore Removing: " << stack.size() << "\n";  
for (int i = 3; i > 0; i--) {  
    stack.pop();  
    cout << stack.size() << "\n";  
}  
  
// Get the last item  
std::cout << "\nTop: " << stack.top() << "\n";  
std::cout << "Size: " << stack.size() << "\n";  
  
// Remove 11 items  
cout << "\nBefore Removing: " << stack.size() << "\n";  
for (int i = 2; i > 0; i--) {  
    stack.pop();  
    cout << stack.size() << "\n";  
}  
  
// Get the last item  
std::cout << "\nTop: " << stack.top() << "\n";  
std::cout << "Size: " << stack.size() << "\n";
```

#### Output
```terminalOuput
"{MyFilepath_To_Folder}\CISC 181 - Data Structures in C++\cisc181\week6\Stack.exe"
terminate called after throwing an instance of 'std::underflow_error'
  what():  Stack Underflow
Before: 0
1
2
3
4
5

Top: 5
Size: 5

Before Removing: 5
4
3
2

Top: 2
Size: 2

Before Removing: 2
1
0

Top:
Process finished with exit code 3
```
### Part 6 Analysis
Explain the difference between `top()` and `pop()`? ****The methods `top()` and `pop()` do a similar thing, they give the top most item, but apart from that they do different things. `top()` only gives the top item. It does not modify the stack. `pop()` like `top()`, gives the top item, but it modifies the stack by removing it from the stack and then returning it. The table below shows the difference.***

|         | Item Returned | Modifies Stack |
| ------- | :-----------: | :------------: |
| `pop()` |   Top most    |      Yes       |
| `top()` |   Top most    |       No       |

## Part 7 — Test the Complete Stack

***Question:*** Write a `main()` function that demonstrates all operations of your stack.

Operations to Perform:
1. Create an empty stack.
2. Verify that `empty()` returns the correct result.
3. Push at least five values.
4. Display the current size.
5. Display the current top.
6. Pop at least two values.
7. Display the new top and size.
8. Continue removing values until the stack is empty.
9. Demonstrate underflow handling.
10. Fill the stack to capacity.
11. Demonstrate overflow handling.

```
```

### Output
```terminalOutput
"{MyFilepath_To_Folder}\CISC 181 - Data Structures in C++\cisc181\week6\Stack.exe"
2. Stack Empty? 1

3. Stack Size: 5

4. Top Value: 50

7.1. Top Value: 30

7.2. Stack Size: 3
Stack Underflow
Stack Overflow

Process finished with exit code 0
```
## Part 8 — Complexity Analysis

## Part 9 — Stack Correctness

## Part 10 — Balanced Delimiters
## Part 11 — Implement the Balanced-Delimiter Algorithm
## Part 12 — Analyze Delimiter Matching
## Part 13 — Stack Applications
### Scenario A — Undo
### Scenario B — Function Calls

### Scenario C — Browser Back Navigation

### Scenario D — Depth-First Search

### Scenario E — Customer Service Line
## Analysis and Reflection
