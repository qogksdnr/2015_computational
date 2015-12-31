#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void euler_meth(double, double, double, double, double **, double (*)(double, double), double (*) (double, double));

double target1(double x, double y)
{
	return y;
}

double target2(double x, double y)
{
	double k = 1;
	double mu = 0.6;
	double m = 0.5;
	//return exp(x)+y;
	return -(k*x+mu*y)/m;
}


int main()
{
	double *out1[2];
	const double tix = 1, tiy = 0;
	const double dx = 0.01;
	const double xl = 10;
	
	cout << "Target ODE: y' = y + e^x" << endl;
	cout << "initial cond.: (x0,y0) = (" << tix << "," << tiy << "), interval size:" << dx <<  endl;
	cout << "Solving target ODE using euler & RK4 meth." << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	euler_meth(tix,tiy,xl,dx,out1,target1,target2);
	for(int i=0;i<=xl/dx;i++){
		cout << setiosflags(ios::fixed|ios::left) << "Eu_x" << setw(log10(10/0.01)+1) << i << ": " << setprecision(6) << out1[0][i] << "   ";
		cout << setiosflags(ios::fixed|ios::left) << "Eu_y" << setw(log10(10/0.01)+1) << i << ": " << setprecision(6) << out1[1][i] << endl;
	}
}

void euler_meth(double ix, double iy, double count, double dx, double **out, double (*infunc1)(double, double), double (*infunc2)(double, double))
{
	int iter=(count/dx);
	out[0] = new double[iter+2];
	out[1] = new double[iter+2];
	out[0][0] = ix;
	out[1][0] = iy;
	for(int i = 1; i <= iter; i++){
		//out[0][i] = out[0][i-1] + dx;
		//out[1][i] = out[1][i-1] + dx*infunc(out[0][i-1],out[1][i-1]); 
		out[0][i] = out[0][i-1] + dx * infunc1(out[0][i-1],out[1][i-1]);
		out[1][i] = out[1][i-1] + dx * infunc2(out[0][i-1],out[1][i-1]);
	}
}
