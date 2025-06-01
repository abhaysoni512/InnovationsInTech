#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

int main()
{
    Pair<int> p1{5, 6}; // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2{1.2, 3.4}; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3{7.8, 9.0}; // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';

    Pair p4{1, 2}; // instantiates Pair<int> and creates object p4
    std::cout << p4.first << ' ' << p4.second << '\n';

    // Pair p5{1, 2.3};              // instantiates Pair<double> and creates object p5
    // std::cout << p5.first << ' ' << p5.second << '\n';  //here we encounter problem as on case of p5
    //  we are not specifying the type of Pair so it will take the first type as int and second as double

    return 0;
}