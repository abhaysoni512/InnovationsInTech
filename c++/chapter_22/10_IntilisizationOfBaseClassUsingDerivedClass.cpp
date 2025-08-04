#include <iostream>
using namespace std;
class Base
{
private:
    int m_id{};
public:
    Base(int id = 0)
        : m_id{id}
    {
        std::cout << "Base m_id : " << m_id << endl;
    }
    int getId() const { return m_id; }
};

class Derived : public Base
{
private:
    double m_cost{};
public:
    Derived(double cost = 0.0,int id = 0)
        : m_cost{cost}, Base(id)
    {
        std::cout << "Derived m_cost :"<<m_cost<<endl;

    }
    double getCost() const { return m_cost; }
};

int main()
{
    Derived d(11,4);
    d.getCost();
    d.getId();
    return 0;
}
/*
Order of execution:
    1. Memory for derived is allocated.
    2. The Derived(double, int) constructor is called, where cost = 1.3, and id = 5.
    3. The compiler looks to see if we’ve asked for a particular Base class constructor. We have! So it calls Base(int) with id = 5.
    4. The base class constructor member initializer list sets m_id to 5.
    5. The base class constructor body executes, which does nothing.
    6. The base class constructor returns.
    7. The derived class constructor member initializer list sets m_cost to 1.3.
    8. The derived class constructor body executes, which does nothing.
    9. The derived class constructor returns.
*/