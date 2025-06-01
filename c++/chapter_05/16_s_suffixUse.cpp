#include <iostream>
#include <string>

int main()
{
    using namespace std::string_literals;
    //The “s” suffix lives in the namespace std::literals::string_literals

        // C-style string literal
        const char *cStr = "foo";

    // std::string created using the s suffix // here cppStr will be object
    std::string cppStr = "goo"s;

    // std::string operations
    cppStr += " bar"; // Concatenation

    std::cout << cStr << '\n';   // Outputs: foo
    std::cout << cppStr << '\n'; // Outputs: goo bar

    return 0;
}
