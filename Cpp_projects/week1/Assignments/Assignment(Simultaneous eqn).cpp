#include <iostream>
using namespace std;
int main()
{
	cout<<"This solves simultaneous equations in the form of :"<<endl;
	cout<<"ax+by = e"<<endl;
	cout<<"cx+dy = f"<<endl;
	
	float a;
	cout<<"Enter value of a :"<<endl;
	cin>>a;
	float b;
	cout<<"Enter value of b :"<<endl;
	cin>>b;
	float e;
	cout<<"Enter value of e :"<<endl;
	cin>>e;
	float c;
	cout<<"Enter value of c :"<<endl;
	cin>>c;
	float d;
	cout<<"Enter value of d :"<<endl;
	cin>>d;
	float f;
	cout<<"Enter value of f :"<<endl;
	cin>>f;
	
	float det = (a*d)-(b*c);
	cout<<"Determinant is :"<<det<<endl;
	
	float detx = (e*d)-(b*f);
	float dety = (a*f)-(e*c);
	float x = detx/det;
	cout<<"Your value of X is :"<<x<<endl;
	float y = dety/det;
	cout<<"Your value of y is :"<<y<<endl;
	
	return 0;
}
