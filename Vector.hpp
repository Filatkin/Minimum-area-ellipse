#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
class Vector
{
private:
    double* a;
    unsigned int n;
public:
    Vector(unsigned int n_);
    ~Vector();
    double getValue(unsigned int i) const;
    unsigned int getN() const;
    void setValue(unsigned int i,double value);
    Vector operator* (const double c) const;
    Vector operator+ (const Vector& v);
    Vector operator- (const Vector& v);
    Vector operator= (const Vector& v);
};
Vector operator* (double c, const Vector& v);
//Only for 2 coordinates
ostream& operator<<(ostream& os, const Vector& v);
#endif
