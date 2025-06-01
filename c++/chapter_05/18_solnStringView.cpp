#if 0
    std::string_view C++17

To address the issue with std::string being expensive to initialize (or copy),
C++17 introduced std::string_view (which lives in the <string_view> header). 
std::string_view provides read-only access to an existing string (a C-style string, a std::string, or another std::string_view) without making a copy. 
Read-only means that we can access and use the value being viewed, but we can not modify it.

#endif

#include <iostream>
#include <string_view>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   no copy is made here and hence it is more efficient.
//   note that name is still a string_view and not a string.
//   string_view is a view of string which does not own the memory. 
//   So it will not deallocate the memory when it goes out of scope.
//   it is good to use string_view when we are not going to modify the string.
//   if we want to modify the string, we have to convert it to string.
//   string_view is very useful when dealing with large strings or when we want to avoid unnecessary copying.
//   it is also useful when dealing with C-style strings.
//   string_view is a part of C++17.
//   if you are using C++11 or earlier, you can use std::basic_string::const_iterator and std::basic_string::const
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printString(std::string_view name){

    std::cout << name << std::endl;  
}

int main(){
    std::string_view name{"Abhay"}; //here no copy is made for name intilizer as name is just pointing to read only section of string "Abhay"
    printString(name);
    name = "Abhay Soni";
    return 0;
}