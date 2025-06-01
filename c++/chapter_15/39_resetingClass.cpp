#include <iostream>

class Class
{
    int a;
    double b;
    std::string c;

public:
    // Constructor to initialize members
    Class(int a_, double b_, std::string c_) : a(a_), b(b_), c(c_) {}

    // Function to display current state
    void display() const
    {
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    }

    // Reset function to restore default values
    void reset()
    {
        a = 0;
        b = 0.0;
        c = "";
    }
};

int main()
{
    Class obj(10, 3.14, "Hello");
    std::cout << "Before reset: ";
    obj.display();

    obj.reset();
    std::cout << "After reset: ";
    obj.display();

    return 0;
}