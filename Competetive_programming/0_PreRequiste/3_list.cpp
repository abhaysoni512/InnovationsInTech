//list is same as vector but it is not contiguous
// it is a doubly linked list
// it is not contiguous in memory
// it is not random access
//it provides front and back insertion

#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {1, 2, 3, 4, 5};

    // Using iterator
    std::list<int>::iterator it = myList.begin();
    std::cout << "Using iterator: myList = ";
    for (; it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Using range-based for loop
    std::cout << "Using range-based for loop: myList = ";
    for (auto item : myList) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // erase
    std::list<int> myList2 = {1, 2, 3, 4, 5};
    std::cout << "myList2 = ";
    for (auto item : myList2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    myList2.erase(myList2.begin()); // erase the first element
    std::cout << "After erase: myList2 = ";
    for (auto item : myList2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    //insert
    std::list<int> myList3 = {1, 2, 3, 4, 5};
    std::cout << "myList3 = ";
    for (const auto &item : myList3) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    myList3.insert(myList3.begin(), 0); // insert 0 at the beginning
    myList3.push_front(-1); // insert -1 at the front
    for(const auto &item : myList3) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}