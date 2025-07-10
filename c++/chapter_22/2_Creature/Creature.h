#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include "2dpoint.h"

class Creature
{
private:
    std::string m_name{};
    Point2D m_location;
public:
    Creature(std::string_view name, const Point2D& location):m_name(name),m_location(location){
        
    }
    ~Creature() = default;

    friend std::ostream &operator<<(std::ostream &out, const Creature&c){
        out<<c.m_name<<" is at "<<c.m_location<<" ....\n";
        return out;
    }
    void moveTo(int x, int y)
    {
        m_location.setXY(x,y);
    }
};

#endif