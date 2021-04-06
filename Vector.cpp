#include <iostream>
#include "Vector.hpp"
using namespace std;
    Vector::Vector(unsigned int n_)
    {
        n=n_;
        a=new double [n];
    }
    Vector::~Vector()
    {
        delete [] a;
    }
    double Vector::getValue(unsigned int i) const
    {
        return a[i];
    }
    unsigned int Vector::getN() const
    {
        return n;
    }
    void Vector::setValue(unsigned int i,double value)
    {
        a[i]=value;
    }
    Vector Vector::operator* (const double c) const
    {
        Vector v=Vector(n);
        for(unsigned int i=0;i<n;i++)
        {
            v.setValue(i,a[i]*c);
        }
        return v;
    }
    Vector Vector::operator+ (const Vector& v)
    {
        Vector V=Vector(n);
        for(unsigned int i=0;i<n;i++)
        {
            V.setValue(i,a[i]+v.getValue(i));
        }
        return V;
    }
    Vector Vector::operator- (const Vector& v)
    {
        Vector V=Vector(n);
        for(unsigned int i=0;i<n;i++)
        {
            V.setValue(i,a[i]-v.getValue(i));
        }
        return V;
    }
    Vector Vector::operator= (const Vector& v)
    {
        Vector V=Vector(v.getN());
        for(unsigned int i=0;i<v.getN();i++)
        {
            V.setValue(i,v.getValue(i));
        }
        return V;
    }
Vector operator* (double c, const Vector& v)
{
    Vector V=Vector(v.getN());
        for(unsigned int i=0;i<v.getN();i++)
        {
            V.setValue(i,v.getValue(i)*c);
        }
    return V;
}
//Only for 2 coordinates
ostream& operator<<(ostream& os, const Vector& v)
{
    os << "(" << v.getValue(0) << "; " << v.getValue(1)<<")";
    return os;
}
