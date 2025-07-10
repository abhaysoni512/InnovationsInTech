#ifndef POINT2D
#define POINT2D

#include <iostream>

class Point2D
{
private:
    int m_x{};
    int m_y{1};
public:
    Point2D(int x = 0, int y = 1):m_x(x),m_y{y}{}

    // An overloaded output operator
    friend std::ostream &operator<<(std::ostream &out, const Point2D &point)
    {
        out << '(' << point.m_x << ", " << point.m_y << ')';
        return out;
    }

    Point2D(const Point2D& point2d){
        m_x = point2d.m_x;
        m_y = point2d.m_y;
    }

    void setXY(int x,int y){
        m_x = x;
        m_y = y;
    }
};

#endif