#include <iostream>
using namespace std;

int main()
{
	int a = 13;
	int b = 2;
	int c;
	
	cout << "a :" << a << endl;
	cout << "b :" << b << endl;
	c = a + b;
	cout << "a + b :" << c << endl;
	
	c = a - b;
	cout << "a - b :" << c << endl;
	c = a * b;
	cout << "a * b :" << c << endl;
	
	c = a / b;
	cout << "a / b :" << c << endl;
	
	c = a % b;
	cout << "a % b :" << c << endl;
	
	return 0;
}
