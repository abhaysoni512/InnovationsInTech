#include <iostream>

struct coordinates
{
    double x{};
    double y{};
};

struct Triangle
{
    coordinates *a{};
    coordinates *b{};
    coordinates *c{};
};

int main()
{
    coordinates p{1, 2};
    coordinates q{3, 7};
    coordinates r{10, 2};

    Triangle tr{&p, &q, &r};
    Triangle *ptr{&tr};

    // ptr is a coordinateser to a Triangle, which contains members that are coordinatesers to a coordinates
    // To access member y of coordinates c of the Triangle coordinatesed to by ptr, the following are equivalent:

    std::cout << ptr->b->x << " , " << ptr->b->y << '\n'; // much nicer
}