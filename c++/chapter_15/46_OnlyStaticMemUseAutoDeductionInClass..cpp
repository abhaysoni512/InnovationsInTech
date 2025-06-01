#include <bits/stdc++.h>
using namespace std;
class something
{
    private:
        /*
        auto a{1}; // auto deduction for static member variable
        */
        auto constexpr static a{1}; // static member variable with auto deduction
        // Note: The static member variable 'a' is initialized with a constant expression, which allows it to be deduced as 'int'.
    // Note: The static member variable 'a' is defined as constexpr, which means it is a compile-time constant.
    // Note: The static member variable 'a' is defined as static, which means it is shared among all instances of the class.
    public:
        void display() const
        {
            cout << a << '\n';
        }
};

int main()
{
    something obj;
    obj.display(); // Output: 1
    // Note: The static member variable 'a' is deduced as 'int' because it is initialized with an integer literal.
    return 0;
}
    
