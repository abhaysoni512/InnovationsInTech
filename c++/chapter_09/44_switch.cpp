#if 0
    #include <iostream>

    void printDigitName(int x)
    {
        if (x == 1)
            std::cout << "One";
        else if (x == 2)
            std::cout << "Two";
        else if (x == 3)
            std::cout << "Three";
        else
            std::cout << "Unknown";
    }

    int main()
    {
        printDigitName(2);
        std::cout << '\n';

        return 0;
    }
    Variable x in printDigitName() will be evaluated up to three times depending on the value passed in (which is inefficient),
    and the reader has to be sure that it is x being evaluated each time (not some other variable).

    Because testing a variable or expression for equality against a set of different values is common, 
    C++ provides an alternative conditional statement called a switch-statement that is specialized for this purpose.

#endif

#include <iostream>

void printDigitName(int x)
{
    switch (x)
    {
    case 1:
        std::cout << "One";
        return;
    case 2:
        std::cout << "Two";
        return;
    case 3:
        std::cout << "Three";
        return;
    default:
        std::cout << "Unknown";
        return;
    }
}

int main()
{
    printDigitName(1);
    std::cout << '\n';

    return 0;
}