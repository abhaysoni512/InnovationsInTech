#ifndef CENT_H
#define CENT_H


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

cents operator+(const cents &c1, const int &i); //prototypedeclaration

#endif