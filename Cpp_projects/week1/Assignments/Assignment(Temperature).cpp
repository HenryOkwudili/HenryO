#include <iostream>

using namespace std;
int main()
{
	float F;
	float K;
	cout<<"This converts value of temperature in Kelvin to Farenheit"<<endl;
	cout<<"Intput value in Kelvin :"<<endl;
	cin>>K;
	float a = (K-273.15)*9;
	float b =a/5;
	float c =b+32;
	cout<<"Farenheit value is :"<<c<<endl;
	
	return 0;
}
