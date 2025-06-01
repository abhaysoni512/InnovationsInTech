#include <iostream>

class Something
{   private:
        static inline int s_value {10}; // declare s_value as static (initializer moved below)
    public:
        static void setValue(int value) // static member function to set the value of s_value
        {
            s_value = value; // modify the static member variable
        }

        static int getValue() // static member function to get the value of s_value
        {
            return s_value; // return the static member variable
        }

};

int main()
{
    std::cout << "Initial value: " << Something::getValue() << '\n'; // Accessing static member function before any object is created

    Something::setValue(20); // Modify the static member variable using the static member function

    std::cout << "Modified value: " << Something::getValue() << '\n'; // Accessing static member function after modification

    return 0;
}
