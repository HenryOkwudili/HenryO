#include <iostream>
using namespace std;

int main()
{
	int x;
	int y = 10;
	int z = 5;
	
	x = (y < z) ? y-z : z-y;
	cout<<"(y < z) ? y-z :"<<x<<endl;
	
	return 0;
}
