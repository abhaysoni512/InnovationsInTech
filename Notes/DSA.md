********* Data Structures **********
Note: These Notes are from youtube Channel's playlist "Data structures playlist by William Fiset"
Link: 
https://youtube.com/playlist?list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&si=3SvpV029dFKw6bME

1. Data Structures Basics :

A data structure is a way of organizing and storing data in a computer so that it can be accessed and modified efficiently.

Abstract Data types vs Data Structures:

- ADT provides is an abstraction of a data structure, defining the operations that can be performed on it without specifying how these operations are implemented.
- Examples
    ADTs         Implementation
    List        Array, Linked List
    Queue       Array, Linked List based Queue, Stack based Queue
    Map        Hash Table, Tree Map
    Vehicle    Car, Bike, Truck

2. Computional Complexity Analysis:

Big O Notation:
Big -O notation is a mathematical notation that describes the upper bound(worst case) of an algorithm's running time or space requirements in terms of the size of the input data.

It provides a high-level understanding of the algorithm's efficiency and scalability.

Common Big O Notations: (where n is the size of the input data)
- O(1): Constant time - The algorithm's running time does not change with the size of the input data.
- O(log n): Logarithmic time - The algorithm's running time grows logarithmically with the size of the input data.
- O(n): Linear time - The algorithm's running time grows linearly with the size of the input data.
- O(n log n): Linearithmic time - The algorithm's running time grows in a linearithmic manner with the size of the input data.
- O(n^2): Quadratic time - The algorithm's running time grows quadratically with the size of the input data.
- O(2^n): Exponential time - The algorithm's running time grows exponentially with the size of the input data.
- O(n!): Factorial time - The algorithm's running time grows factorially with the size of the input data.

Classic Examples:

- Finding all subsets of a set :  o(2^n)
- Finding the maximum element in an array : O(n)
- Finding all permutation of a string : O(n!)
- Sorting Use merge sort : O(n log n)
- Searching in a list : O(n)

3. Static and Dynamic Arrays:

Static Arrays:
- fixed length container that holds a fixed number of elements of the same type.

when and where static arrays are used:
i. Storing and acessing sequential data.
ii. Storing temporary objects.
iii. Used by IO routines to store data.
iv. Looking up values in a table.
v. Used in dp to cahche results of subproblems.

Complexity:
             Static Array        Dynamic Array
Access        O(1)               O(1)
Search        O(n)               O(n)
Insertion     N/A                O(n)
Deletion      N/A                O(n)
Append        N/A                O(1) amortized


       