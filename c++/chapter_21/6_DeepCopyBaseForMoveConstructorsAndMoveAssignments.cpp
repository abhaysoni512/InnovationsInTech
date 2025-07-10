#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Auto_ptr3
{
    T *m_ptr{};
    std::string m_name; // added

public:
    Auto_ptr3(T *ptr = nullptr, std::string name = "")
        : m_ptr(ptr), m_name(name)
    {
        cout << "Constructor called for object: " << m_name
             << " at " << this << endl;
    }

    ~Auto_ptr3()
    {
        cout << "Destructor called for object: " << m_name
             << " at " << this << endl;
        delete m_ptr;
    }

    Auto_ptr3(const Auto_ptr3 &a)
    {
        m_ptr = new T(*a.m_ptr);
        m_name = a.m_name + "_copy"; // distinguish copies
        cout << "Copy constructor called for object: " << m_name
             << " at " << this << " (copied from " << &a << ")" << endl;
    }

    Auto_ptr3 &operator=(const Auto_ptr3 &a)
    {
        if (this == &a)
            return *this;
        delete m_ptr;
        m_ptr = new T(*a.m_ptr);
        m_name = a.m_name + "_assigned";
        cout << "Copy assignment called for object: " << m_name
             << " at " << this << " (assigned from " << &a << ")" << endl;
        return *this;
    }
};

class Resource
{
private:
public:
    Resource(){
        cout<<"Resource Constructor called"<<endl;
    }
    ~Resource(){
        cout<<"Resource Destructor called"<<endl;
    }
};

Auto_ptr3<Resource> generateResource(){
    Auto_ptr3<Resource> res{new Resource};
    return res;  
}

int main()
{
    Auto_ptr3<Resource> res(nullptr, "res");
    res = generateResource(); // res_assigned will show in log
    return 0;
}