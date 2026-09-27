# Week 5: Hash Tables

## Table of Contents

1. Part I
    - Analysis
2. Part II
3. Part III
4. Part IV
5. Part V

## Part 1 - Understanding Hash Functions

The hash function for this section is to add each digit and mod 10 it.

1. 555223: $5+5+5+2+2+3=22$ then $22\space \%\space 10=2$
2. 555980: $5+5+5+9+8+0=32$ then $32\space \%\space 10=2$
3. 555000: $5+5+5+0+0+0=15$ then $15\space \%\space 10=5$
4. 555890: $5+5+5+8+9+0=32$ then $32\space \%\space 10=2$

|  Key   | Digital Sum | Table Index |
|:------:|:-----------:|:-----------:|
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

```c++
int hasFunction(int key, int tableSize) {
    
}
```

## Resources

1. Hash Table: [Learn Hash Tables in 13 minutes](https://www.youtube.com/watch?v=FsfRsGFHuv4) - Bro Code
2. Hash Table: [Data Structures in C++ - Hash Tables](https://www.youtube.com/watch?v=Wbdw5ucmHic) - Solbyte
3. Linear
   Probing: [Linear Probing in Hashing Animations | Data Structure | Visual How](https://www.youtube.com/watch?v=2F8qXwVW3ds) -
   Visual How
4. Linear Probing: [L-6.4: Linear Probing in Hashing with example](https://www.youtube.com/watch?v=ZEyPqqRTO00) - Gate
   Smashers
5. 