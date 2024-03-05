#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	vector<int> :: iterator i;
	
	for(i = v.begin(); i != v.end(); i++){
		*i = *i * 5;
	}
	
	cout<<"Output of begin and end: ";
	for(i = v.begin(); i != v.end(); i++)
		cout<<*i<<" ";  
	
}
