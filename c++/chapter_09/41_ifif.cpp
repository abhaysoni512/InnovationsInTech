#if 0
If-else vs if-if

New programmers sometimes wonder when they should use if-else (if followed by one or more else-statements) or if-if (if followed by one or more additional if-statements).

Use if-else when you only want to execute the code after the first true condition.
Use if-if when you want to execute the code after all true conditions.

#endif

#include <iostream>

void ifelse(bool a, bool b, bool c)
{
    if (a) // always evaluates
        std::cout << "a";
    else if (b) // only evaluates when prior if-statement condition is false
        std::cout << "b";
    else if (c) // only evaluates when prior if-statement condition is false
        std::cout << "c";
    std::cout << '\n';
}

void ifif(bool a, bool b, bool c)
{
    if (a) // always evaluates
        std::cout << "a";
    if (b) // always evaluates
        std::cout << "b";
    if (c) // always evaluates
        std::cout << "c";
    std::cout << '\n';
}

int main()
{
    ifelse(false, true, true);
    ifif(false, true, true);

    return 0;
}