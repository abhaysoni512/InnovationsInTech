#include <iostream>

class Date
{
private:
    int m_year;

public:
    Date(int year) : m_year(year) {}

    int getYear() { return m_year; }
};

int main()
{
    Date d(2021);

    // Print the initial year
    std::cout << "Initial year: " << d.getYear() << "\n";

    int yearRef = d.getYear();
    yearRef = 2030; // This changes m_year inside d

    // Print the modified year but it won't change the original m_year
    // because yearRef is a copy of the value, not a reference
    // If you want to modify the original m_year, you need to return a reference
    // to m_year instead of a copy.
    // To modify the original m_year, you can use a non-const reference
    // in the getter function.
    // Uncomment the following line to see the effect of modifying the reference
    // d.getYear() = 2030; // This will not work as getYear() returns a copy
    
    // Print the modified year
    std::cout << "Modified year: " << d.getYear() << "\n";

    return 0;
}
