/*
    Consider the expression std::cout << point. If the operator is <<, what are the operands? 
    The left operand is the std::cout object, and the right operand is your Point class object. 
    std::cout is actually an object of type std::ostream.
*/

#include <iostream>
using namespace std;
class Point{
private:
    int m_x{};
    int m_y{};
    int m_z{};
public:
    Point(int x, int y, int z) : m_x(x),m_y{y},m_z{z}{}
    friend std::ostream &operator<<(std::ostream &out, const Point &point);
};                                  //cout
std::ostream& operator<<(std::ostream &out, const Point &point) {
    out << "x: "<< point.m_x <<" y:"<<point.m_y<<" z:"<<point.m_z<<endl;
    return out;
}

int main()
{
    Point p1{11,22,33};
    std::cout<<"Coordinates of p1 : "<<p1 << endl;
    return 0;
}