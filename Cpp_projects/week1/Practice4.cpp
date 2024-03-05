#include <iostream>
using namespace std;
int main()
{
	int num = 150;
	int hr = 0;
	int min = 0;
	
	while (num >=60){
		hr+=1;
		num-=60;
	}
	
	min = num;
	cout<<"Number is :"<<num<<endl;
	cout<<"Hour is :"<<hr<<endl;
	cout<<"Minute is :"<<min<<endl;
	cout<<"Time is :"<<hr<<"Hours :"<<min<<"Minutes";
}
