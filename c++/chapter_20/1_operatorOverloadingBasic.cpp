#include <bits/stdc++.h>
using namespace std;
/*
    When evaluating an expression containing an operator, the compiler uses the following rules:

If all of the operands are fundamental data types, the compiler will call a built-in routine if one exists.
If one does not exist, the compiler will produce a compiler error.
If any of the operands are program-defined types (e.g. one of your classes, or an enum type), 
the compiler will use the function overload resolution algorithm (described in lesson 11.3 -- Function overload resolution and ambiguous matches)
to see if it can find an overloaded operator that is an unambiguous best match. This may involve implicitly converting one or more operands
to match the parameter types of an overloaded operator. It may also involve implicitly converting program-defined types into fundamental types
(via an overloaded typecast, which we’ll cover later in this chapter) so that it can match a built-in operator. 
If no match can be found (or an ambiguous match is found), the compiler will error.
*/

/*
    What are the limitations on operator overloading?
    1. First, almost any existing operator in C++ can be overloaded. The exceptions are: conditional (?:), sizeof, scope (::), member selector (.), pointer member selector (.*), typeid, and the casting operators.

    2. Second, you can only overload the operators that exist. You can not create new operators or rename existing operators. For example, you could not create an operator** to do exponents.

    3. Third, at least one of the operands in an overloaded operator must be a user-defined type. This means you could overload operator+(int, Mystring), but not operator+(int, double).
    An overloaded operator should operate on at least one program-defined type (either as a parameter of the function, or the implicit object).

    4. Fourth, it is not possible to change the number of operands an operator supports.

    5. Finally, all operators keep their default precedence and associativity (regardless of what they’re used for) and this can not be changed.
    Some new programmers attempt to overload the bitwise XOR operator (^) to do exponentiation. However,
     in C++, operator^ has a lower precedence level than the basic arithmetic operators, which causes expressions to evaluate incorrectly.
    In basic mathematics, exponentiation is resolved before basic arithmetic, so 4 + 3 ^ 2 resolves as 4 + (3 ^ 2) => 4 + 9 => 13.
    However, in C++, the arithmetic operators have higher precedence than operator^, so 4 + 3 ^ 2 resolves as (4 + 3) ^ 2 => 7 ^ 2 => 49.

    Note :
    Operators that do not modify their operands (e.g. arithmetic operators) should generally return results by value.
    Operators that modify their leftmost operand (e.g. pre-increment, any of the assignment operators) should generally return the leftmost operand by reference.

    there are three different ways to overload operators: the member function way, the friend function way, and the normal function way.
*/

// The following example shows how to overload operator plus (+) in order to add two “Cents” objects together:

class cents{
private:
        int m_cents{};
public:
        cents(int cents):m_cents(cents){}
        int getCents() const{
            return m_cents;
        }
        //ading two cents objects using friend method
        friend cents operator+(const cents &c1, const cents &c2);
        // Overloading operators for operands of different types
        friend cents operator+(const cents &c1,const int &i);
};
cents operator+(const cents &c1,const cents &c2) {
    return c1.m_cents + c2.m_cents;
}
cents operator+(const cents &c1, const int &i){
    return c1.m_cents + i;
}

int main()
{
    cents c1{10};
    cents c2{20};
    cout<< (c1+c2).getCents() << endl;
    cout << "Overloading operators for operands of different types\n" ;
    cout << (c1 + 10).getCents() << endl;
    return 0;
}