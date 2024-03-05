#include <iostream>
#include <string>
using namespace std;

struct student{
	string matno;
	string name;
	int coursescore[2];
};

int main()
{
	student computer[5];
	
	for (int i=0; i<5; i++){
		cout<<"Enter the Matriculation number of student "<<i+1<<" : ";
		cin>>computer[i].matno;
		cout<<"Enter the name of student : "<<i+1<<" : ";
		cin>>computer[i].name;
		cout<<"Course score 1 (csc201): "<<i+1<<" : ";
		cin>>computer[i].coursescore[0];
		cout<<"Course score 2 (csc205): "<<i+1<<" : ";
		cin>>computer[i].coursescore[1];
	}
	
	for(int i=0; i<5; i++){
		cout<<"Matriculation number of student : "<< computer[i].matno<<endl;
		cout<<"Name of student : "<<i+1<<computer[i].name<<endl;
		cout<<"Course score 1 (csc201): "<<i+1<<computer [i].coursescore[0]<<endl;
		cout<<"Course score 2 (csc205): "<<i+1<<computer[i].coursescore[1]<<endl;
	}
}
