//shared pointer is a smart pointer that manages the lifetime of a dynamically allocated object.
// It allows multiple shared_ptr instances to share ownership of the same object.
// When the last shared_ptr pointing to the object is destroyed or reset, the object is automatically deleted.
// This prevents memory leaks and makes memory management easier and safer.

#include <iostream>

using namespace std;

int main()
{
    shared_ptr<int> p1(new int(10)); // p1 is a shared pointer's class object that points to an integer with value 10
    shared_ptr<int> p2;
    p2 = p1; // Here p2 is assigned to p1, so both p1 and p2 point to the same memory location
    cout << p1.use_count() << endl; // use_count() returns the number of shared_ptr instances sharing ownership of the same object
    cout << p2.use_count() << endl; // use_count() returns the number of shared_ptr instances sharing ownership of the same object

    p1.reset(); // p1 is reset, so it no longer points to the memory location
    cout << p1.use_count() << endl; // use_count() returns the number of shared_ptr instances sharing ownership of the same object
    cout << p2.use_count() << endl; // use_count() returns the number of shared_ptr instances sharing ownership of the same object
    

    return 0;
}