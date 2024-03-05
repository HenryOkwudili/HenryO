#include <iostream>
#include <new>
using namespace std;
//int *array;
int i, size, *array;
int main()
{
	cout<<"Enter the size of the array"<<endl;
	cin>>size;
	array = new int [size];//Declaring the array
	
	for (i=0; i<size; i++){
		array[i]=i*i;
		cout<<"array["<<i<<"] ="<<array[i]<<endl;
	}
	
/*	for (int j=0; j<size; j++){
		cout<<"array["<<j<<"] ="<<array[j]<<endl;
	} */
	return 0;
}
