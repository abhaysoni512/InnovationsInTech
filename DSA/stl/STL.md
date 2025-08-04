# Containers in C++Library (STL)

## Overview
Containers in C++Library (STL) provide a rich set of data structures that are essential for efficient programming. They include various types of collections such as vectors, lists, sets, and maps, each optimized for different use cases.

## Types of Containers
1. Sequence Containers
   - **Vector**: Dynamic array that can grow in size.
   - **Stack**: LIFO (Last In, First Out) data structure.
   - **Queue**: FIFO (First In, First Out) data structure.
   - **Priority Queue**: Elements are served based on priority.
   - **Array**: Fixed-size array with static memory allocation.
2. Ordered Associative Containers(sorted order)
   - **Set**: Collection of unique elements, sorted by default.
   - **Map**: Collection of key-value pairs, where keys are unique and sorted.
   - **Multiset**: Like set, but allows duplicate elements.
   - **Multimap**: Like map, but allows duplicate keys.

3. Unordered Associative Containers(Hashing)
   - **Unordered Set**: Collection of unique elements, not sorted.
   - **Unordered Map**: Collection of key-value pairs, keys are unique and not sorted.

4. Nested Containers
   vectors of vectors, maps of vectors, etc., allowing complex data structures.
   eg: ```cpp
   std::vector<std::vector<int>> matrix;
    ```
5. Specialized Containers
    - **Bitset**: Efficient storage of bits.


# Iterators
  Are similar to pointers, allowing traversal of containers.


#Algorithms
  STL provides a rich set of algorithms that can be applied to containers, such as sorting, searching, and transforming data.
  eg: 1. Upper Bound
      2. Lower Bound
      3. sort
      4. max_element
      5. min_element
      6. reverse
      7. find
      8. count
      9. accumulate

# Functors
    Classes that can be called like functions. They are often used with algorithms to define custom behavior.
    eg: ```cpp
    class Add {
    public:
        int operator()(int a, int b) const {
            return a + b;
        }
    };
