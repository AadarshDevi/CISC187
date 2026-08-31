# Week 1: Data Structure – Arrays

## Table of Contents
1. [Video Explanation](https://youtu.be/VDAtAhWbI9U)
2. [Creating an Array](#1-creating-an-array)
3. [Size of an Element](#2-size-of-an-element)
4. [Theoretical Steps for Operations on Arrays](#3-theoretical-steps-for-operations-on-arrays)
   1. [Reading](#31-reading)
   2. [Searching for Invalid Value](#32-searching-for-invalid-value)
   3. [Insertion at the start of the Array](#33-insertion-at-the-start-of-the-array)
   4. [Insertion at the end of the Array](#34-insertion-at-the-end-of-the-array)
   5. [Deleting at the start of the Array](#35-deleting-at-the-start-of-the-array)
   6. [Deleting at the end of the Array](#36-deleting-at-the-end-of-the-array)
5. [Searching an Array for "apples"](#4-searching-an-array-for-apples)
6. [Address of an Array](#5-address-of-an-array)

## 1. Creating an Array

An array in C++ is created starting with the data type. Here I am using `int`. It is then followed by the identifier
and then by square brackets containing the length of the array. Below is an int array with a size of 100.
```c++
const int ARRAY_LENGTH = 100;

// data_type identifier[array_length]
int array[ARRAY_LENGTH];
```

## 2. Size of an Element

In an array, all the elements have the same size because they are the same datatype. In my array, the datatype is
an `int`. The size of an int in C++ is 4 bytes.

```c++
std::cout << "Size of an int (bytes): " << sizeof(array[0]) << "\n";
```
```terminaloutput
Size of an int (bytes): 4
```

## 3. Theoretical Steps for Operations on Arrays

The array used in the examples below is an `int array[100]` with a size of `100`.

### 3.1 Reading

When reading a value from an array, there is only 1 step. This is because there is only 1 operation to read a value
from an array.

**_No of Step:_** 1

```c++
std::cout << "Value at index 0: " << array[0] << "\n";
```

### 3.2 Searching for Invalid Value

Unsorted values in an array mean that the array has to be iterated on to find the value. If the value is not present
in the array, the:

**_No of Step:_** N

If the array is sorted, based on the search algorithm, the number of steps can vary.

### 3.3 Insertion at the start of the Array

When adding a value at the start of the array, the values in the array have to shift to the next index so any data in
the array would not be overwritten. The last value moves to the next index. Then from right to left, each value moves
to the next index giving space from the new value.

If the array has n values, there will be:

**_No of Step:_** N + 1

N values moved and the new value added at the start.

### 3.4 Insertion at the end of the Array

Unlike adding values to the start of an array, adding values to the end of the array will not shift any values. A new
value will simply be added to the end of the array.

**_No of Step:_** 1

Adding a value to the end of an array takes 1 step.

### 3.5 Deleting at the start of the Array

Just like adding a value at the start of an array moves the values, deleting values at the start of the array will
move the values to a lower index. By deleting at the start, all the values after the deleted value will have to be
moved to a lower index. So this makes:

**_No of Step:_** N - 1

There were n values in the array. 1 value was deleted, leaving N - 1 values that need to be shifted.

### 3.6 Deleting at the end of the Array

Deleting values at the end of the array will not interfere with the other values. Values before the deleted value
will not be affected. This makes the number of steps needed to delete values at the end:

**_No of Step:_** 1

## 4. Searching an Array for "apples"

To find all instances of "apples" in an array, it would normally take:

**_No of Steps:_** N

This is because the array has to be iterated completely to find all instances.

If the array is sorted, a searching algorithm can reduce the number of steps needed to find all instances of "apples".

## 5. Address of an Array

To get the address of an array, print the object to the output.

```c++
std::cout << "Address of array: " << array << "\n";
```
```terminaloutput
Address of array: 0xf0b87ff730
```

But when we are programming, we would need the address of the array. So a way to get it is to use pointers.

```c++
const int ARRAY_LENGTH = 100;
int array[ARRAY_LENGTH];

// ptr stores address of &array
int* ptr = &array[0];

// print address of array
std::cout << "Address of Array: " << ptr << "\n";
```