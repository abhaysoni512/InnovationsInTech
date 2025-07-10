// let's cover shallow copy and it's problem

#include <bits/stdc++.h>
using namespace std;
class Mystring
{
private:
    char *m_data{};
    int m_length{};

public:
    Mystring(const char *str = "")
    {
        m_length = strlen(str) + 1;
        m_data = new char[m_length];
        for (int i{0}; i < m_length; i++)
        {
            m_data[i] = str[i];
        }
    }
    ~Mystring()
    {
        delete[] m_data;
        m_data = nullptr; // Avoid dangling pointer
    }
    Mystring(const Mystring &source);
    void deepcopy(const Mystring &source) ;
    int *getAddress()
    {
        return reinterpret_cast<int *>(m_data);
    }
    Mystring& operator=(const Mystring& source){
        // S1. Check weather we are using self copying
        if(this != &source){
            // now do the deep copy
            deepcopy(source);
        }
        return *this;

    }
};
void Mystring::deepcopy(const Mystring &source){
    // first we need to deallocate any value that this string is holding!
    delete[] m_data;

    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;

    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source.m_data)
    {
        // allocate memory for our copy
        m_data = new char[m_length];

        // do the copy
        for (int i{0}; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = nullptr;
}
// copy constructor
Mystring::Mystring(const Mystring &source)
{
    deepcopy(source);
}

int main()
{

    Mystring s1{"Abhay"};
    Mystring s2{s1};
    Mystring s3 = s1;
    cout << "s1 address: " << s1.getAddress() << endl;
    cout << "s2 address: " << s2.getAddress() << endl;
    cout << "s3 address: " << s3.getAddress() << endl;

    return 0;
}


// Note:
/*
            1. this
        this is of type Mystring* (a pointer to the current object).

        You use this when you want to access members like this->m_data.

        2. *this
        *this is of type Mystring& (a reference to the current object).

        This is what you return in operator=:

        Mystring& operator=(const Mystring& source) {
            if (this != &source) {
                deepcopy(source);
            }
            return *this; // return the current object by reference
        }
*/