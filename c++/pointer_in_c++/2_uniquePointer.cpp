// used for memory management
//  unique_ptr is a smart pointer that manages the lifetime of a dynamically allocated object.
//  It ensures that the object is automatically deleted when the unique_ptr goes out of scope.
//  This prevents memory leaks and makes memory management easier and safer.
//  unique_ptr cannot be copied, but it can be moved.
//  This means that you can transfer ownership of the object managed by the unique_ptr to another unique_ptr.
//  This is useful when you want to transfer ownership of a resource between different parts of your program.

#include <iostream>
using namespace std;

auto f1()
{
    unique_ptr<int> p(new int(10)); // p is a unique pointer's class object that points to an integer with value 10
    // p jis memory location ko point kar raha hai jahan par 10 store hai, jaise p destroy ho jayega toh ye memory location bhi destroy ho jayegi
    cout << "Value of p is " << *p << endl;        // dereferencing the pointer
    cout << "Address of p is " << p.get() << endl; // address of the pointer

    // suppose we want to transfer ownership of the object managed by p to another unique_ptr
    unique_ptr<int> p2 = std::move(p); // p2 is a unique pointer's class object that points to an integer with value 10
    // p2 jis memory location ko point kar raha hai jahan par 10 store hai, jaise p2 destroy ho jayega toh ye memory location bhi destroy ho jayegi
    cout << "Value of p2 is " << *p2 << endl;        // dereferencing the pointer
    cout << "Address of p2 is " << p2.get() << endl; // address of the pointer

    cout << "Address of p is " << p.get() << endl; // address of the pointer
    
}
int main()
{
    f1();
    return 0;
}