#include <iostream>

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        std::cout << "Default constructor called\n";
    }
    // Copy constructor
    Fraction(const Fraction &other) // Copy constructor parameter must be a reference
        : m_numerator{other.m_numerator}, m_denominator{other.m_denominator}
    {
        std::cout << "Copy constructor called\n";
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f{5, 3}; // Calls Fraction(int, int) constructor
    f.print();

    Fraction fCopy{f};
    fCopy.print();

    return 0;
}