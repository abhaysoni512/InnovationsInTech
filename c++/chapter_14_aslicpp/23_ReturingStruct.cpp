#include <iostream>

struct Point3d
{
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

Point3d getZeroPoint()
{
    // 1ST WAY
    /*
    // We can create a variable and return the variable (we'll improve this below)
    Point3d temp{0.0, 0.0, 0.0};
    return temp;
    */
    // 2ND WAY
    //  We can return a temporary object
    return Point3d{0.0, 0.0, 0.0}; // also Point3d{}; will work
}

int main()
{
    Point3d zero{getZeroPoint()};

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}