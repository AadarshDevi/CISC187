# Week 5: Hash Tables

> [!NOTE]
> **Google Gemini** was used to help me fix pointer and address problems because I was having a very hard time with
> them.

## Table of Contents

1. [Part 1 - Understanding Hash Functions](#part-1---understanding-hash-functions)
    - [Analysis](#analysis)
2. [Part 2 - Implement a Hash Function](#part-2---implement-a-hash-function)
3. [Part 3 - Build a HashTable](#part-3---build-a-hash-table)
    1. [Class HashTable](#class-hashtable)
    2. [Testing Class](#testing)
4. [Part 4 - Linear Probing](#part-4---linear-probing)
    1. [Output](#output)
    2. [Class: HashTable](#class-hashtable-1)
5. Part 6 - Home Position and Actual Position
    6. [Analysis](#analysis-1)
6. [Part 6 - Searching with Linear Probing](#part-6--)
7. Part 7 - Deletion and Tombstones
8. Part 8 - Load Factor
9. Part 9 - Hash Function Quality
10. Part 10 - Complexity Analysis
11. Part 11 - Hashing vs. Encryption
12. Part 12 - Cryptographic and Non-Cryptographic Hashing
13. Part 13 - Applications and Limitations
14. Analysis & Reflection

## Part 1 - Understanding Hash Functions

The hash function for this section is to add each digit and mod 10 it.

1. 555223: $5+5+5+2+2+3=22$ then $22\space \%\space 10=2$
2. 555980: $5+5+5+9+8+0=32$ then $32\space \%\space 10=2$
3. 555000: $5+5+5+0+0+0=15$ then $15\space \%\space 10=5$
4. 555890: $5+5+5+8+9+0=32$ then $32\space \%\space 10=2$

|  Key   | Digital Sum | Table Index |
| :----: | :---------: | :---------: |
| 555223 |     22      |      2      |
| 555980 |     32      |      2      |
| 555000 |     15      |      5      |
| 555890 |     32      |      2      |

### Analysis

There were 3 keys that generated the same index. They are 555223, 555980, and 555890 which generated the table index 2.
Because these three have generated the same index, they collide. This is called a **_collision_**. Here we
use $\%\space 10$ because our hash table has 10 indies from zero to nine. If our hash table had 20 indices, we would
do $\%\space 20$ instead. Increasing the number of indices will lower the possibility of collisions happening but, it
cannot eliminate it. It will increase the number of possible index outputs, but there can be few keys that can end up
having the same index in the table.

## Part 2 - Implement a Hash Function

Create a hash function that takes an int as the key and does digit sum and gets the table index.

1. Input: Key (int), Table Size (int)
2. Process: Digital Sum, Index
3. Output: Index (int)

```c++
int hashFunction(int key, int tableSize) {
    int digit_sum = 0;
    for (int i = 0; i < INT_MAX; i++) {
        int digit = key % 10; // get last digit
        digit_sum += digit; // add to sum
        key = key / 10; // remove the last digit which is now 0
        if (key == 0) break; // escapes if key = 0
    }
    return digit_sum % tableSize; // index = digital_sum % table_size
}
```

It is not a while loop because if the function fails, there will be a hard loop exit. Below are the outputs for the keys
using the hashFunction and manually calculating the index.

|  Key   | Manual Calculation | Hash Function |
|:------:|:------------------:|:-------------:|
| 555223 |         2          |       2       |
| 555980 |         2          |       2       | 
| 555000 |         5          |       5       |
| 555890 |         2          |       2       |

## Part 3 - Build a Hash Table

HashTable class should be able to the below operations on the Records:

1. Place
2. Search
3. Delete (Key)
4. Delete (Record)

### Class: HashTable

This is my HashTable class. After many pointer and address problems, I have done it. There are 2 methods to delete an
item, one uses the record object and the other uses the key.

```c++
#include <iostream>
#include <string>
#include <climits>
#include <vector>

class HashTable {
private:
    const int DEFAULT_SIZE = 11;
    int table_size = DEFAULT_SIZE;
    std::vector<std::vector<Record> > *hash_table;

public:
    HashTable(int table_size) {
        if (table_size > 0) this->table_size = table_size; // makes sure size is not 0 or negative

        // table_size already has a default so no need to change if the length is 0 ir less

        // create hash_table
        hash_table = new std::vector<std::vector<Record> >(this->table_size);
    }

    // Deconstructor
    ~HashTable() {
        // delete the vector created
        delete hash_table;
    }

    int hashFunction(int key) {
        int digit_sum = 0;
        for (int i = 0; i < INT_MAX; i++) {
            int digit = key % 10; // get last digit
            digit_sum += digit; // add to sum
            key = key / 10; // remove the last digit which is now 0
            if (key == 0) break; // escapes if key = 0
        }
        return digit_sum % table_size; // index = digital_sum % table_size
    }

    bool add(Record record) {
        const int index = hashFunction(record.key); // get table_index
        hash_table->at(index).push_back(record); // place record in the vector with the table_index
        return true;
    }

    Record *get(int key) {
        const int index = hashFunction(key);
        std::vector<Record> &record_vector = hash_table->at(index);
        for (int i = 0; i < record_vector.size(); i++) {
            if (record_vector[i].key == key) {
                return &record_vector[i];
            }
        }
        return nullptr;
    }

    bool remove(int key) {
        const int index = hashFunction(key);
        std::vector<Record> &record_vector = hash_table->at(index);
        for (int i = 0; i < record_vector.size(); i++) {
            if (record_vector[i].key == key) {
                record_vector.erase(record_vector.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool remove(Record record) {
        const int index = hashFunction(record.key);
        std::vector<Record> &record_vector = hash_table->at(index);
        for (int i = 0; i < record_vector.size(); i++) {
            if (record_vector[i].key == record.key) {
                record_vector.erase(record_vector.begin() + i);
                return true;
            }
        }
        return false;
    }

    void printData() {
        std::cout << "\nPrinting Data:\n";
        for (int i = 0; i < table_size; i++) {
            std::vector<Record> record_vector = hash_table->at(i);
            if (record_vector.empty()) continue;
            std::cout << "i = " << i << ": ";
            for (Record record: record_vector) {
                std::cout << record.value << "\t";
            }
            std::cout << "\n";
        }
    }
};
```

### Testing

Testing this class was how those pointer and address problems were fixed. Below is the test suite.

```c++
int main() {
    HashTable hash_table(10);

    Record record1{.key = 555223, .value = "Student_C"};
    hash_table.add(record1);

    Record record2{.key = 555980, .value = "Student_G"};
    hash_table.add(record2);

    Record record3{.key = 555000, .value = "Student_A"};
    hash_table.add(record3);

    Record record4{.key = 555890, .value = "Student_L"};
    hash_table.add(record4);

    hash_table.printData();

    hash_table.remove(555890);

    hash_table.printData();

    hash_table.remove(record1);

    hash_table.printData();

    Record *record5 = hash_table.get(555890);
    std::cout << "\nPrinting Record: " << record5 << "\n";

    Record *record6 = hash_table.get(555980);
    std::cout << "\nPrinting Record: " << record6->value << "\n";

    std::cout << "\n";
    return 0;
}
```

## Part 4 - Linear Probing

Now that we have an existing HashTable class, we will now use linear probing instead of using multiple vectors. First is
changing add to insert for probing. The entire class's methods were rewritten for probing. The same test suite is used.

My loop will not go into an infinite loop because it uses the current index and the size of the hash_table to loop
through each index once. if it doesn't find an empty place, it will return false for not being able to place the record.

### Output

|  Key   | Calculated Index | Actual Index |
|:------:|:----------------:|:------------:|
| 555223 |        2         |      2       |
| 555980 |        2         |      3       |
| 555000 |        3         |      5       |
| 555890 |        2         |      4       |

```terminaloutput
i = 2   a_i = 2         Student_C
i = 2   a_i = 3         Student_G
i = 5   a_i = 5         Student_A
i = 2   a_i = 4         Student_L

Printing Data:
i = 2: Student_C
i = 3: Student_G
i = 4: Student_L
i = 5: Student_A
a_i = 2         Student_L

Printing Data:
i = 2: Student_C
i = 3: Student_G
i = 5: Student_A

Printing Data:
i = 3: Student_G
i = 5: Student_A

Printing Record: 0
a_i = 2         Student_G

Printing Record: Student_G
```

### Class: HashTable

```c++
#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <optional>


struct Record {
    int key;
    std::string value;
};

class HashTable {
private:
    const int DEFAULT_SIZE = 11;
    int table_size = DEFAULT_SIZE;
    std::vector<std::optional<Record> > hash_table;
    // float DEFAULT_GROWING_THRESHOLD = 0.75;
    // float growing_threshold = DEFAULT_GROWING_THRESHOLD;
    int element_count = 0;

public:
    HashTable(int table_size, float growing_threshold) {
        if (table_size > 0) this->table_size = table_size; // makes sure size is not 0 or negative
        // if (growing_threshold > 0) this->growing_threshold = growing_threshold;
        // makes sure factor is not 0 or negative

        // table_size already has a default so no need to change if the length is 0 ir less

        // create hash_table
        hash_table = std::vector<std::optional<Record> >(this->table_size);
    }

    HashTable(int table_size) {
        if (table_size > 0) this->table_size = table_size; // makes sure size is not 0 or negative

        // table_size already has a default so no need to change if the length is 0 ir less

        // create hash_table
        hash_table = std::vector<std::optional<Record> >(this->table_size);
    }

    int hashFunction(int key) const {
        int digit_sum = 0;
        for (int i = 0; i < INT_MAX; i++) {
            int digit = key % 10; // get last digit
            digit_sum += digit; // add to sum
            key = key / 10; // remove the last digit which is now 0
            if (key == 0) break; // escapes if key = 0
        }
        return digit_sum % table_size; // index = digital_sum % table_size
    }

    bool insert(Record record) {
        // calculate home position
        const int index = hashFunction(record.key);
        std::cout << "i = " << index << "\t";

        // is position empty or not
        if (!hash_table.at(index).has_value()) {
            //std::cout << "Empty Space: Now Occupying\t" << record.value << "\n";
            std::cout << "a_i = " << index << "\t\t" << record.value << "\n";
            hash_table.at(index) = record;
            return true;
        }

        // probe for new index
        for (int i = 1; i < table_size; i++) {
            // new index
            int shifted_index = index + i;

            // index wrapped if shifted_index <= table size
            if (shifted_index >= table_size) shifted_index -= table_size;

            // calculate new index
            int actual_index = shifted_index % table_size;
            //std::cout << "Actual Index: " << actual_index << "\t\t\t";

            // check if the new index is occupied
            if (!hash_table.at(actual_index).has_value()) {
                //std::cout << "Actual Index: Now Occupied\t" << record.value << "\n";
                std::cout << "a_i = " << actual_index << "\t\t" << record.value << "\n";
                hash_table.at(actual_index) = record;
                // hash_table
                return true;
            }
        }
        std::cout << "\n";
        return false;
    }

    Record *get(int key) {
        const int index = hashFunction(key);

        if (hash_table.at(index).has_value() && hash_table.at(index).value().key == key) {
            return &hash_table.at(index).value();
        }

        for (int i = 1; i < table_size; i++) {
            // new index
            int shifted_index = index + i;

            // index wrapped if shifted_index <= table size
            if (shifted_index >= table_size) shifted_index -= table_size;

            // calculate new index
            int actual_index = shifted_index % table_size;

            // check if the new index is occupied
            if (hash_table.at(actual_index).has_value() && hash_table.at(actual_index).value().key == key) {
                std::cout << "a_i = " << index << "\t\t" << hash_table.at(actual_index).value().value << "\n";
                return &hash_table.at(actual_index).value();
            }
        }

        return nullptr;
    }

    bool remove(int key) {
        const int index = hashFunction(key);

        if (hash_table.at(index).has_value() && hash_table.at(index).value().key == key) {
            hash_table.at(index).reset();
            return true;
        }

        for (int i = 1; i < table_size; i++) {
            // new index
            int shifted_index = index + i;

            // index wrapped if shifted_index <= table size
            if (shifted_index >= table_size) shifted_index -= table_size;

            // calculate new index
            int actual_index = shifted_index % table_size;

            // check if the new index is occupied
            if (hash_table.at(actual_index).has_value() && hash_table.at(actual_index).value().key == key) {
                std::cout << "a_i = " << index << "\t\t" << hash_table.at(actual_index).value().value << "\n";
                hash_table.at(actual_index).reset();
                // hash_table
                return true;
            }
        }
        return false;
    }

    bool remove(Record record) {
        const int index = hashFunction(record.key);

        if (hash_table.at(index).has_value() && hash_table.at(index).value().key == record.key) {
            hash_table.at(index).reset();
            return true;
        }

        for (int i = 1; i < table_size; i++) {
            // new index
            int shifted_index = index + i;

            // index wrapped if shifted_index <= table size
            if (shifted_index >= table_size) shifted_index -= table_size;

            // calculate new index
            int actual_index = shifted_index % table_size;

            // check if the new index is occupied
            if (hash_table.at(actual_index).has_value() && hash_table.at(actual_index).value().key == record.key) {
                std::cout << "a_i = " << index << "\t\t" << hash_table.at(actual_index).value().value << "\n";
                hash_table.at(actual_index).reset();
                // hash_table
                return true;
            }
        }
        return false;
    }

    void printData() {
        std::cout << "\nPrinting Data:\n";
        if (hash_table.empty()) return;
        for (int i = 0; i < table_size; i++) {
            if (!hash_table.at(i).has_value()) {
                continue;
            }
            std::cout << "i = " << i << ": ";
            std::cout << hash_table.at(i).value().value << "\t";
            std::cout << "\n";
        }
    }
};
```

## Part 5 -Home Position and Actual Position

I already had a method to display the entire hash table, I modified it so i can show all the vales for each record.

```c++
void printData() {
   std::cout << "\nPrinting Data:\n";
   if (hash_table.empty()) return;
   for (int i = 0; i < table_size; i++) {
      if (!hash_table.at(i).has_value()) {
         continue;
      }
      std::cout << "calculated_index = " << hashFunction(hash_table.at(i).value().key) << "\t";
      std::cout << "actual_index = " << i << "\t";
      std::cout << "(key : value) >> " << hash_table.at(i).value().key << " : ";
      std::cout << "" << hash_table.at(i).value().value;
      std::cout << "\n";
   }
}
```

```terminaloutput
calculated_index = 2    actual_index = 2        (key : value) >> 555223 : Student_C
calculated_index = 2    actual_index = 3        (key : value) >> 555980 : Student_G
calculated_index = 2    actual_index = 4        (key : value) >> 555890 : Student_L
calculated_index = 5    actual_index = 5        (key : value) >> 555000 : Student_A
```

### Analysis

A key might not be in the index it was calculated for if there was a value that was already in that index. And because
of linear probing, we would check the next index till we find an empty space to place the record. Linear probing is
simpler because of the small dataset, if it were big, it would take a long time to place the record in an empty index.

## Part 6 - Searching with Linear Probing

I had a get method for searching and was modified to use clustering to stop going through all t=data in hashtable. I
simplified some statements too.

```c++
Record *get(int key) {  
    const int index = hashFunction(key);  
    std::cout << "Index Calculated: " << index << "\n";  
    int positions_checked = 0;  
  
    if (hash_table.at(index).has_value() && hash_table.at(index).value().key == key) {  
        std::cout << "Positions Checked: 1" << "\n";  
        std::cout << "Actual Index: " << index << "\n";  
        return &hash_table.at(index).value();  
    }  
  
    for (int i = 1; i < table_size; i++) {  
        // calculate new index  
        int actual_index = (index + i) % table_size;  
        positions_checked++;  
  
        // check if the new index is occupied  
        if (!hash_table.at(actual_index).has_value()) {  
            std::cout << "Positions Checked: " << positions_checked << "\n";  
            return nullptr;  
        }  
  
        if (hash_table.at(actual_index).value().key == key) {  
            std::cout << "Positions Checked: " << (i + 1) << "\n";  
            std::cout << "Actual Index: " << actual_index << "\n";
            return &hash_table.at(actual_index).value();  
        }  
    }  
  
    std::cout << "Positions Checked: " << positions_checked << "\n";  
    return nullptr;  
}
```

### Output

```terminaloutput
i = 2   a_i = 2         Student_C
i = 2   a_i = 3         Student_G
i = 5   a_i = 5         Student_A
i = 2   a_i = 4         Student_L

Printing Data:
calculated_index = 2    actual_index = 2        (key : value) >> 555223 : Student_C
calculated_index = 2    actual_index = 3        (key : value) >> 555980 : Student_G
calculated_index = 2    actual_index = 4        (key : value) >> 555890 : Student_L
calculated_index = 5    actual_index = 5        (key : value) >> 555000 : Student_A

Index Calculated: 2       // Displaced
Positions Checked: 3
Actual Index: 4
Calculated Index: 2
Printing Record: Student_L

Index Calculated: 5       // Home-positioned
Positions Checked: 1
Actual Index: 5
Calculated Index: 5
Printing Record: Student_A

Index Calculated: 4       // Not In Dataset
Positions Checked: 2
Calculated Index: 4
Printing Record: No Record Exists With key - 555496
```

|   Search Type   | Key Position | Actual Key Position  | Positions Checked |
|:---------------:|:------------:|:--------------------:|:-----------------:|
| Home-positioned |      5       |          5           |         1         |
|    displaced    |      2       |          4           |         3         |
| not in dataset  |      5       | 0 (Record Not Found) |                   |

## Resources

1. Hash Table: [Learn Hash Tables in 13 minutes](https://www.youtube.com/watch?v=FsfRsGFHuv4) - Bro Code
2. Hash Table: [Data Structures in C++ - Hash Tables](https://www.youtube.com/watch?v=Wbdw5ucmHic) - Solbyte
3. Linear
   Probing: [Linear Probing in Hashing Animations | Data Structure | Visual How](https://www.youtube.com/watch?v=2F8qXwVW3ds) -
   Visual How
4. Linear Probing: [L-6.4: Linear Probing in Hashing with example](https://www.youtube.com/watch?v=ZEyPqqRTO00) - Gate
   Smashers
5. Vectors: (Different Approaches to Initialize a Vector in
   C++)[https://medium.com/@pawara/different-approaches-to-initialize-a-vector-in-c-fe7342b5bda6] - Medium
6. Vector of
   Vectors: [Vector of Vectors in C++ STL with Examples](https://www.geeksforgeeks.org/cpp/vector-of-vectors-in-c-stl-with-examples/) -
   GeeksForGeeks
7. Vector Operations: [Vector in C++ STL](https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/) - GeeksForGeeks
8. Null
   Return: [Returning a "NULL reference" in C++?](https://stackoverflow.com/questions/10371094/returning-a-null-reference-in-c) -
   Stack Overflow
9. Linear Probing Algorithm on
   HashTable: [Hashing – Linear Probing](https://www.baeldung.com/cs/hashing-linear-probing) - Baeldung
10. Optional: [std::optional in C++](https://medium.com/@saadurr/std-optional-in-c-ca6e5a5d52d6) - Medium

## Extra

### Hashing Function

#### Version 1: Too Complicated

I had no idea what I was doing. I somehow got it working for the test cases but it isn't the best.

```c++
int hashFunction(int key, int tableSize) {
    int lastNum = 0;
    int sum = 0;
    int remainder = -1;
    int value = 0;
    int digit = 0;
    // std::cout << lastNum << '\n';
    for (int i = 1; i < 10; i++) {
        remainder = (key % (int) pow(10, i));
        std::cout << "rem: " << remainder;

        value = remainder - lastNum;
        std::cout << ", val: " << value;

        digit = value / pow(10, i - 1);
        std::cout << ", digit: " << digit;

        lastNum = remainder;
        std::cout << ", last: " << lastNum << '\n';

        sum += digit;
    }
    std::cout << "Sum: " << sum << "\n\n";

    return 0;
}
```

#### Version 2: Better

I was talking to my dad, who told me that my way was too complicated and forced my to figure out an easier way to get
the digits from the key.

```c++
int hashFunction(int key, int tableSize) {
    int digit_sum = 0;
    for (int i = 0; i < INT_MAX; i++) {
        int digit = key % 10; // get last digit
        digit_sum += digit; // add to sum
        key = key / 10; // remove the last digit which is now 0
        if (key == 0) break; // escapes if key = 0
    }
    return digit_sum % tableSize; // index = digital_sum % table_size
}
```

#### Version 2.1: Class-ified

Changed the header to be suitable for HashTable class.

```c++
int hashFunction(int key) {
   int digit_sum = 0;
   for (int i = 0; i < INT_MAX; i++) {
      int digit = key % 10; // get last digit
      digit_sum += digit; // add to sum
      key = key / 10; // remove the last digit which is now 0
      if (key == 0) break; // escapes if key = 0
   }
   return digit_sum % table_size; // index = digital_sum % table_size
}
```