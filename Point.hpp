#ifndef POINT_H
#define POINT_H
class Point
{
private:
    double x,y;
public:
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;
    double Distance(Point& a);
    bool operator<(const Point& p);
    Point operator=(const Point &p);
};
#endif
