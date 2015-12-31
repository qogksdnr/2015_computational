#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define SEEK_INTERVAL_FACTOR 10000

using namespace std;

double MC_integral(double, double, int, double(*)(double));
double target_func(double x)
{
	return 0.2+25.*x-200.*x*x+675.*x*x*x-900.*x*x*x*x+400.*x*x*x*x*x;
}

int main()
{
	double a, b;
	double pnum;
	a = 0;
	b = 0.8;
	pnum = 1000000;
	cout << "Integrate a function using Monte-Carlo Method" << endl;
	cout << "Interval: [" << a << "," << b << "], Number of points: " << pnum << endl;
	cout << "Result: " << MC_integral(a,b,pnum,target_func) << endl;
}


double MC_integral(double a, double b, int num, double (*infunc)(double))
{
	double total_size, frac_p, frac_m, rtx, rty;
	int dot_p = 0,dot_m = 0;
	double max,min,c=1.;
	if(a>b){
		max = a;
		a = b;
		b = max;
		c = -1.;
	}
	const double intv = (b-a)/SEEK_INTERVAL_FACTOR;
	max = infunc(a);
	min = infunc(a);
	for(double i = a; i <= (b + intv); i += intv){
		if(max < infunc(i)) max = infunc(i);
		else if (min > infunc(i)) min = infunc(i);
	}
	if(max>0 && min<0);
	else if(max<0) max = 0;
	else if(min>0) min = 0;
	else return 0;
	total_size = (b-a)*(max-min);
	srand(time(NULL));
	for(int i = 0; i <= num; i++){
//		if((i+1)%20000 == 0) srand(time(NULL)+i);
		rtx = ((double)rand()/RAND_MAX)*(b-a)+a;
		rty = ((double)rand()/RAND_MAX)*(max-min)+min;
		if(rty<0){
			if(infunc(rtx) < rty) dot_m++;
		}
		else if(rty>0){
			if(infunc(rtx) > rty) dot_p++;
		}
	}
	frac_p = (double)dot_p/(double)num;
	frac_m = (double)dot_m/(double)num;

	return c * total_size*(frac_p-frac_m);
}
