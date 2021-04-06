#include <iostream>
#include "Point.hpp"
    Point::Point(double x, double y): x(x), y(y){}
    void Point::setX(double x)
    {
        this->x=x;
    }
    void Point::setY(double y)
    {
        this->y=y;
    }
    double Point::getX() const
    {
        return x;
    }
    double Point::getY() const
    {
        return y;
    }
    double Point::Distance(Point& a)
    {
        return (x-a.getX())*(x-a.getX())+(y-a.getY())*(y-a.getY());
    }
    bool Point::operator<(const Point& p)
    {
        return this->x<p.getX();
    }
    Point Point::operator=(const Point &p)
    {
        return Point(p.getX(),p.getY());
    }
