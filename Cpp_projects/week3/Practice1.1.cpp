#include <iostream>
#include <iterator>
using namespace std;

int main(){
	int a[] = {10, 20, 30, 40 };
	int a[] :: iterator i;
	
	//Printing elements of an array using foreach loop
	for (i = a.begin(); i != a.end(); i++){
		cout << *i << endl;
	}
	 
}
