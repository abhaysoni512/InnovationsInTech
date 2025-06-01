#if 0
    C++17 introduces the constexpr if statement, which requires the conditional to be a constant expression. 
    The conditional of a constexpr-if-statement will be evaluated at compile-time.

    If the constexpr conditional evaluates to true, the entire if-else will be replaced by the true-statement.
    If the constexpr conditional evaluates to false, the entire if-else will be replaced by the false-statement
    (if it exists) or nothing (if there is no else).

    Step-by-Step Explanation
    constexpr Variable:


    constexpr double gravity{ 9.8 };
    The variable gravity is declared as constexpr, so its value is known at compile time.
    gravity has a value of 9.8.
    if constexpr Condition:

    if constexpr (gravity == 9.8)
    The condition gravity == 9.8 is evaluated at compile time because it is inside an if constexpr.
    Since gravity is 9.8, the condition evaluates to true.
    Branching at Compile Time:

    Because the condition is true, the true branch:
    std::cout << "Gravity is normal.\n";
    will be compiled into the final binary.

    The false branch:
    std::cout << "We are not on Earth.\n";
    will be completely discarded by the compiler.
    Resulting Code: After compilation, the resulting binary contains only:

    std::cout << "Gravity is normal.\n";
    The else branch does not exist in the compiled code, making it more efficient.
    
#endif

#include <iostream>

int main()
{
    constexpr int x = 5;  //req1 : x should be a constant expression
    if constexpr (x == 5)
    {
        std::cout << "this will be executed\n";
    }
    else
    {
        std::cout << "this will be discard on final executable binary\n";
    }


    return 0;
}