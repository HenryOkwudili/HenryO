#include <iostream>
using namespace std;

string concatenate (const string& a, const string& b) {
	return a+b;
}

int main () {
	
	string uni="";
	string a="Pan";
	string b="Atlantic";
	
	uni = concatenate(a,b);
	cout<<"The concatenated string is "<< uni<<endl;
}
