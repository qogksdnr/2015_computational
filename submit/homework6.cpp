#include <iostream>
#include <cmath>

using namespace std;

double rectmeth(double, double, int, int, double(*)(double));
double trapmeth(double, double, int, double(*)(double));

double targetfunc(double x)
{
	return 0.2+25.*x-200.*x*x+675.*x*x*x-900.*x*x*x*x+400.*x*x*x*x*x;
}

int main()
{
	cout << "Range: 0~5, dx: 0.01" << endl;
	cout << "Integrated Result(Rectangular Meth.): " << rectmeth(0,0.8,2,1,targetfunc) << endl;
	cout << "Integrated Result(Trapezoid Meth.): " << trapmeth(0,0.8,2,targetfunc) << endl;
}

double rectmeth(double a, double b, int dn, int over, double (*infunc)(double))
{
	double result = 0;
	double t,dx;
	int i;
	if(a==b) return 0;
	if(dn==0) dn++;
	dx = (b-a)/dn;
	
	if(over){
		for(i = 0;i<dn;i++){
			result += dx*infunc(a);
			a += dx;
		}
	}
	else{
		for(i = 0;i<dn;i++){
			a += dx;
			result += dx*infunc(a);
		}
	}
	return result;
}


double trapmeth(double a, double b, int dn, double (*infunc)(double))
{
	double result = 0;
	double t,dx;
	int i;
	if(a==b) return 0;
	if(dn==0) dn++;

	dx = (b-a)/dn;

	for(i = 0;i<dn;i++) result += 0.5*dx*(infunc(a)+infunc(a+=dx));

	return result;
}
