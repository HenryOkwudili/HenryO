#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	int b = 6;
	
	cout<<"a ="<<a<<", b ="<<b<<endl;
	if(a<6&&b>5)
	{
		cout<<" (a < 6) && (b > 5) is TRUE"<<endl;
	}
	else
	{
		cout<<"(a < 6) && (b > 5) is FALSE"<<endl;
	}
	
	if(a < 6 || b > 5)
	{
		cout<<" (a < 6) || (b > 5) is TRUE"<<endl;
	}
	else
	{
		cout<<"(a < 6) || (b > 5) is FALSE"<<endl;
	}
	
	if (!(a < 6))
	{
		cout<<" !(a < 6) is TRUE"<<endl;
	}
	else
	{
		cout<<"!(a < 6) is FALSE"<<endl;
	}
	return 0;
	
	
}
