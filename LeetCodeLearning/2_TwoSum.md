🧠 What is a Hash Map?   ########################################
A Hash Map (called unordered_map in C++) is like a dictionary 📖:

You store key-value pairs.

You can quickly find a value using its key.

🔧 Think of it like:
| Key      | Value |
| -------- | ----- |
| "Apple"  | 50    |
| "Banana" | 30    |
| "Mango"  | 70    |

You say: “What’s the price of Mango?” → You get 70.

This is O(1) on average — very fast.

✅ In C++, use:

#include <unordered_map>
unordered_map<int, int> myMap;

🛠️ Basic Operations
| Operation       | Code                           | Description                 |
| --------------- | ------------------------------ | --------------------------- |
| Insert          | `myMap[key] = value;`          | Add or update key-value     |
| Access          | `myMap[key]`                   | Get value at key            |
| Check if exists | `myMap.count(key)` or `find()` | Returns 1 if exists, else 0 |
| Remove          | `myMap.erase(key);`            | Deletes the key-value pair  |

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> myMap;

    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Mango";

    cout << myMap[2] << endl; // Output: Banana

    if (myMap.count(3)) {
        cout << "Key 3 exists\n";
    }

    return 0;
}

🔍 Why is it Useful for "Two Sum"?
Problem:
Given an array nums and a target value, find two numbers that add up to the target.

👉 Brute force: try all pairs → O(n²) ❌
👉 Smart way: use a hash map → O(n) ✅

🎯 Key Idea:
While iterating:

For each number x, calculate the needed number: target - x.

Check if that needed number is already in the map.

If yes → found the pair!

Great — let's **slow it down even more** and give you a **hands-on feel** for how a `hash_map` (in C++, called `unordered_map`) is working behind the scenes. We’ll build this knowledge step by step.


## 🧪 Tiny Hands-On Practice: Basic `unordered_map`

Let’s write a simple program that adds some key-value pairs and looks them up:


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> m;

    // Insert elements
    m[5] = 100;
    m[10] = 200;

    // Access elements
    cout << "m[5] = " << m[5] << endl;
    cout << "m[10] = " << m[10] << endl;

    // Check if key exists
    if (m.count(15)) {
        cout << "15 exists" << endl;
    } else {
        cout << "15 does not exist" << endl;
    }

    return 0;
}


🔍 Try this in your compiler:

* Add new key-value pairs.
* Try accessing keys that don’t exist.
* Use `count()` to check if a key is present.

---

## 🔨 Now Let’s Simulate the Two Sum Step-by-Step with Manual `unordered_map` Operations

Let’s say:

```cpp
nums = [3, 4, 5]
target = 9
```

We’ll simulate it with a pen and paper / code.

---

### Step 1 (i = 0):

* `nums[0] = 3`
* `needed = 9 - 3 = 6`
* Does 6 exist in `map`? ❌ No
* Add `3:0` to map
  → map is now: `{3: 0}`

---

### Step 2 (i = 1):

* `nums[1] = 4`
* `needed = 9 - 4 = 5`
* Does 5 exist in `map`? ❌ No
* Add `4:1` to map
  → map is now: `{3: 0, 4: 1}`

---

### Step 3 (i = 2):

* `nums[2] = 5`
* `needed = 9 - 5 = 4`
* Does 4 exist in `map`? ✅ Yes, index 1
* Return `{1, 2}`

---

## 🎯 What is the Hash Map Doing?

Let’s visualize the hashmap after each step:

| i | nums\[i] | Needed | Map before insert | Map after insert | Match? |
| - | -------- | ------ | ----------------- | ---------------- | ------ |
| 0 | 3        | 6      | {}                | {3: 0}           | ❌      |
| 1 | 4        | 5      | {3: 0}            | {3: 0, 4: 1}     | ❌      |
| 2 | 5        | 4      | {3: 0, 4: 1}      | ✖ (we return)    | ✅      |

---
