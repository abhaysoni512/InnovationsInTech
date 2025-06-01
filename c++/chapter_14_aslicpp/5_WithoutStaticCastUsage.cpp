/*
    Second, as of C++17, if an unscoped enumeration has an explicitly specified base, 
    then the compiler will allow you to list initialize an unscoped enumeration using an integral value:
*/

#include <iostream>
enum class Pet : unsigned int
{
    cat,   // assigned 0
    dog,   // assigned 1
    pig,   // assigned 2
    whale, // assigned 3
};

int main()
{
    Pet pet{2}; // okay: convert integer 2 to a Pet
    /*
    Pet pet2(2);  // compile error: cannot direct initialize with integer
    Pet pet3 = 3; // compile error : cannot copy initialize with integer
    */

    return 0;
}