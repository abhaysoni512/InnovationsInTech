
#include <iostream>

int main()
{
    const char name[]{"Alex"};         // case 1: const C-style string initialized with C-style string literal
    const char *const color{"Orange"}; // case 2: const pointer to C-style string literal

    std::cout << name << ' ' << color << '\n';

    return 0;
}

/*
    In case 1, “Alex” is put into (probably read-only) memory somewhere.
    Then the program allocates memory for a C-style array of length 5 (four explicit characters plus the null terminator),
     and initializes that memory with the string “Alex”. So we end up with 2 copies of “Alex” -- one in global memory somewhere,
     and the other owned by name.
     Since name is const (and will never be modified), making a copy is inefficient.

    In case 2, how the compiler handles this is implementation defined.
    What usually happens is that the compiler places the string “Orange” into read-only memory somewhere,
     and then initializes the pointer with the address of the string.

    auto s1{ "Alex" };  // type deduced as const char*
    auto* s2{ "Alex" }; // type deduced as const char*
    auto& s3{ "Alex" }; // type deduced as const char(&)[5]


*/