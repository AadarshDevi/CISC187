# Week 1: Data Structure – Arrays

## Table of Contents
1. [Creating an Array](#creating-an-array)
2. [Size of an Element](#size-of-an-element)
3. [Theoretical Steps for Operations on Arrays](#theoretical-steps-for-operations-on-arrays)
   1. [Reading](#reading)
   2. [Searching for Invalid Value](#searching-for-invalid-value)
   3. [Insertion at the start of the Array](#insertion-at-the-start-of-the-array)
   4. [Insertion at the end of the Array](#insertion-at-the-end-of-the-array)
   5. [Deleting at the start of the Array](#deleting-at-the-start-of-the-array)
   6. [Deleting at the end of the Array](#deleting-at-the-end-of-the-array)

## Creating an Array

An array in C++ is created starting with the data type. Here I am using `int`. It is then followed by the identifier
and then by square brackets containing the length of the array. Below is an int array with a size of 100.
```c++
const int ARRAY_LENGTH = 100;

// data_type identifier[array_length]
int array[ARRAY_LENGTH];
```

## Size of an Element

In an array, all the elements have the same size because they are the same datatype. in my array, the datatype is
an `int`. The size of an int in C++ is 4 bytes.

```c++
std::cout << "Size of an int (bytes): " << sizeof(array[0]) << "\n";
```
```terminaloutput
Size of an int (bytes): 4
```

## Theoretical Steps for Operations on Arrays

### Reading

When reading a value from an array, there is only 1 step. This is because there is only 1 operation to read a value
from an array.

**_No of Step:_** 1

```c++
std::cout << "Value at index 0: " << array[0] << "\n";
```

### Searching for Invalid Value

### Insertion at the start of the Array

When adding a value at the start of the array, the values in the array have to shift to the next index so any data in
the array would not be overwritten. the last value moves to the next index. then from right to left, each value moves
to the next index giving space from the new value.

If the array has n values, there will be:

**_No of Step:_** N + 1

N values moved and the new value added at the start.

### Insertion at the end of the Array

Unlike adding values to the start of an array, adding values to the end of the array will not shift any values. a new
value will simply be added to the end of the array.

### Deleting at the start of the Array

### Deleting at the end of the Array