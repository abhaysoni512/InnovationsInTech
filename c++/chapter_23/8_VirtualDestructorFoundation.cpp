#include <bits/stdc++.h>
using namespace std;
class Base{
public:
    virtual ~Base(){
        cout<<" Base des callled\n";
    }
};
class Derived : public Base{
private:
    int *m_array{};
public:
    Derived(int length):
            m_array{new int[length]}
        {}

    ~Derived(){
        cout<<" derived class des callled\n";
        delete []m_array;
    }
};
int main(){
    Derived *derived{new Derived(5)};
    Base *base{derived};

    delete base;
    return 0;
}