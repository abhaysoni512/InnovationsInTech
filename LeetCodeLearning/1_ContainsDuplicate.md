#1
🧠 What is a Hash Set?
Think of a hash set like a magical box 📦 where:

You can store items.

You can check quickly if something is already inside.

Duplicates are not allowed.

This means if you try to add the same item again, it won't be added again. It's like a collection that only keeps unique items!

🛠️ In Programming Terms
In C++, we use:

cpp
Copy
Edit
#include <unordered_set>
A std::unordered_set<int> is a set that:

Stores unique integers.

Uses hashing internally to find elements quickly.

| Operation       | Code                        | Description                         |
| --------------- | --------------------------- | ----------------------------------- |
| Create set      | `unordered_set<int> s;`     | Make an empty set                   |
| Add value       | `s.insert(5);`              | Adds 5 to the set                   |
| Check if exists | `s.count(5)` or `s.find(5)` | Returns `1` if 5 exists, `0` if not |
| Size of set     | `s.size();`                 | Returns number of elements          |


🧪 Example Code
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Duplicate — won't be added again

    cout << "Size: " << mySet.size() << endl; // Output: 3

    if (mySet.count(20)) {
        cout << "20 exists in the set\n";
    }

    if (!mySet.count(40)) {
        cout << "40 does NOT exist in the set\n";
    }

    return 0;
}


#2 what is difference between unordered set vs order set

🔄 set vs unordered_set in C++
| Feature                  | `set`                         | `unordered_set`               |
| ------------------------ | ----------------------------- | ----------------------------- |
| **Order of elements**    | Sorted (ascending by default) | No order (random)             |
| **Underlying structure** | Red-Black Tree (Balanced BST) | Hash Table                    |
| **Time complexity**      | O(log n) for insert/find      | O(1) average, O(n) worst-case |
| **Duplicates**           | Not allowed                   | Not allowed                   |
| **Header file**          | `<set>`                       | `<unordered_set>`             |

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    set<int> s = {5, 1, 10, 3};
    unordered_set<int> us = {5, 1, 10, 3};

    cout << "Set (ordered): ";
    for (int x : s) cout << x << " ";  // Output: 1 3 5 10

    cout << "\nUnordered Set: ";
    for (int x : us) cout << x << " "; // Output: Order is not guaranteed

    return 0;
}
| Use Case                                   | Use `set` | Use `unordered_set`  |
| ------------------------------------------ | --------- | -------------------- |
| You need **elements in sorted order**      | ✔️        | ❌                    |
| You only care about **fast lookup/insert** | ❌ (log n) | ✔️ (O(1) average)    |
| You want **predictable iteration order**   | ✔️        | ❌                    |
| Your data type **doesn’t support hashing** | ✔️        | ❌ (hashing required) |



Contains Duplicate:

#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> seen;
        for (int num : nums){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

Only thing to remember is that unordered set is used to store unique elements and it has O(1) average time complexity for insert and find operations. It is a good choice when you need to check for duplicates in a collection of items quickly.

seen.count checks if the element exists in the set, returning 1 if it does and 0 if it doesn't. If it exists, we return true indicating a duplicate was found. If we finish checking all elements without finding duplicates, we return false.

