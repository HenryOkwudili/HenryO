#include <iostream>
#include <thread>
using namespace std;

void printx()
{
	for(int i=0; i<=500; i++){
		//sleep(0.001);
		cout<<"x";
	}
}

void printy(){
	for(int i=0; i<=50; i++){
		cout<<"y";
	}
}

int main(){
	thread t1(printx);
	thread t2(printy);
	t1.join();
	t2.join();
	
	return 0;
}