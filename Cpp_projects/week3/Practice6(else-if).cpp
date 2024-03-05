#include <iostream>
using namespace std;
int score=40;

int main()
{
	if(score>=70){
	
		cout<<"Grade A"<<endl;
		cout<<"Excellent"<<endl;
	}
	else if(score>=60){
	
		cout<<"Grade B"<<endl;
		cout<<"Very good"<<endl;
	}
	else if (score>=50){
	
		cout<<"Grade C"<<endl;
		cout<<"Good"<<endl;
	}
	else if(score>=40){
	
		cout<<"Grade D"<<endl;
		cout<<"Fair"<<endl;
	}
	else{
	
		cout<<"Grade F"<<endl;
		cout<<"Poor"<<endl;
	}
	return 0;
}
