#include <bits/stdc++.h>
using namespace std;

class cents
{
private:
    int m_cents{};

public:
    cents(int cents) : m_cents(cents) {}
    int getCents() const
    {
        return m_cents;
    }
};

cents operator+(const cents &c1, const int &i)
{
    return cents{c1.getCents()+i};
}

int main()
{
    cents c1{10};
    cout << "Overloading operators for operands of different types\n";
    cout << (c1 + 10).getCents() << endl;
    return 0;
}