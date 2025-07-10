/* A Smart pointer is a composition class that is designed to manage dynamically allocated memory and ensure that memory gets deleted when the smart pointer object goes out of scope. 
*/

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class AutoPtr{
private:
    T *m_ptr{};
public:
    AutoPtr(T *ptr = nullptr):m_ptr(ptr){}
    ~AutoPtr(){
        delete m_ptr;
    }
};
class Sample{
public:
    Sample(){ cout<<"Sample Const invoked\n";}
    ~Sample(){ cout<<"Sample Destructor invoked\n";}

};
int main(){
    AutoPtr <Sample> res {new Sample()};

    return 0;
}

/*
How the Program Works: Step-by-Step Execution
1. Inside main: Creating the Smart Pointer
The key line in main is:
    Auto_ptr1<Resource> res(new Resource());

Here’s what happens:

    new Resource():
        This dynamically allocates memory for a Resource object using the new operator.
        As part of object creation, the Resource constructor is called, printing "Resource acquired\n".
        The new expression returns a pointer to the newly created Resource object, of type Resource*.
    Auto_ptr1<Resource> res:
        This creates an object res of type Auto_ptr1<Resource>.
        The Auto_ptr1 constructor is invoked, taking the Resource* pointer from new Resource() as its argument.
        Inside Auto_ptr1, the member m_ptr (of type T*, where T is Resource, so Resource*) is initialized to point to this Resource object.
        At this point, res owns the Resource object, and no further action happens in main before it ends.

2. End of main: Automatic Cleanup
    When main finishes, the res object goes out of scope because it’s a local variable.
    When an object goes out of scope, its destructor is automatically called.
    For res, this means the Auto_ptr1<Resource> destructor runs:
        ~Auto_ptr1() { delete m_ptr; }
    What delete m_ptr does:
        m_ptr points to the Resource object created earlier.
        delete m_ptr deallocates the memory for that object.
        Deallocation triggers the Resource destructor, which prints "Resource destroyed\n".
    https://grok.com/chat/e0e84249-185b-42ef-b97f-d462264a52db
*/
