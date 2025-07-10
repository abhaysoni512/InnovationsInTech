/*
    Copy assignment vs Copy constructor

    The purpose of the copy constructor and the copy assignment operator are almost equivalent -- both copy one object to another.
     However, the copy constructor initializes new objects, whereas the assignment operator replaces the contents of existing objects.

    The difference between the copy constructor and the copy assignment operator causes a lot of confusion for new programmers,
     but it’s really not all that difficult. Summarizing:

    If a new object has to be created before the copying can occur, the copy constructor is used 
    (note: this includes passing or returning objects by value).

    If a new object does not have to be created before the copying can occur, the assignment operator is used.
*/

/*
    Overloading the copy assignment operator (operator=) is fairly straightforward, with one specific caveat that we’ll get to.
    The copy assignment operator must be overloaded as a member function.
*/

#include <iostream>
#include <cassert>

class Fraction{
private:
    int m_num;
    int m_deno;
public :
    Fraction(int num = 0, int deno = 1) : m_num(num), m_deno(deno){
        assert (deno !=0);
    }
    Fraction &operator=(const Fraction &f1);
     
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
};
std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    return out << f1.m_num << " / " << f1.m_deno << "\n";
}

Fraction & Fraction::operator=(const Fraction &f1) //scope resolution is must
{
    // self-assignment guard
    if (this == &f1)
        return *this;
    m_num = f1.m_num;
    m_deno = f1.m_deno;
    return *this;

}

int main()
{
    Fraction f1 {1,3};
    Fraction f2;
    f2 = f1;
    std::cout<<f2;
}