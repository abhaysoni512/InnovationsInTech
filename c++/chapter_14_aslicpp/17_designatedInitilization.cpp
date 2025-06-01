// When initializing a struct from a list of values, 
//the initializers are applied to the members in order of declaration.

#if 0

struct Foo
{
    int a{};
    int c{};
};

int main()
{
    Foo f{1, 3}; // f.a = 1, f.c = 3

    return 0;
}

#endif

// Now consider what would happen if you were to update this struct definition
// to add a new member that is not the last member:

#if 0

struct Foo
{
    int a {};
    int b {}; // just added
    int c {};
};

int main()
{
    Foo f { 1, 3 }; // now, f.a = 1, f.b = 3, f.c = 0

    return 0;
}

#endif

/*
Now all your initialization values have shifted, and worse, 
the compiler may not detect this as an error (after all, the syntax is still valid).

To help avoid this, C++20 adds a new way to initialize struct members called designated initializers. 
Designated initializers allow you to explicitly define which initialization values map to which members. 
The members can be initialized using list or copy initialization, and must be initialized in the
same order in which they are declared in the struct, 
otherwise a warning or error will result.
Members not designated an initializer will be value initialized.

*/

struct Foo
{
    int a{};
    int b{};
    int c{};
};

int main()
{
    Foo f1{.a{1}, .c{3}};   // ok: f1.a = 1, f1.b = 0 (value initialized), f1.c = 3
    Foo f2{.a = 1, .c = 3}; // ok: f2.a = 1, f2.b = 0 (value initialized), f2.c = 3
    Foo f3{.b{2}, .a{1}};   // error: initialization order does not match order of declaration in struct

    return 0;
}