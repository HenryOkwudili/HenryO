#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main()
{
	//Two dimensional key
	
	map<int, map<int, int> > m;
	//For accessing outer map
	map<int, map<int, int> >::iterator itr;
	//For accessing inner map
	map<int, int>::iterator ptr;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				m[i][j] = i+j; 
			}
		} 
		
		for(int i = 0; i<2; i++){
			for(int j= 0; j<2; j++){
				
				//Accessing through array subscript
				cout<<"First key is "<<i
					<<"And second key is "<< j
					<<"And value is "<<m[i][j]<<endl;
			}
		}
		cout<<"\nNow accessing map though iterator \n\n";
		
	for (itr = m.begin(); itr != m.end(); itr++){
		
		for(ptr = itr->second.begin();ptr != itr->second.end();ptr++){
			cout<<"First key is "<<itr->first
				<<"And second key is "<<ptr->first
				<<"And value is "<<ptr->second<<endl;
		}
	}
}
