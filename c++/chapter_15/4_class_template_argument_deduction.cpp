// CTAD (Class Template Argument Deduction)
// C++17 introduced Class Template Argument Deduction (CTAD) which allows the deduction of template arguments 
// from the initializer list.
// CTAD is used to deduce the template arguments of a class template from the initializer list.
// CTAD is used when the template arguments are not explicitly specified.
#include <utility> // for std::pair

int main()
{
    std::pair<int, int> p1{1, 2}; // explicitly specify class template std::pair<int, int> (C++11 onward)
    std::pair p2{1, 2};           // CTAD used to deduce std::pair<int, int> from the initializers (C++17)
    std::pair p3{1u, 2u};         // CTAD used to deduce std::pair<unsigned int, unsigned int> from the initializers (C++17)
    /*
    std::pair<> p1{1, 2};         // error: too few template arguments, both arguments not deduced
    std::pair<int> p2{3, 4};      // error: too few template arguments, second argument not deduced
    */
    return 0;
}