#include <iostream>
#include <string>

template <typename T>
T printString(T x)
{
    return x;
}

int main()
{
    std::string hello{"Hello, world!"};
    std::cout << printString(hello) << '\n';

    return 0;
}

/*
    When the compiler tries to resolve printString(hello) it won’t find a non-template function match for printString(std::string), but it will find our function template for printString(T),
     and determine that it can generate an printString(std::string) function from it.
    Thus, the compiler will generate and compile this.

        #include <iostream>
        #include <string>

        template <typename T>
        T printString(T x);

        template<>
        std::string printString<std::string>(std::string x)
        {
            return x;
        }

        int main()
        {
            std::string hello{ "Hello, world!" };
            std::cout << printString(hello) << '\n';

            return 0;
        }
*/