// unordered_set is an unordered associative container that stores unique elements

#include <unordered_set>
#include <iostream>

using namespace std;

int main()
{
    // declaring an unordered set
    unordered_set<int> uset;
    // inserting elements into the unordered set
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(40); // duplicate element, will not be inserted

    // printing the elements of the unordered set
    cout << "Elements of the unordered set are: ";
    for (auto it = uset.begin(); it != uset.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // or using range-based for loop
    cout << "Elements of the unordered set are: ";
    for (auto element : uset)
    {
        cout << element << " ";
    }
    cout << endl;

    // checking if an element is present in the unordered set
    int key = 20;
    if (uset.find(key) != uset.end())
    {
        cout << key << " is present in the unordered set." << endl;
    }
    else
    {
        cout << key << " is not present in the unordered set." << endl;
    }

    // removing an element from the unordered set
    uset.erase(key);
    cout << "Elements of the unordered set after removing " << key << " are: ";
    for (auto it = uset.begin(); it != uset.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //acessing elements using iterators
    cout << "Third Element of the unordered set using iterators are: ";
    auto it = next(uset.begin(), 2); // accessing the third element
    cout << *it << endl;

}