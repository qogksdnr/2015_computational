#include <iostream>
#include <string.h>

using namespace std;

class name{
private:
	int abcd;
	char namea[100];
public:
	void printbcd();
	void initabcd();
	name();
	name(int);
	name(char *);
	name(int, char*);
	~name();
};
void name::initabcd()
{
	abcd = 10;	
}

void name::printbcd()
{
	cout << abcd << endl;
}

name::name()
{
	abcd = 0;
	cout << "CONSTRUCT A" << endl;
}

name::name(int a)
{
	abcd = a;
	cout << "CONSTRUCT B" << endl;
}
name::~name()
{
	cout << "DESTROY" << endl;
}

int main()
{
	name * abc;
	name * def;

	abc = new name;
	def = new name(2);
	
	(*abc).printbcd();
	(*def).printbcd();

	delete abc;
	delete def;
}
