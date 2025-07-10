#include <memory>
#include <iostream>
// C++14 comes with an additional function named std::make_unique(). This templated function constructs an object of the template type and initializes it with the arguments passed into the function.
/*
    ✅ 1. std::unique_ptr<T>
    It is a smart pointer introduced in C++11 that manages the lifetime of a dynamically allocated object.

    It ensures only one owner at a time.

    You manually use new to allocate memory:
        std::unique_ptr<int> ptr(new int(10));

    ✅ 2. std::make_unique<T> (C++14 and later)
    A helper function that creates a std::unique_ptr without requiring new.

    Safer and more readable:
    auto ptr = std::make_unique<int>(10);

*/
using namespace std;

class Fraction
{
private:
    int m_num{};
    int m_den{1};
public:
    Fraction(int numerator = 0, int denominator = 1) : m_num{numerator}, m_den{denominator}
    {
    }
    friend std::ostream& operator<< (std::ostream& out, const Fraction &f){
        out << f.m_num <<" / " << f.m_den <<endl;
        return out;
    }
};

class Resource{
public:
    Resource(){cout<<"Resource created\n";}
    ~Resource() { cout << "Resource destroyed\n"; }
};

std::unique_ptr<Resource> getResource()
{
    return std::make_unique<Resource>();
}
int main()
{
    // Create a single dynamically allocated Fraction with numerator 3 and denominator 5
    // We can also use automatic type deduction to good effect here
    auto f1 {std::make_unique<Fraction>(3,5)};
    std::cout << *f1 << '\n';
    // Create a dynamically allocated array of Fractions of length 4
    auto f2{std::make_unique<Fraction[]>(4)};
    std::cout << f2[0] << '\n';

    auto ptr = getResource();
    return 0;
}
