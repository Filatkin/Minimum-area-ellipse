#include <iostream>
#include "Matrix.hpp"
using namespace std;
    Matrix::Matrix(unsigned int n_,unsigned int r_)
    {
        n=n_;
        r=r_;
        a=new double* [n];
        for(unsigned int i=0;i<n;i++)
            a[i]=new double [r];
    }
    Matrix::~Matrix()
    {
        for(unsigned int i=0;i<n;i++)
            delete [] a[i];
        delete [] a;
    }
    unsigned int Matrix::getN() const
    {
        return n;
    }
    unsigned int Matrix::getR() const
    {
        return r;
    }
    double Matrix::getValue(unsigned int i, unsigned int j) const
    {
        return a[i][j];
    }
    void Matrix::setValue(unsigned int i, unsigned int j, double value) const
    {
        a[i][j]=value;
    }
    Matrix Matrix::operator* (const double c) const
    {
        Matrix M=Matrix(n,r);
        for(unsigned int i=0;i<n;i++)
            for(unsigned int j=0;j<r;j++)
                M.setValue(i,j,a[i][j]*c);
        return M;
    }
    Matrix Matrix::operator+ (const Matrix& m) const
    {
        Matrix M=Matrix(n,r);
        for(unsigned int i=0;i<n;i++)
            for(unsigned int j=0;j<r;j++)
                M.setValue(i,j,a[i][j]+m.getValue(i,j));
        return M;
    }
    Matrix Matrix::operator- (const Matrix& m) const
    {
        Matrix M=Matrix(n,r);
        for(unsigned int i=0;i<n;i++)
            for(unsigned int j=0;j<r;j++)
            M.setValue(i,j,a[i][j]-m.getValue(i,j));
        return M;
    }
    Matrix Matrix::operator* (const Matrix& m)
    {
        Matrix M=Matrix(n,m.getR());
        for(unsigned int i=0;i<n;i++)
        {
            for(unsigned int j=0;j<m.getR();j++)
            {
                double c;
                c=0;
                for(unsigned int k=0;k<r;k++)
                {
                    c+=a[i][k]*m.getValue(k,j);
                }
                M.setValue(i,j,c);
            }
        }
        return M;
    }
    Vector Matrix::operator* (const Vector& v)
    {
        Vector V=Vector(v.getN());
        for(unsigned int i=0;i<n;i++)
        {
            double c;
            c=0;
            for(unsigned int k=0;k<v.getN();k++)
            {
                c+=a[i][k]*v.getValue(k);
            }
            V.setValue(i,c);
        }
        return V;
    }
    //Only for 3x3, and it's enough
    double Matrix::det()
    {
        return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    }
    Matrix Matrix::operator=(const Matrix &m) const
    {
        Matrix M=Matrix(m.getN(),m.getR());
        for(unsigned int i=0;i<m.getN();i++)
            for(unsigned int j=0;j<m.getR();j++)
        {
            M.setValue(i,j,a[i][j]);
        }
        return M;
    }
    Matrix Matrix::transpose() const
    {
        Matrix M=Matrix(r,n);
        for(unsigned int i=0;i<r;i++)
            for(unsigned int j=0;j<n;j++)
        {
            M.setValue(i,j,a[j][i]);
        }
        return M;
    }
    //Only for 3x3 and 2x2, and it's enough
    Matrix Matrix::inv()
    {
        double d=this->det();
        Matrix m=Matrix(3,3);
        m.setValue(0,0,(a[1][1]*a[2][2]-a[1][2]*a[2][1])/d);
        m.setValue(0,1,-(a[1][0]*a[2][2]-a[1][2]*a[2][0])/d);
        m.setValue(0,2,(a[1][0]*a[2][1]-a[2][0]*a[1][1])/d);
        m.setValue(1,0,-(a[0][1]*a[2][2]-a[0][2]*a[2][1])/d);
        m.setValue(1,1,(a[0][0]*a[2][2]-a[0][2]*a[2][0])/d);
        m.setValue(1,2,-(a[0][0]*a[2][1]-a[0][1]*a[2][0])/d);
        m.setValue(2,0,(a[0][1]*a[1][2]-a[1][1]*a[0][2])/d);
        m.setValue(2,1,-(a[0][0]*a[1][2]-a[1][0]*a[0][2])/d);
        m.setValue(2,2,(a[0][0]*a[1][1]-a[0][1]*a[1][0])/d);
        return m.transpose();
    }
    Matrix Matrix::inv2()
    {
        double d=a[0][0]*a[1][1]-a[0][1]*a[1][0];
        Matrix m=Matrix(2,2);
        m.setValue(0,0,a[1][1]/d);
        m.setValue(0,1,(-a[0][1])/d);
        m.setValue(1,0,(-a[1][0])/d);
        m.setValue(1,1,a[0][0]/d);
        return m;
    }
    Vector Matrix::diag()
    {
        Vector v=Vector(n);
        for(unsigned int i=0;i<n;i++)
        {
            v.setValue(i,a[i][i]);
        }
        return v;
    }
Matrix operator* (double c, const Matrix& m)
    {
        Matrix M(m.getN(),m.getR());
        for(unsigned int i=0;i<m.getN();i++)
            for(unsigned int j=0;j<m.getR();j++)
                M.setValue(i,j,c*m.getValue(i,j));
        return M;
    }
//Only for 2x2
ostream& operator<<(ostream& os, const Matrix& m)
{
    os <<endl<< m.getValue(0,0) << " " << m.getValue(0,1) <<endl;
    os << m.getValue(1,0) << " " << m.getValue(1,1) <<endl;
    return os;
}
//Only for 2x2,it's enough
Matrix operator*(const Vector &v,const Matrix &m)
{
    Matrix M=Matrix(2,2);
    M.setValue(0,0,v.getValue(0)*m.getValue(0,0));
    M.setValue(0,1,v.getValue(0)*m.getValue(0,1));
    M.setValue(1,0,v.getValue(1)*m.getValue(0,0));
    M.setValue(1,1,v.getValue(1)*m.getValue(0,1));
    return M;
}
