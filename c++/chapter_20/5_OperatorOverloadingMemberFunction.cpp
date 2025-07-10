/*
    Overloading operators using a member function is very similar to overloading operators using a friend function. 
    When overloading an operator using a member function:

        The overloaded operator must be added as a member function of the left operand.
        The left operand becomes the implicit *this object
        All other operands become function parameters.
*/

#include <iostream>
using namespace std;
class Cents{
private:
    int m_cents{};
public:
    Cents(int cents) : m_cents(cents){}
    Cents operator+(int cents) const;
    int getCents() const{
        return m_cents;
    }
};
Cents Cents::operator+(int cents) const{    //make sure to use scope resoultion operator
    return m_cents + cents;
}

int main()
{
    Cents c1{10};
    Cents c2{c1+20};
    cout<<c2.getCents()<<endl;
}