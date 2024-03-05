#include <iostream>
using namespace std;
int main()
{
	cout<<"Input numbers to find the largest number"<<endl;
	cout<<"Input first number: "<<endl;
	int a;
	cin>>a;
	cout<<"Input second number"<<endl;
	int b;
	cin>>b;
	cout<<"Input third number"<<endl;
	int c;
	cin>>c;
	
	if(a>b && a>c)
		cout<<"This is the largest number: "<<a<<endl;
	else if(b>a && b>c)
		cout<<"This is the largest number: "<<b<<endl;
	else if(c>a && c>b)
		cout<<"This is the largest number: "<<c<<endl;
		
	return 0;
}
