//writing to a text file
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream myfile("example.txt",ios::app);
	if(myfile.is_open())
	{
		myfile<<"This is a new line.\n";
		myfile<<"Append.\n";
		myfile.close();
	}
	else cout<<"Unable to open file";
	return 0;
	
}
