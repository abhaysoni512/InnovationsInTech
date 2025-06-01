1. Program Defined Data

    i.A program-defined type must have a name and a definition before it can be used
    
    ii.// This only defines what a Fraction type looks like, it doesn't create one
    struct Fraction
    {
        int numerator {};
        int denominator {};
    };

    // Now we can make use of our Fraction type
    int main()
    {
        Fraction f { 3, 4 }; // this actually instantiates a Fraction object named f

        return 0;
    }
    iii.Name your program-defined types starting with a capital letter and do not use a suffix.
    
    iv.Every code file that uses a program-defined type needs to see the full type definition before it is used. A forward declaration is not sufficient. This is required so that the compiler knows how much memory to allocate for objects of that type. A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then #included into each code file as needed.

    v. Type definitions are partially exempt from the one-definition rule (ODR) : using forward declarations in a similar manner doesn’t work for types, because the compiler typically needs to see the full definition to use a given type. We must be able to propagate the full type definition to each code file that needs it.

    Vi. User Defined vs Program Defined 

    The C++ language standard uses the term “user-defined type” in a non-conventional manner. In the language standard, a “user-defined type” is any class type or enumerated type that is defined by you, the standard library, or the implementation (e.g. types defined by the compiler to support language extensions). Perhaps counter-intuitively, this means std::string (a class type defined in the standard library) is considered to be a user-defined type!

    To provide additional differentiation, the C++20 language standard helpfully defines the term “program-defined type” to mean class types and enumerated types that are not defined as part of the standard library, implementation, or core language. In other words, “program-defined types” only include class types and enum types that are defined by us (or a third-party library).

2. Enumerations

    A. Unscoped enumerations

        // Define a new unscoped enumeration named Color
        enum Color
        {
            // Here are the enumerators
            // These symbolic constants define all the possible values this type can hold
            // Each enumerator is separated by a comma, not a semicolon
            red,
            green,
            blue, // trailing comma optional but recommended
        }; // the enum definition must end with a semicolon

        Inside a pair of curly braces, we define the enumerators for the Color type: red, green, and blue. These enumerators define the specific values that type Color is restricted to. Each enumerator must be separated by a comma (not a semicolon) -- a trailing comma after the last enumerator is optional but recommended for consistency.

        An enumeration or enumerated type is the program-defined type itself (e.g. Color).
        An enumerator is a specific named value belonging to the enumeration (e.g. red).

        Enumerators must be given names. Unfortunately, there is no common naming convention for enumerator names. Common choices include starting with lower case (e.g. red), starting with caps (Red), all caps (RED), all caps with a prefix (COLOR_RED), or prefixed with a “k” and intercapped (kColorRed).

        II. The scope of unscoped enumerations

        Unscoped enumerations are named such because they put their enumerator names into the same scope as the enumeration definition itself (as opposed to creating a new scope region like a namespace does).

        enum Color // this enum is defined in the global namespace
        {
            red, // so red is put into the global namespace
            green,
            blue,
        };

        int main()
        {
            Color apple { red }; // my apple is red

            return 0;
        }