
/*
    Captures are treated as const by default
    When a lambda is called, operator() is invoked. By default, this operator() treats captures as const, meaning the lambda is not allowed to modify those captures.
    In the following example, we capture the variable ammo and try to decrement it.
*/
#include <iostream>

int main()
{
    int ammo{ 10 };

    // Define a lambda and store it in a variable called "shoot".
    auto shoot{
        [&ammo]() mutable    //Use mutable keyword to solve this
        {
            // Illegal, ammo cannot be modified.
            // Error : error: cannot assign to a variable captured by copy in a non-mutable lambda
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
        }};

    // Call the lambda
    shoot();
    shoot();
    std::cout << ammo << " shot(s) left\n";
    /*
        While this now compiles, there’s still a logic error. What happened? When the lambda was called, the lambda captured a copy of ammo.
        When the lambda decremented ammo from 10 to 9 to 8, it decremented its own copy, not the original ammo value in main().
        Because captured variables are members of the lambda object, their values are persisted across multiple calls to the lambda!
        To Solve Capture variable by refernces to modify actual variable
    */
    return 0;
}
    