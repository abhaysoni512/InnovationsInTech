#if 0
    //#ifdef(If Defined)
    Purpose : Checks if a macro(identifier)
    is defined.If the macro is defined, the following code is included.Common Use :
    Used to include code conditionally based on preprocessor macros.

#endif

#include <iostream>
#define MY_NAME "Macro_Abhay"  //this macro is defined

int main()
{
#ifdef MY_NAME    //this secotion will be included if MY_NAME is defined
    std::cout << "My name is: " << MY_NAME << '\n';
#endif
    return 0;
}