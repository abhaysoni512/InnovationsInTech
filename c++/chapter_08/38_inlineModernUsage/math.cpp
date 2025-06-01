#include <iostream>
inline double pi() {
    std::cout << "pi() called\n";
    return 3.14;
    }

double circumference(double radius){
    return pi() *2 * radius;
}
