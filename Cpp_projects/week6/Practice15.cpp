#include <iostream>

using namespace std;

struct book2_t {
	char title[50]="C++ programming";
	char author[50]="Bjane Stroustrup";
	union{
		int dollars;
		int yen;
	}price;
}book2;

int main()
{
	cout<<"Book Title"<<book2.title<<endl;
	cout<<"Book Author"<<book2.author<<endl;
	cout<<"Price in dollars"<<book2.price.dollars<<endl;
	cout<<"Price in Yen"<<book2.price.yen<<endl;
	
	return 0;
}
