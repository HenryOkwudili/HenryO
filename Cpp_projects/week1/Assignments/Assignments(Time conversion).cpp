#include <iostream>
using namespace std;
int main()
{
	cout<<"This converts a number into hours and minutes"<<endl;
	int a;
	cout<<"Enter an amount of time in seconds :"<<endl;
	cin>>a;
	int hr = a/60;
	int min = a % 60;
	
	cout<<"The time in hours and minutes is :"<<hr<<"hours"<<":"<<min<<"minutes"<<endl;

	return 0;
	
	
}
