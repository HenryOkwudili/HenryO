#include <iostream>
#include <exception>
#include <vector>

using namespace std;
int main(){
	vector<int> myvector(10);
	try{
		
		myvector.at(20)=100; //Vector::at throws an out-of-range
		
	} catch (const out_of_range &err){
		cerr << "Out of range error" << err.what() << endl;
		cerr << "Type: "<< typeid(err).name() <<endl;
	}
	
	return 0;
}