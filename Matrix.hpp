#ifndef MATRIX_H
#define MATRIX_H
#include "Vector.hpp"
class Matrix
{
private:
    double** a;
    unsigned int n;
    unsigned int r;
public:
    Matrix(unsigned int n_,unsigned int r_);
    ~Matrix();
    unsigned int getN() const;
    unsigned int getR() const;
    double getValue(unsigned int i, unsigned int j) const;
    void setValue(unsigned int i, unsigned int j, double value) const;
    Matrix operator* (const double c) const;
    Matrix operator+ (const Matrix& m) const;
    Matrix operator- (const Matrix& m) const;
    Matrix operator* (const Matrix& m);
    Vector operator* (const Vector& v);
    //Only for 3x3, and it's enough
    double det();
    Matrix operator=(const Matrix &m) const;
    Matrix transpose() const;
    //Only for 3x3 and 2x2, and it's enough
    Matrix inv();
    Matrix inv2();
    Vector diag();
};
Matrix operator* (double c, const Matrix& m);
//Only for 2x2
ostream& operator<<(ostream& os, const Matrix& m);
//Only for 2x2,it's enough
Matrix operator*(const Vector &v,const Matrix &m);
#endif
