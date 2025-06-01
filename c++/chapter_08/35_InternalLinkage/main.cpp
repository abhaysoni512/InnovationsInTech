
// main.cpp
extern void printFile1();
extern void printFile2();

int main()
{
    printFile1();
    printFile2();
    return 0;
}

/*
    In C++, the linkage of a variable determines its visibility across translation units (code files).
    A const variable has internal linkage by default, meaning that it is only visible within the
    translation unit where it is defined.

    This design is driven by two key considerations:

    Compile-time Constants: const variables can often be used in compile-time expressions.
    To achieve this, their value must be known at compile time, which requires the compiler to see the full definition
    (not just a declaration).
    Avoiding ODR Violations: If const variables had external linkage by default,
    including their definitions in multiple files would lead to One Definition Rule (ODR) violations,
    as multiple definitions of the same variable would exist.


    Here’s what happens:

    Each .cpp file includes the header file with const int myConst = 42;.
    Since myConst has internal linkage, each translation unit (file1.cpp and file2.cpp) gets its own unique copy of myConst.
    The program works without linker errors because there’s no conflict between the myConst variables in the two files.

    To make a const variable have external linkage:
        Use extern and define it in a single .cpp file.
        Use inline (from C++17) to safely include it in multiple files without ODR violations.

    */