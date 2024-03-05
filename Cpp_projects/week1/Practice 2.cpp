#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	int c;
	c = a++;
	cout <<"c = a++ :"<< c << endl;
	
	a =5;
	c = ++a;
	cout <<"c = ++a :"<< c << endl;
	
	a = 5;
	c = a--;
	cout<<"c = a-- :"<< c << endl;
	
	a = 5;
	c = --a;
	cout<<"c = --a :"<< c << endl;
	
	return 0;
	
}
