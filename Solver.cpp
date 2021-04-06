#include <iostream>
#include <vector>
#include <cmath>
#include "Point.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
double* solver(unsigned int n, double* x, double* y, double error, double accuracy)
{
    vector<Point> P;
    for(unsigned int i=0;i<n;i++)
    {
        cout<<"("<<x[i]<<","<<y[i]<<")"<<endl;
        P.push_back(Point(x[i],y[i]));
    }
    Matrix q=Matrix(3,n);
    Matrix B=Matrix(2,n);
    unsigned int j=0;
    double k=0;
    for(auto it=P.begin();it!=P.end();++it)
    {
        Point p=(*it);
        double x1=p.getX(),y1=p.getY();
        q.setValue(0,j,x1);
        q.setValue(1,j,y1);
        B.setValue(0,j,x1);
        B.setValue(1,j,y1);
        q.setValue(2,j,1);
        j++;
        k++;
    }
    Matrix u=Matrix(n,n);
    for(unsigned int i=0;i<n;i++)
        for(unsigned int l=0;l<n;l++)
        {
            if(i==l)
                u.setValue(i,l,1/k);
            else
                u.setValue(i,l,0);
        }
    while(error>accuracy)
    {
    Matrix X=q*u*q.transpose();
    Matrix M=q.transpose()*(X.inv())*q;
    Vector V=M.diag();
    double maximum=V.getValue(0),position=0,step,sum=0;
    for(unsigned int i=0;i<V.getN();i++)
    {
        if(V.getValue(i)>maximum)
        {
            position=i;
            maximum=V.getValue(i);
        }
    }
    step=(maximum-3)/(3*(maximum-1));
    Matrix new_u=((1-step)*u);
    new_u.setValue(position,position,new_u.getValue(position,position)+step);
    for(unsigned int i=0;i<n;i++)
    {
        sum+=(new_u.getValue(i,i)-u.getValue(i,i))*(new_u.getValue(i,i)-u.getValue(i,i));
    }
    error=sqrt(sum);
    for(unsigned int i=0;i<n;i++)
        u.setValue(i,i,new_u.getValue(i,i));
    }
    Vector U=Vector(n);
    for(unsigned int i=0;i<n;i++)
    {
        U.setValue(i,u.getValue(i,i));
    }
    Vector C=B*U;
    Matrix Ct=Matrix(1,2);
    Ct.setValue(0,0,C.getValue(0));
    Ct.setValue(0,1,C.getValue(1));
    Matrix A1=B*u*(B.transpose());
    Matrix A=(0.5)*((A1-C*Ct)).inv2();
    double *eq = new double[6];
    double a=A.getValue(0,0),b=2*A.getValue(0,1),c=A.getValue(1,1);
    double d=-2*(C.getValue(0))*a-(C.getValue(1))*b,
           e=-(C.getValue(0))*b-2*(C.getValue(1))*c,
           f=a*(C.getValue(0))*(C.getValue(0))+(C.getValue(1))*(C.getValue(0))*b+(C.getValue(1))*(C.getValue(1))*c-1;
    eq[0] = a;
    eq[1] = b;
    eq[2] = c;
    eq[3] = d;
    eq[4] = e;
    eq[5] = f;
    return eq;
}
