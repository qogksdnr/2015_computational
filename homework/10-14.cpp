#include <iostream>
#include <string.h>

using namespace std;

class cat{
	private:
		char name[100];
		char sex[100];
		char color[100];
	public:
		void inline printN(){cout << "This cat's name is " << name << endl; };
		void inline printS(){cout << "This cat's sex is " << sex << endl; };
		void inline printC(){cout << "This cat's color is " << color << endl; };
		void inline setN(char *in){strcpy(name,in);};
		void inline setS(char *in){strcpy(sex,in);};
		void inline setC(char *in){strcpy(color,in);};
		cat(char *, char *, char *);
};

cat::cat(char inn[], char ins[], char inc[])
{
	strcpy(name,inn);
	strcpy(sex,ins);
	strcpy(color,ins);
}

int main()
{
	cat* a = new cat("nyaa","female","white");
	a->printN();
	a->printS();
	a->printC();
	a->setN("nya");
	a->printN();
	delete a;
}
	
