#include <iostream>
#include <thread>

using namespace std;
void printx(int num)
{
	for (int i=0; i<=num; i++){
		cout<<"x";
	}
}

int main(){
	int num;
	cout<<"Enter Value of X :";
	cin>>num;
	thread t1(printx, num);
	
	t1.join();
	
	return 0;
}