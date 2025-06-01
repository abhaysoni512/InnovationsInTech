#include <iostream>

class Date
{
private:
    int m_year;

public:
    Date(int year) : m_year(year) {}

    int &getYear() { return m_year; } // Return a non-const reference
    const int getYear() const { return m_year; } // Return a const reference
    const int & getYearConst() const { return m_year; } // Return a const reference
    int  getYearConstCopy() const { return m_year; } // Return a copy

};

int main()
{
    Date d(2021);

    // Print the initial year
    std::cout << "Initial year: " << d.getYear() << "\n";

    // Obtain a non-const reference to m_year and modify it
    int &yearRef = d.getYear();
    yearRef = 2030; // This changes m_year inside d

    // Print the modified year
    std::cout << "Modified year: " << d.getYear() << "\n";

    return 0;
}
