
#include <iostream>
#include <random>

int main() {

	// length of array
	const int ARRAY_LENGTH = 100;

	// create an array containing 100 ints
	int array[ARRAY_LENGTH];

	// size of an int in C++
	std::cout << "Size of an int (bytes): " << sizeof(array[0]) << "\n";

	std::cout << "Address of array: " << array << "\n";

	int* ptr = &array[0];

	std::cout << "Address of array: " << ptr << "\n";
}

/*
 * Array in C++: https://www.geeksforgeeks.org/cpp/cpp-arrays/
 * Size of int: https://www.geeksforgeeks.org/cpp/cpp-sizeof-operator/
 */