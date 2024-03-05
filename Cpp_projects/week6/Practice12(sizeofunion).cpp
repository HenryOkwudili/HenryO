#include <iostream>
using namespace std;
union unionJob{
	//defining a union
	char name[32];
	float salary;
	int workerNo;
}uJob;

struct structJob{
	char name[32];
	float salary;
	int workerNo;
}sJob;

int main()
{
	cout<<"size of union in bytes"<<sizeof(uJob)<<endl;
	cout<<"size of structure in bytes"<<sizeof(sJob)<<endl;
	
	return 0;
}
