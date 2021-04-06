#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "Solver.hpp"
using namespace std;
int main()
{
    double error=1,accuracy=0.0001;
    unsigned int n;
    cout<<"Amount of points,two at least (generates randomly in the range of 1 to 100):"<<endl;
    cin>>n;
    double *x = new double [n];
    double *y = new double [n];
    srand(time(NULL));
    for(unsigned int i=0;i<n;i++)
    {
        x[i]=rand()%100-50;
        y[i]=rand()%100-50;
    }
    double *ans = solver(n, x, y, error, accuracy);
    ofstream out;
	out.open("data.txt");
	if (out.is_open())
	{
		out << ans[0] <<' '<< ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << ' ' << ans[5] << endl;
		for(unsigned int i=0;i<n;i++)
        {
            out << x[i] << ' ' << y[i] << endl;
        }
	}
	double C = (ans[0] + ans[2] + ((ans[0] + ans[2])*(ans[0] + ans[2]) - 4 * (ans[0] * ans[2] - ans[1] * ans[1])))/2;
	double A = C - (ans[0] + ans[2]);
	double S = 3.14 * 1/sqrt(fabs(A)) * 1/sqrt(fabs(C));
    cout<<"The equation is:"<<endl<<'('<<ans[0]<<')'<<"x^2+("<<ans[1]<<")xy+("<<ans[2]<<")y^2+("<<ans[3]<<")x+("<<ans[4]<<")y+("<<ans[5]<<")=0"<<endl;
    cout<<"S = "<<S<<endl;
}
