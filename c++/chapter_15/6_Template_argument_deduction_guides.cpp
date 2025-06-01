// Template argument deduction guides
// C++17 introduced template argument deduction guides (TADG) which allow the deduction of template arguments from the initializer list.
// TADG is used to deduce the template arguments of a class template from the initializer list.
// TADG is used when the template arguments are not explicitly specified.
// TADG is used to provide hints to the compiler on how to deduce the template arguments.
#if 0
// define our own Pair type
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

int main()
{
    Pair<int, int> p1{1, 2}; // ok: we're explicitly specifying the template arguments
    Pair p2{1, 2};           // compile error in C++17 (okay in C++20)

    return 0;
}
#endif
// error : // error: no viable constructor or deduction guide for deduction of template arguments of 'Pair'
//to solve it : we need to provide the deduction guide for the compiler
// define our own Pair type
template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

// provide a deduction guide for Pair
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main(){
    Pair<int, int> p1{1, 2}; // ok: we're explicitly specifying the template arguments
    Pair p2{1, 2};           // ok: TADG used to deduce Pair<int, int> from the initializers

    return 0;
}