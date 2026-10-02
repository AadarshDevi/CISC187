>[!NOTE]
>This was written in Obsidian, I apolagize if markdown is broken.
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

```c++  
// 1. empty stack - default size = 10 items  
Stack stack;  
  
// 2. is stack empty  
std::cout << "2. Stack Empty? " << stack.empty() << "\n";  
  
// 3. push 5 values  
for (int i = 0; i < 5; i++) {  
    stack.push((i + 1) * 10);  
}  
  
// 4. display current stack size  
std::cout << "\n4. Stack Size: " << stack.size() << "\n";  
  
// 5. display current top value  
std::cout << "\n5. Top Value: " << stack.top() << "\n";  
  
// 6. pop 2 values  
for (int i = 0; i < 2; i++) {  
    stack.pop();  
}  
  
// 7.1. display current top  
std::cout << "\n7.1. Top Value: " << stack.top() << "\n";  
  
// 7.2. display current stack size  
std::cout << "\n7.2. Stack Size: " << stack.size() << "\n";  
  
// 8. remove all items via pop  
while (!stack.empty()) {  
    stack.pop();  
}  
  
// 9. display underflow handling - pop @ (size = 0)  
try {  
    stack.pop();  
} catch (std::underflow_error const &e) {  
    std::cout << e.what() << "\n";  
}  
  
// 10. fill up stack  
while (!stack.full()) {  
    stack.push(stack.size() + 1);  
}  
  
// 11. overflow handling - push @ (size = 10)  
try {  
    stack.push(stack.size() + 1);  
} catch (std::overflow_error const &e) {  
    std::cout << e.what() << "\n";  
}
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

Analyze the following operations:

```
push()
pop()
top()
empty()
full()
size()
```

| Operation | Big-O Complexity | Explanation                                                                                                                                      |
| --------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| `push()`  | $O(1)$           | We are pushing the new item to the top of the stack. So 1 operation. There is no inserting items. Only 1 item is added, the rest not affected.   |
| `pop()`   | $O(1)$           | We are popping the top item from the top of the stack. So 1 operation. There is no moving items down. 1 item removed, the rest not affected.     |
| `top()`   | $O(1)$           | Gives the top item, so 1 operation. Stack is not modified meaning nothing happens.                                                               |
| `empty()` | $O(1)$           | Checks if the stack size is -1 which is 1 conditional. Stack is not modified making it remain the same. No items are touched.                    |
| `full()`  | $O(1)$           | Checks if the stack size is $\text{CAPACITY} - 1$ which is 1 conditional. Stack is not modified making it remain the same. No items are touched. |
| `size()`  | $O(1)$           | Gives the current stack size and adds 1 to it because index starts at 0. Stack is not modified making it remain the same. No items are touched.  |
### One Million Elements

***Question:*** A stack has `1,000,000` elements. Explain whether removing the top element requires examining the previous `999,999` elements. Connect your explanation to the purpose of maintaining `topIndex`.

***Answer:*** A stack containing `1,000,000` elements will not be disturbed when the top item is removed (size = `999,999`) . The only item that is accessed or modified is the top item. The rest are not touched by the stack. The index, $\text{topIndex}=1,000,000$ starts and when the top item is removed, $\text{topIndex}=999,999$ which tells us that the `999,999` elements were not disturbed.
## Part 9 — Stack Correctness

Suppose an empty stack receives:

```
push(5)
push(10)
push(15)
push(20)
```

Without running the program, determine the values returned by four consecutive `pop()` operations.

Then explain the general relationship:

```
push(x1), push(x2), ..., push(xN)
```

followed by repeated pops.

What order should the values be returned in?

Explain why this property can be used to test whether your stack implementation is correct.


***Question:***
1. Predict the 4 consecutive numbers retrieved by the 4 consecutive `pop()` operations.
2. Explain the general relationship. What is the numbers from`pop()` return? What is the order?
3. Explain why the property can be used to test whether the stack implementation is correct.

***Answer:***
1. 4 Consecutive `pop()` numbers: `stack -> (5, 10, 15, 20)`
```terminalOutput
pop() -> 20                 stack -> (5, 10, 15)
pop() -> 15                 stack -> (5, 10)
pop() -> 10                 stack -> (5)
pop() -> 5                  stack -> ()
```
2. General Relationship

The stack will fill up by adding values. It shows that the first value added tot he stack will be at the bottom. To remove it all the items above have to be removed. If there are $N$ spaces, $N$ items can be filled by $N$ `push()` operations. The first item is represented by `x1` and the subsequent items are represented by `xN`.

```terminalOutput
push(x1)                    stack -> (x1)
push(x2)                    stack -> (x1, x2)
push(x3)                    stack -> (x1, x2, x3)
...                         ...
push(xN)                    stack -> (x1, x2, x3, ..., xN)
```

By repeatedly popping after pushing items in the stack, the items on the top will come out first. The last item was `xN` which will come out first then `x(N-1)` will come out till `x1` will come out by repeated `pop()` operations. What goes in first, comes out last, or ***Last In, First Out - LIFO***.

```terminalOutput
pop(xN)                    stack -> (x1, ..., x(N-2), x(N-1), xN)
pop(x(N-1))                stack -> (x1, ..., x(N-2), x(N-1))
pop(x(N-2))                stack -> (x1, ..., x(N-2))
...                        ...
pop(x1)                    stack -> (x1)
```

***Why would this be important?*** If we have a stack that has 5 numbers pushed in ascending (highest - lowest) order, we will know that the numbers popped will be in descending (lowest - highest) order because the last item (highest) comes out first. If we get the numbers mixed or in ascending order, we know that there is something wrong with the stack. It is a property of the stack and its is straight forward. The output from popping is $100\%$ predictable because when we push, we know the order so when we pop, the order is reversed, ***predictable***.
## Part 10 — Balanced Delimiters

***Question:*** Write an algorithm to check if the delimiters in the given string are balanced.

***Answer:***

![[Flowchart_Stack.drawio.svg|488]]

## Part 11 — Implement the Balanced-Delimiter Algorithm

To implement the algorithm, I took all the test cases and placed them in a string array  instead of manually changing the string.
```c++
std::string test_inputs[] = {  
    "{(a+b)*[c-d]}",  
    "{(a+b]*c}",  
    "((a+b))",  
    "((a+b)",  
    "[a+b]",  
    "{[()]}",  
    "{[(])}",  
	")[]}"
};
```

Next I looped each string.
```c++
for (string test_input: test_inputs) {  
    ... 
}
```

I created a new stack for each new test case instead of reusing the old stack object. It is so the old results do not accidentally affect the following tests. I sometimes forget to clear stack so its a better way to use a fresh stack instead.
```c++
for (string test_input: test_inputs) {  
    std::stack<char> expression;  // stack
	...
}
```

I looped through each character in the string.
```c++
for (string test_input: test_inputs) {  
    std::stack<char> expression;  
  
	// for each char in string
    for (char test_char: test_input) {  
        ...
    }
    ...
}
```

Now that I have everything ready to test, I print each letter when I am running the program.
```c++
for (string test_input: test_inputs) {  
    std::stack<char> expression;  
  
    for (char test_char: test_input) {  
        std::cout << test_char;  // print letter
  
        ...
    }  
    ...
}
```

Now to test the test cases. I push the char if it is an opening delimiter
```c++
for (string test_input: test_inputs) {  
    std::stack<char> expression;  
  
    for (char test_char: test_input) {  
        std::cout << test_char;  
  
		// is char opening delimiter? push
        if (test_char == '(' || test_char == '{' || test_char == '[') {  
            expression.push(test_char);  
            continue;
        }  
		...
    }  
    ...
}
```

If the stack is empty, we iterate to the next char. If the char is a closing delimiter, we break out of the loop after we add the closing delimiter to the stack. This means the test case doesn't have balanced delimiters.
```c++
for (string test_input: test_inputs) {  
    std::stack<char> expression;  
  
    for (char test_char: test_input) {  
        std::cout << test_char;  
  
        if (test_char == '(' || test_char == '{' || test_char == '[') {  
            expression.push(test_char); 
            continue; 
        }  
  
		// if stack is empty and char is closing delimiter --> break after char is added to stack (it tells that the delimiters aren't balanced)
        if (expression.empty() && (test_char == ')' || test_char == '}' || test_char == ']')) {
		    expression.push(test_char);
		    break;
		}
        ...
    }  
    ...
}
```

Now that most of the cases are handled, we now have the main logic. Pop an opening delimiter if char is the corresponding closing delimiter.
```c++
for (string test_input: test_inputs) {  
    std::stack<char> expression;  
  
    for (char test_char: test_input) {  
        std::cout << test_char;  
  
        if (test_char == '(' || test_char == '{' || test_char == '[') {  
            expression.push(test_char);  
            continue;  
        }  
  
        if (expression.empty() && (test_char == ')' || test_char == '}' || test_char == ']')) {  
            expression.push(test_char);  
            break;  
        }  
  
		// removing opening delimiter for the corresponding closing delimiter
        if (expression.top() == '(' && test_char == ')') {  
            expression.pop();  
        } else if (expression.top() == '{' && test_char == '}') {  
            expression.pop();  
        } else if (expression.top() == '[' && test_char == ']') {  
            expression.pop();  
        }  
    }  
    ...
}
```

If the stack has a $\text{stack size}\neq0$ then the test case was not delimiter balanced.
```terminalOutput
"D:\College\Miramar Community College\Classes\CISC 181 - Data Structures in C++\cisc181\week6\Stack.exe"
{(a+b)*[c-d]}   Stack Size: 0           // Stack Size = 0 --> Balanced
{(a+b]*c}       Stack Size: 2           // Stack Size = 2 --> "(" & "]" Not sure how to fix
((a+b)) Stack Size: 0                   // Stack Size = 0 --> Balanced
((a+b)  Stack Size: 1                   // Stack Size = 1 --> "("
[a+b]   Stack Size: 0                   // Stack Size = 0 --> Balanced
{[()]}  Stack Size: 0                   // Stack Size = 0 --> Balanced
{[(])}  Stack Size: 2                   // Stack Size = 2 --> "[" & "("
)       Stack Size: 1                   // Stack Size = 1 --> ")"

Process finished with exit code 0
```

***Important Cases:***
1. [x] A closing delimiter with no matching opening delimiter.
2. [x] Different delimiter types that do not match.
3. [x] Opening delimiters left in the stack after the expression ends.
4. [x] Correctly nested delimiters.

Because of the confusion, I added a print statement to print each delimiter left in the stack.
```terminalOutput
{(a+b)*[c-d]}   Stack Size: 0
{(a+b]*c}       Stack Size: 2
Stack: ( {

((a+b)) Stack Size: 0
((a+b)  Stack Size: 1
Stack: (

[a+b]   Stack Size: 0
{[()]}  Stack Size: 0
{[(])}  Stack Size: 2
Stack: [ {

)       Stack Size: 1
Stack: )
```

The part that made my question my sanity was:
```terminalOutput
{(a+b]*c}       Stack Size: 2
Stack: ( {
```

But then I remembered that int he stack, the top item was `"("` so when `"}"` was reached, it wasn't able to close. ***I think this is a bug and I don't know how to fix this.***
## Part 12 — Analyze Delimiter Matching

***Questions:***
1. Explain how many times each character is examined? ***Each character in the program was checked once. Because it was looping, there was no place for a char to be examined twice.***
2. Explain why each delimiter is pushed or popped at most once? ***One by one, only one char is being analyzed. So if there is a char that is an opening delimiter, it will add it to the stack. Multiple chars are not analyzed at the same time.***
3. Explain the time complexity of the algorithm? ***The time complexity for the program is $O(N)$ because the more characters, the longer it will take to analyze the string to check if it is balanced.***
4. Explain the worst-case space complexity. ***The worst-case space complexity will be $O(N)$ because each char takes up some space. Each char takes some $b$ bytes and with $N$ chars, it will take $b*N$ bytes.***
## Part 13 — Stack Applications
### Scenario A — Undo
A Stack will be useful because when undoing, we need to undo the most recent change to be able to undo the change we need. So a stack will be useful. Undo is ***LIFO*** so is a stack.

***Answer:*** Stack
### Scenario B — Function Calls
Stack Trace, it is a stack with the names of methods that call another method. The recent one is on the top and the method that started the stack trace sits on the bottom.

***Answer:*** Stack
### Scenario C — Browser Back Navigation
History is a list of websites a person went to. But on a tab, to go back to a tab that was originally viewed, the user has to click the back button many times to go back to the webpage they want to see. So a stack is a good data structure for this.

***Answer:*** Stack
### Scenario D — Depth-First Search
A Tree data structure would be more efficient than a stack. Because this is trying to find paths to different places/unknown places, using a tree will be more useful than a stack. With a stack, only 1 way can be checked at a time. With a tree, many paths can be checked simultaneously.

***Answer:*** Tree
### Scenario E — Customer Service Line
The first come first serve is what I think when I read this problem. The first person comes and gets served before another person who came later. A Queue will be more effective. It is s ***FIFO*** or ***First In, First Out***.

***Answer:*** Queue
## Analysis and Reflection

***Question:*** Based on your implementation and testing, briefly discuss:

1. Why a stack is considered an **Abstract Data Type** rather than a specific physical data structure.
2. Why access is intentionally restricted to the top.
3. How maintaining `topIndex` allows `push()`, `pop()`, and `top()` to operate efficiently.
4. The difference between stack overflow and stack underflow.
5. Why array-based stacks have a fixed capacity unless dynamic storage is introduced.
6. Why stacks naturally support operations such as undo, recursion, backtracking, and delimiter matching.
7. Why a stack is not appropriate when elements must be processed in arrival order.

Connect your answers to the **LIFO** property rather than simply listing stack applications.

***Answers:***
1. An ***abstract data type*** is a data type that is created in memory. It does not physically exist. It was created in memory to store data. 
2. Many times, we would need to go back to the previous step instead of going all the way to the start of the data structure. It is like instructions, the first instruction is needed to complete the next instruction. Because the stack is restricted, it is easier to learn, implement and test.
3. the `topIndex` is a pointer pointing to the most recent item in the stack. If it is not updated, data added would not be accounted for or, data removed would not be accounted for by returning the same item the was supposed to be deleted.
4. Stack Overflow is when an item is trying to be pushed into a stack that is full. It cannot accept new values. Stack Underflow is the opposite, it is trying to retrieve an item from the stack when there is no items in the stack.
5. An array-based stack is basically an array with restricted access via a stack api. So just like an array, if more space is needed, we need it increase it manually and copy paste the data then delete the old stack. Data can be lost or altered by accident. A dynamic stack will help us to extend the limit when some percentage of the stack is filled up. It can also help duplicate the data when extending.
6. Undo operations basically is trying to undo the last operation and put many of those together, we have an undo that has to be dome to undo another undo. If a car is built and there is a defect, all the parts have to be removed methodically, (like undo) in order to fix the problem. Recursion is the same except the method calls itself to do some work. The method call will have some work and a method call and after all the method calls are over each work will be finished. That is a stack behavior. backtracking and delimiters are also the same.
7. If items have to processed in arriving order, a stack is the wrong data type because the last item will be processed first which means the other items that came before will leave and will be delayed. A time sensitive item that comes first would be the last to be process if it was in a stack and could be expired by the time it is processed.
## Resources

1. How to catch [std::overflow_error](https://en.cppreference.com/cpp/error/overflow_error) - cppreference.com