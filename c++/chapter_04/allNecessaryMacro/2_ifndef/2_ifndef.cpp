#if 0
   Purpose: Checks if a macro (identifier) is not defined. 
   If the macro is not defined, the following code is included.
Common Use: Often used in header guards to prevent multiple inclusions of the same header file.
#endif
#include "2_ifndef.h"

std::string myFunction()
{
    return "My function is called";
}
int main()
{
    std::cout << "My name is: " << myFunction() << '\n';
    return 0;
}