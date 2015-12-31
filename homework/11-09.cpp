#include <iostream>
#include <cmath>

using namespace std;

double nrmeth(double,double,const double,const double,const double,double (*)(double));
double bisect(double,double,const double,const double,const double,double (*)(double));
double falsepos(double,double,const double,const double,const double,double (*)(double));

double test(double x)
{
	return exp(-x)-sin(M_PI*x/2);   // Target Function
}

int isfail=0;

int main()
{
	double (*func)(double);
	cout <<"Approx x(using Bisection method): " << bisect(0,5,0.01,0.01,1000,*test) << endl;
	if(isfail) cout << "FAILED" << endl;
	isfail = 0;
	cout <<"Approx x(using False position method): " << falsepos(0,5,0.01,0.01,1000,*test) << endl;
	if(isfail) cout << "FAILED" << endl;
}

double bisect(double a,double b,const double e1,const double e2,const double MAX, double (*infunc)(double))
{
	int i;
	double len, c;
	if(a >= b || e2 < 0 || e1 < 0){
		a = c;				// if a and b is out of range, swap two variables.
		b = a;
		b = c;
	}
	else if(infunc(a) == 0) return a;
	else if(infunc(b) == 0) return b;
	else if(infunc(a+b)/2. == 0) return (a+b)/2.;
	else if(infunc(a)*infunc(b) > 0){
		isfail = -1;
		return 0;
	}
	for(i = 0;i<MAX;i++){
		c = (a+b)/2.;
		if(infunc(a)*infunc(c) < 0) b = c;
		else if(infunc(c)*infunc(b) < 0) a = c;
		c = (a+b)/2.;
		len = b-a;
		if(len < e2 || abs(infunc(c)) < e1) break;
		
	}
	return (a+b)/2.;
}


double falsepos(double a,double b,const double e1,const double e2,const double MAX, double (*infunc)(double))
{
	int i;
	double len,c;

	if(a >= b || e2 < 0 || e1 < 0){
		a = c;				// if a and b is out of range, swap two variables.
		b = a;
		b = c;
	}
	else if(infunc(a) == 0) return a;
	else if(infunc(b) == 0) return b;
	else if(infunc(a+b)/2. == 0) return (a+b)/2.;
	else if(infunc(a)*infunc(b) > 0){
		isfail = -1;
		return 0;
	}
	for(i=0;i<MAX;i++){
		c = a - ((b-a)/(infunc(b)-infunc(a)))*infunc(a);
		if(infunc(a)*infunc(c) < 0) b = c;
		else a = c;
		len = b-a;
		if(len < e2 || abs(infunc(c)) < e1) break;
	}	
	return c;
}

double nrmeth(double a,double b,const double e1,const double e2,const double MAX, double (*infunc)(double))
{
}
