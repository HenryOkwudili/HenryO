#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float v;
	float pi = 3.142;
	float r;
	cout<<"Please enter value of radius :";
	cin>>r;
	v = (4/3)*pi*pow(r,2);
	cout<<"Volume of sphere is :"<<v;
	
	return 0;
}
