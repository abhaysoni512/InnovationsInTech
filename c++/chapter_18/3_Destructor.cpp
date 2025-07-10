/*
    The destructor must have the same name as the class, preceded by a tilde (~).
    The destructor can not take arguments.
    The destructor has no return type.
*/

#include <iostream>
using namespace std;
class DoSomething
{
private:
    int m_value;
public:
    DoSomething(int value) : m_value(value)
    {
        cout << "Constructor called with value: " << m_value << endl;
    }

    ~DoSomething()
    {
        cout << "Destructor called for value: " << m_value << endl;
    }
};
int main()
{
    DoSomething *ptr = new DoSomething(10);
    delete ptr; // Explicitly calling the destructor by deleting the object
    // Note: The destructor will be called automatically when the object is deleted.
    // If you don't delete the object, the destructor won't be called, leading to a memory leak.
    
    return 0;
}