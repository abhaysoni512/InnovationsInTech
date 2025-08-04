#include <iostream>

class Base
{
public:
    void print(int) { std::cout << "Base::print(int)\n"; }
    void print(double) { std::cout << "Base::print(double)\n"; }
};

class Derived : public Base
{
public:
    void print(double) { std::cout << "Derived::print(double)"; } // this function added
};

int main()
{
    Derived d{};
    d.print(5); // calls Derived::print(double), not Base::print(int)

    return 0;
}

/*
For the call d.print(5), the compiler finds one function named print() in Derived, therefore it will only consider functions in Derived when trying to determine what function to resolve to. This function is also the best matching function in Derived for this function call. Therefore, this calls Derived::print(double).

Since Base::print(int) has a parameter that is a better match for int argument 5 than Derived::print(double), you may have been expecting this function call to resolve to Base::print(int). But because d is a Derived, there is at least one print() function in Derived, and Derived is more derived than Base, the functions in Base are not even considered.
*/