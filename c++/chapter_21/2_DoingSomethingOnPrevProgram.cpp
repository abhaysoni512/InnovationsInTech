#include <bits/stdc++.h>
using namespace std;
template <typename T>
class AutoPtr
{
private:
    T *m_ptr{};
public:
    AutoPtr(T *ptr = nullptr) : m_ptr(ptr) {}
    ~AutoPtr()
    {
        delete m_ptr;
    }
    T* operator->(){
        return m_ptr;
    }
};
class Sample
{
public:
    Sample() { cout << "Sample Const invoked\n"; }
    ~Sample() { cout << "Sample Destructor invoked\n"; }
    void printHi(){
        cout << "Hello\n";
    }
};
void DoSomething(){
    AutoPtr<Sample> ptr{new Sample()};

    int x;
    cout<<"Enter x :";
    cin>>x;

    if(!x) return;

    ptr->printHi();
    

}
int main()
{
    
    DoSomething();
    return 0;
}

/*
    Operator Overloading Explained
    Now, let’s tackle your main question: How does operator overloading work here, and why does ptr-> access Sample class methods instead of AutoPtr class methods?

    What is operator-> Overloading?
    In C++, the arrow operator (->) is typically used with pointers to access members of the object they point to (e.g., pointer->method()). You can overload this operator in a class to define what happens when -> is used on an object of that class. The overloaded operator-> must return either:

    A pointer to another object, or
    An object that itself has an operator-> (though in this case, it’s just a pointer).

    In AutoPtr, the overloaded operator-> is:
        T* operator->() { return m_ptr; }

    - It returns m_ptr, which is a T* (in this program, T is Sample, so it’s a Sample*).
    - This means when you write ptr->something, it’s equivalent to (ptr.operator->())->something.
    - Since ptr.operator->() returns m_ptr (a Sample*), the expression becomes m_ptr->something, which accesses members of the Sample object.

    Why Sample Methods and Not AutoPtr Methods?
        When you use ptr->printHi():

            The -> triggers ptr.operator->(), which returns m_ptr, a pointer to a Sample object.
            The -> then operates on m_ptr, so m_ptr->printHi() calls the printHi() method of the Sample class.
            The AutoPtr class itself doesn’t have a printHi() method, nor does operator-> return a pointer to an AutoPtr object—it returns a pointer to the managed Sample object.

            https://grok.com/chat/918d670d-4c11-4646-972c-b4415059d215
    */
