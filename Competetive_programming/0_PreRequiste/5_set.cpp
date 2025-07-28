#include <iostream>
#include <set>

using namespace std;

int main() {
    // Set
    // set is a collection of unique elements
    // it is implemented as a balanced binary search tree
    // it is sorted in ascending order by default (sorted set)
    // it is not random access
    // it provides front and back insertion
    // it provides O(log n) time complexity for insertion, deletion, and search
    set<int> mySet = {1, 2, 3, 4, 5};

    cout << "mySet = ";
    for (auto item : mySet) {
        cout << item << " ";
    }
    cout << endl;

    // insert
    mySet.insert(6);
    mySet.insert(7);
    cout << "After insert: mySet = ";
    for (auto item : mySet) {
        cout << item << " ";
    }
    cout << endl;

    // find
    auto it = mySet.find(3);
    if (it != mySet.end()) {
        cout << "Found: " << *it << endl;
    } else {
        // if the element is not found in the set it will return end() means last element ke baad
        cout << "Not found" << endl;
    }

    // erase
    mySet.erase(3);
    cout << "After erase: mySet = ";
    for (const auto &item : mySet) {
        cout << item << " ";
    }
    cout << endl;

    int count = mySet.count(4);
    cout << "Count of 4: " << count << endl;
    // set is a collection of unique elements
    // if we try to insert duplicate element it will not be inserted
    // so either 1 or 0 will be returned

    // erase in a range
    mySet.erase(mySet.find(1), mySet.find(2));
    cout << "After erase in a range: mySet = ";
    for (const auto &item : mySet) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}