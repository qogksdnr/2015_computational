#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void euler_meth(double, double, double, double, double **, double (*)(double, double));
void RK4_meth(double, double, double, double, double **, double (*) (double, double));

double target(double x, double y)
{
	return exp(x)+y;
}


int main()
{
	double *out1[2];
	double *out2[2];
	const double tix = 0, tiy = 0;
	const double dx = 0.01;
	const double xl = 1.;
	
	cout << "Target ODE: y' = y + e^x" << endl;
	cout << "Range: [" << tix << "," << tix+xl << "], initial cond.: (x0,y0) = (" << tix << "," << tiy << "), interval size:" << dx <<  endl;
	cout << "Solving target ODE using euler & RK4 meth." << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	euler_meth(tix,tiy,xl,dx,out1,target);
	RK4_meth(tix,tiy,xl,dx,out2,target);
	for(int i=0;i<=xl/dx;i++){
		cout << setiosflags(ios::fixed|ios::left) << "Eu_x" << setw(3) << i << ": " << setprecision(2) << out1[0][i] << "   ";
		cout << setiosflags(ios::fixed|ios::left) << "Eu_y" << setw(3) << i << ": " << setprecision(6) << out1[1][i] << "  |  ";
		cout << setiosflags(ios::fixed|ios::left) << "RK4_x" << setw(3) << i << ": " << setprecision(2) << out2[0][i] << "   " ;
		cout << setiosflags(ios::fixed|ios::left) << "RK4_y" << setw(3) << i << ": " << setprecision(6) << out2[1][i] << endl;
	}
}

void euler_meth(double ix, double iy, double xlength, double dx, double **out, double (*infunc)(double, double))
{
	int iter=(xlength/dx);
	out[0] = new double[iter+2];
	out[1] = new double[iter+2];
	out[0][0] = ix;
	out[1][0] = iy;
	for(int i = 1; i <= iter; i++){
		out[0][i] = out[0][i-1] + dx;
		out[1][i] = out[1][i-1] + dx*infunc(out[0][i-1],out[1][i-1]); 
	}
}

void RK4_meth(double ix, double iy, double xlength, double dx, double **out, double (*infunc) (double, double))
{
	int iter = (xlength/dx);
	double k1, k2 ,k3 ,k4;
	out[0] = new double[iter+2];
	out[1] = new double[iter+2];
	out[0][0] = ix;
	out[1][0] = iy;
	for(int i = 1; i <= iter; i++){
		k1 = infunc(out[0][i-1],out[1][i-1]);
		k2 = infunc(out[0][i-1]+0.5*dx,out[1][i-1]+0.5*dx*k1);
		k3 = infunc(out[0][i-1]+0.5*dx,out[1][i-1]+0.5*dx*k2);
		k4 = infunc(out[0][i-1]+dx,out[1][i-1]+dx*k3);
		out[0][i] = out[0][i-1] + dx;
		out[1][i] = out[1][i-1] + (dx/6.)*(k1+(2.*k2)+(2.*k3)+k4);
	}
}
