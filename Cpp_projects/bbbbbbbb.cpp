#include <iostream>
using namespace std;

int main(){
try{
	try{
		throw 20;
	}catch(int n){
		cout<<"Inner Catch\n";
		throw;
	}
}catch(int x){
	cout<<"Outer Catch\n";
}
return 0;
}
