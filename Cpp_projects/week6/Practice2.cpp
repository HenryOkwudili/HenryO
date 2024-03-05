#include <iostream>
using namespace std;



	


int main()
{
	
	using C = char;
using NUMBERS = int;
using fields = char [50];
    C x='a';
	NUMBERS y = 10;
	NUMBERS z = 5;
	fields characters = "Hello world";
	
	NUMBERS c=y+z;
	
	cout<<"NUMBERS c=y+z So c= "<<c<<endl;
	cout<<"field characters = "<<characters<<endl;
	cout<<" C x='a', So x="<<x<<endl;
	return 0;
}
