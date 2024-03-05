#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float pi = 3.142;
	float h;
	cout<<"Please enter height value :";
	cin>>h;
	float c;
	cout<<"Please enter radius value :";
	cin>>c;
	float r = pow(c,2);
	int v;
	v = pi*h*r;
	cout<<"Volume of cylinder is :"<<v<<endl;
	
	return 0;
}
